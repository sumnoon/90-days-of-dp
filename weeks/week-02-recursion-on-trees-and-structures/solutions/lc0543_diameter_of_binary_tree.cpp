#include <algorithm>
#include <iostream>
#include <random>
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
    int diameter = 0;
    int func(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = func(root->left);
        int rHeight = func(root->right);

        diameter = max(diameter, lHeight + rHeight);

        return max(lHeight, rHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        func(root);
        return diameter;
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

// Reference: the longest path through each node, from separately computed heights. O(n^2).
int height(TreeNode* r) { return r ? 1 + max(height(r->left), height(r->right)) : 0; }
int slow_diameter(TreeNode* r) {
    if (!r) return 0;
    return max({height(r->left) + height(r->right), slow_diameter(r->left), slow_diameter(r->right)});
}

int main() {
    struct Case { vector<optional<int>> tree; int want; };
    Case cases[] = {
        {{1, 2, 3, 4, 5}, 3},                              // LeetCode example 1: 4-2-1-3
        {{1, 2}, 1},                                       // LeetCode example 2
        {{1}, 0},                                          // one node: no edges
        {{1, 2, null, 3, null, 4}, 3},                     // a chain of 4 nodes, 3 edges
        // the longest path skips the root: 7-5-3-2-4-6-8, all under 2
        {{1, 2, null, 3, 4, 5, null, null, 6, 7, null, null, 8}, 6},
    };
    int failed = 0;
    Solution s;   // reused on purpose: diameter must be reset on every call
    for (auto& [tree, want] : cases) {
        TreeNode* root = build(tree);
        int got = s.diameterOfBinaryTree(root);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "diameter " << got << endl;
        free_tree(root);
    }

    mt19937 rng(98);
    int mismatches = 0;
    for (int t = 0; t < 500; ++t) {
        TreeNode* root = random_tree(1 + rng() % 40, rng);
        if (s.diameterOfBinaryTree(root) != slow_diameter(root)) ++mismatches;
        free_tree(root);
    }
    if (mismatches) ++failed;
    cout << (mismatches ? "FAIL " : "ok   ") << "500 random trees match the O(n^2) reference" << endl;

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
