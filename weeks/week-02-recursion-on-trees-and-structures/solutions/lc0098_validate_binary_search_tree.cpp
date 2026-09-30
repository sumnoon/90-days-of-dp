#include <climits>
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
    bool validate(TreeNode* root, TreeNode* lo, TreeNode* hi) {
        if (root == nullptr) {
            return true;
        }
        
        if ((lo != nullptr && lo->val >= root->val) 
        || (hi != nullptr && hi->val <= root->val)) {
            return false;
        }

        return validate(root->left, lo, root) && validate(root->right, root, hi);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
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
    struct Case { vector<optional<int>> tree; bool want; };
    Case cases[] = {
        {{2, 1, 3}, true},                         // LeetCode example 1
        {{5, 1, 4, null, null, 3, 6}, false},      // LeetCode example 2: 4 < 5 on the right
        {{5, 4, 6, null, null, 3, 7}, false},      // 3 is fine under 6, but it is right of 5
        {{3, 1, 5, 0, 2, 4, 6}, true},             // a full valid BST
        {{1, 1}, false},                           // duplicates are not allowed
        {{2, 2, 2}, false},
        {{1}, true},
        {{}, true},
        {{INT_MIN}, true},                         // extreme values: no sentinel to collide with
        {{INT_MAX}, true},
        {{INT_MIN, null, INT_MAX}, true},
        {{INT_MAX, INT_MIN}, true},
        {{0, INT_MIN, INT_MAX, null, -1}, true},   // -1 under INT_MIN's right, still left of 0
        {{0, INT_MIN, INT_MAX, null, 1}, false},   // 1 is right of INT_MIN but not left of 0
        {{10, 5, 15, null, null, 6, 20}, false},   // 6 < 10 deep in the right subtree
    };
    int failed = 0;
    for (auto& [tree, want] : cases) {
        TreeNode* root = build(tree);
        bool got = Solution().isValidBST(root);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << boolalpha << got << endl;
        free_tree(root);
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
