/* ============================================================
   90 Days of DP — shared stepper
   Every visualization is a sequence of states you walk through.
   This owns the walking: transport, keyboard, scrub, play, and the
   three panels every page shares (narration, code, call stack).
   The page owns only its own drawing.
   ============================================================ */

(function (global) {
  "use strict";

  var SVG_NS = "http://www.w3.org/2000/svg";

  function svgIcon(paths, opts) {
    var s = document.createElementNS(SVG_NS, "svg");
    s.setAttribute("viewBox", "0 0 16 16");
    s.setAttribute("aria-hidden", "true");
    s.setAttribute("fill", "none");
    s.setAttribute("stroke", "currentColor");
    s.setAttribute("stroke-width", (opts && opts.w) || "2.25");
    s.setAttribute("stroke-linecap", "square");
    s.setAttribute("stroke-linejoin", "miter");
    paths.forEach(function (d) {
      var p = document.createElementNS(SVG_NS, "path");
      p.setAttribute("d", d);
      s.appendChild(p);
    });
    return s;
  }

  var ICONS = {
    prev: function () { return svgIcon(["M10 3 L5 8 L10 13"]); },
    next: function () { return svgIcon(["M6 3 L11 8 L6 13"]); },
    play: function () {
      var s = svgIcon(["M4.5 3 L12.5 8 L4.5 13 Z"]);
      s.setAttribute("fill", "currentColor");
      s.setAttribute("stroke-width", "1");
      return s;
    },
    pause: function () { return svgIcon(["M5.5 3 L5.5 13", "M10.5 3 L10.5 13"], { w: "2.75" }); },
    reset: function () { return svgIcon(["M13 8 A5 5 0 1 1 8 3", "M8 0.5 L8 5.5 L4 5.5"], { w: "2" }); }
  };

  function el(tag, cls, text) {
    var n = document.createElement(tag);
    if (cls) n.className = cls;
    if (text != null) n.textContent = text;
    return n;
  }

  function button(cls, iconName, label, textFirst) {
    var b = el("button", cls);
    b.type = "button";
    var t = el("span", null, label);
    if (textFirst) { b.appendChild(t); b.appendChild(ICONS[iconName]()); }
    else { b.appendChild(ICONS[iconName]()); b.appendChild(t); }
    return b;
  }

  /* ---------- panels every page shares ---------- */

  function renderCode(host, lines, activeLine) {
    if (!host) return;
    if (!host.__built) {
      host.textContent = "";
      lines.forEach(function (src, i) {
        var row = el("div", "code__row");
        row.dataset.line = String(i + 1);
        row.appendChild(el("span", "code__n", String(i + 1)));
        row.appendChild(el("span", "code__s", src === "" ? " " : src));
        host.appendChild(row);
      });
      host.__built = true;
    }
    var rows = host.children;
    for (var i = 0; i < rows.length; i++) {
      rows[i].classList.toggle("is-on", activeLine != null && Number(rows[i].dataset.line) === activeLine);
    }
  }

  function renderFrames(host, frames, labeller) {
    if (!host) return;
    host.textContent = "";
    if (!frames || !frames.length) {
      host.appendChild(el("li", "is-empty", "empty"));
      return;
    }
    for (var i = frames.length - 1; i >= 0; i--) {
      var f = frames[i];
      var li = el("li", i === frames.length - 1 ? "is-top" : null);
      var parts = labeller(f, i, i === frames.length - 1);
      li.appendChild(el("span", null, parts.main));
      if (parts.aside != null) li.appendChild(el("span", "k", parts.aside));
      host.appendChild(li);
    }
  }

  /* ---------- the controller ---------- */

  function stepper(opts) {
    var steps = opts.steps;
    var at = 0;
    var timer = null;
    var reduced = global.matchMedia && global.matchMedia("(prefers-reduced-motion: reduce)").matches;

    var host = opts.transport;
    var bPrev = button("btn", "prev", "Prev");
    var bNext = button("btn btn--go", "next", "Next", true);
    var bPlay = button("btn", "play", "Play");
    var bReset = button("btn", "reset", "Reset");
    var scrub = el("input", "scrub");
    scrub.type = "range";
    scrub.min = "0";
    scrub.step = "1";
    scrub.max = String(steps.length - 1);
    scrub.value = "0";
    scrub.id = (opts.id || "stepper") + "-scrub";
    scrub.setAttribute("aria-label", "Step");
    var count = el("span", "count");

    host.appendChild(bPrev);
    host.appendChild(bNext);
    host.appendChild(scrub);
    host.appendChild(bPlay);
    host.appendChild(bReset);
    host.appendChild(count);

    var live = opts.say;
    if (live) { live.setAttribute("aria-live", "polite"); live.setAttribute("aria-atomic", "true"); }

    function stop() {
      if (timer) { clearInterval(timer); timer = null; }
      bPlay.lastChild.textContent = "Play";
      bPlay.replaceChild(ICONS.play(), bPlay.firstChild);
    }

    function render() {
      var st = steps[at];
      if (opts.render) opts.render(st, at);
      if (opts.say) opts.say.innerHTML = st.note || "";
      renderCode(opts.code, opts.codeLines || [], st.line);
      if (opts.frames) renderFrames(opts.frames, st.frames, opts.frameLabel || function (f) { return { main: String(f) }; });
      count.textContent = at + " / " + (steps.length - 1);
      scrub.value = String(at);
      bPrev.disabled = at === 0;
      bNext.disabled = at === steps.length - 1;
      if (at === steps.length - 1) stop();
    }

    function go(i) {
      at = Math.max(0, Math.min(steps.length - 1, i));
      render();
    }

    function rebuild(nextSteps, keep) {
      steps = nextSteps;
      scrub.max = String(steps.length - 1);
      at = keep ? Math.min(at, steps.length - 1) : 0;
      if (opts.code) opts.code.__built = false;
      render();
    }

    bPrev.addEventListener("click", function () { stop(); go(at - 1); });
    bNext.addEventListener("click", function () { stop(); go(at + 1); });
    bReset.addEventListener("click", function () { stop(); go(0); });
    scrub.addEventListener("input", function () { stop(); go(Number(scrub.value)); });
    bPlay.addEventListener("click", function () {
      if (timer) { stop(); return; }
      if (at === steps.length - 1) go(0);
      bPlay.lastChild.textContent = "Pause";
      bPlay.replaceChild(ICONS.pause(), bPlay.firstChild);
      timer = setInterval(function () {
        if (at >= steps.length - 1) { stop(); return; }
        go(at + 1);
      }, reduced ? 1800 : (opts.playMs || 1100));
    });

    document.addEventListener("keydown", function (e) {
      if (e.target && /^(INPUT|SELECT|TEXTAREA)$/.test(e.target.tagName) && e.target !== scrub) return;
      if (e.key === "ArrowRight") { stop(); go(at + 1); }
      else if (e.key === "ArrowLeft") { stop(); go(at - 1); }
    });

    render();

    return {
      go: go,
      stop: stop,
      rebuild: rebuild,
      opts: opts,
      at: function () { return at; },
      reduced: reduced
    };
  }

  global.Schematic = {
    icons: ICONS,
    el: el,
    stepper: stepper,
    renderCode: renderCode,
    renderFrames: renderFrames,
    svgNS: SVG_NS
  };
})(window);
