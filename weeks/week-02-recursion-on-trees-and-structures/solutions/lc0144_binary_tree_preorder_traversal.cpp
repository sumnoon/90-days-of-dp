#include <iostream>
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
    void helper(TreeNode* root, vector<int> &ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
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

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) cout << (i ? "," : "") << v[i];
    cout << "]";
}

int main() {
    struct Case { vector<optional<int>> tree; vector<int> want; };
    Case cases[] = {
        {{1, null, 2, 3}, {1, 2, 3}},   // LeetCode example 1,
        {{}, {}},   // empty tree,
        {{1}, {1}},   // one node,
        {{1, 2, 4, 3}, {1, 2, 3, 4}},   // the tree from your main,
        {{1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9}, {1, 2, 4, 5, 6, 7, 3, 8, 9}},   // LeetCode example 2,
        {{1, 2, null, 3, null, 4}, {1, 2, 3, 4}},   // left chain
    };
    int failed = 0;
    for (auto& [tree, want] : cases) {
        TreeNode* root = build(tree);
        vector<int> got = Solution().preorderTraversal(root);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ");
        print(got);
        cout << endl;
        free_tree(root);
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
