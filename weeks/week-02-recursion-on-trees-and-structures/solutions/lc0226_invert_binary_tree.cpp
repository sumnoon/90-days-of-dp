#include <iostream>
#include <optional>
#include <queue>
#include <string>
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *l = root->left;
        TreeNode *r = root->right;

        root->left = invertTree(r);
        root->right = invertTree(l);

        return root;
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

// Level order with trailing nulls trimmed, as LeetCode prints it.
vector<optional<int>> serialize(TreeNode* root) {
    vector<optional<int>> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        if (!n) { out.push_back(null); continue; }
        out.push_back(n->val);
        q.push(n->left);
        q.push(n->right);
    }
    while (!out.empty() && !out.back()) out.pop_back();
    return out;
}

void print(const vector<optional<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) cout << (i ? "," : "") << (v[i] ? to_string(*v[i]) : "null");
    cout << "]";
}

int main() {
    struct Case { vector<optional<int>> tree, want; };
    Case cases[] = {
        {{4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1}},   // LeetCode example 1
        {{2, 1, 3}, {2, 3, 1}},                           // LeetCode example 2
        {{}, {}},                                         // empty tree
        {{1}, {1}},                                       // one node
        {{1, 2}, {1, null, 2}},                           // left child becomes right
        {{1, 2, null, 3, null, 4}, {1, null, 2, null, 3, null, 4}},   // left chain becomes right chain
    };
    int failed = 0;
    for (auto& [tree, want] : cases) {
        TreeNode* root = Solution().invertTree(build(tree));
        vector<optional<int>> got = serialize(root);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ");
        print(got);
        cout << endl;
        free_tree(root);
    }

    // Inverting twice gives the original tree back.
    vector<optional<int>> big = {1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9};
    TreeNode* root = build(big);
    root = Solution().invertTree(Solution().invertTree(root));
    bool ok = serialize(root) == big;
    if (!ok) ++failed;
    cout << (ok ? "ok   " : "FAIL ") << "invert twice = original" << endl;
    free_tree(root);

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
