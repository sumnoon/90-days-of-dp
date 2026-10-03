#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <optional>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (l != nullptr && r != nullptr) {
            return root;
        }

        return (l != nullptr) ? l : r;
    }
};

// --- local harness (LeetCode supplies these) ---

constexpr nullopt_t null = nullopt;

// Builds a tree from LeetCode's level-order form: {1, null, 2, 3}.
TreeNode* build(const vector<optional<int>>& vals) {
    if (vals.empty() || !vals[0]) return nullptr;
    TreeNode* root = new TreeNode(*vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < vals.size() && vals[i]) q.push(node->left = new TreeNode(*vals[i]));
        ++i;
        if (i < vals.size() && vals[i]) q.push(node->right = new TreeNode(*vals[i]));
        ++i;
    }
    return root;
}

void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

// A random tree of n nodes with values 0..n-1: each new node hangs off a
// random free child slot, so shapes range from chains to bushy trees.
TreeNode* random_tree(int n, mt19937& rng) {
    if (n == 0) return nullptr;
    vector<TreeNode*> nodes = {new TreeNode(0)};
    for (int v = 1; v < n; ++v) {
        while (true) {
            TreeNode* p = nodes[rng() % nodes.size()];
            TreeNode*& slot = (rng() & 1) ? p->left : p->right;
            if (!slot) { slot = new TreeNode(v); nodes.push_back(slot); break; }
        }
    }
    return nodes[0];
}

TreeNode* find(TreeNode* r, int v) {
    if (!r || r->val == v) return r;
    TreeNode* f = find(r->left, v);
    return f ? f : find(r->right, v);
}

// Reference: the root-to-node paths of p and q; the LCA is where they last agree.
bool path_to(TreeNode* r, TreeNode* x, vector<TreeNode*>& path) {
    if (!r) return false;
    path.push_back(r);
    if (r == x || path_to(r->left, x, path) || path_to(r->right, x, path)) return true;
    path.pop_back();
    return false;
}
TreeNode* slow_lca(TreeNode* r, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> a, b;
    path_to(r, p, a);
    path_to(r, q, b);
    TreeNode* last = nullptr;
    for (size_t i = 0; i < min(a.size(), b.size()) && a[i] == b[i]; ++i) last = a[i];
    return last;
}

int main() {
    vector<optional<int>> ex = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    struct Case { vector<optional<int>> tree; int p, q, want; };
    Case cases[] = {
        {ex, 5, 1, 3},          // LeetCode example 1: on opposite sides of the root
        {ex, 5, 4, 5},          // LeetCode example 2: a node is its own ancestor
        {{1, 2}, 1, 2, 1},      // LeetCode example 3
        {ex, 7, 4, 2},          // both deep, under 2
        {ex, 6, 4, 5},
        {ex, 7, 8, 3},
        {ex, 0, 8, 1},
    };
    int failed = 0;
    for (auto& [tree, pv, qv, want] : cases) {
        TreeNode* root = build(tree);
        TreeNode* got = Solution().lowestCommonAncestor(root, find(root, pv), find(root, qv));
        bool ok = got && got->val == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "lca(" << pv << ", " << qv << ") = " << (got ? to_string(got->val) : "null") << endl;
        free_tree(root);
    }

    mt19937 rng(236);
    int mismatches = 0, pairs = 0;
    for (int t = 0; t < 500; ++t) {
        int n = 2 + rng() % 40;
        TreeNode* root = random_tree(n, rng);
        for (int k = 0; k < 5; ++k) {
            int a = rng() % n, b = rng() % n;
            if (a == b) continue;
            TreeNode *p = find(root, a), *q = find(root, b);
            ++pairs;
            if (Solution().lowestCommonAncestor(root, p, q) != slow_lca(root, p, q)) ++mismatches;
        }
        free_tree(root);
    }
    if (mismatches) ++failed;
    cout << (mismatches ? "FAIL " : "ok   ") << pairs << " random (p, q) pairs match the path-comparison reference" << endl;

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
