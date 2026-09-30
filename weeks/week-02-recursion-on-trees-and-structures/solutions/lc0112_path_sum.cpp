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
    bool func(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum - root->val == 0;
        }
        return func(root->left, targetSum - root->val) || func(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return func(root, targetSum);
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

int main() {
    vector<optional<int>> ex1 = {5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1};
    struct Case { vector<optional<int>> tree; int target; bool want; };
    Case cases[] = {
        {ex1, 22, true},                  // LeetCode example 1: 5 -> 4 -> 11 -> 2
        {{1, 2, 3}, 5, false},            // LeetCode example 2
        {{}, 0, false},                   // LeetCode example 3: empty tree has no path, even for 0
        {{1, 2}, 1, false},               // 1 alone is not root-to-LEAF: 1 still has a child
        {{1, 2}, 3, true},
        {{1}, 1, true},                   // the root is a leaf
        {{-2, null, -3}, -5, true},       // negative values
        {{1, -2, -3, 1, 3, -2, null, -1}, -1, true},   // 1 -> -2 -> 1 -> -1
        {ex1, 26, true},                  // 5 -> 8 -> 13
        {ex1, 18, true},                  // 5 -> 8 -> 4 -> 1
        {ex1, 9, false},                  // 5 -> 4 is not a leaf path
    };
    int failed = 0;
    for (auto& [tree, target, want] : cases) {
        TreeNode* root = build(tree);
        bool got = Solution().hasPathSum(root, target);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "target " << target << ": " << boolalpha << got << endl;
        free_tree(root);
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
