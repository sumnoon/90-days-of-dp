#include <algorithm>
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
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = helper(root->left);
        int r = helper(root->right);
        return 1 + max(l, r);
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
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
    struct Case { vector<optional<int>> tree; int want; };
    Case cases[] = {
        {{3, 9, 20, null, null, 15, 7}, 3},   // LeetCode example 1
        {{1, null, 2}, 2},                    // LeetCode example 2
        {{}, 0},                              // empty tree
        {{1}, 1},                             // one node
        {{1, 2, 4, 3}, 3},                    // the traversal tree
        {{1, 2, null, 3, null, 4}, 4},        // left chain
        {{1, 2, 3, 4, 5, 6, 7}, 3},           // perfect tree
    };
    int failed = 0;
    for (auto& [tree, want] : cases) {
        TreeNode* root = build(tree);
        int got = Solution().maxDepth(root);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "depth " << got << endl;
        free_tree(root);
    }

    // LeetCode's limit: 10^4 nodes. As one chain, that is 10^4 frames deep.
    TreeNode* chain = nullptr;
    for (int i = 0; i < 10000; ++i) chain = new TreeNode(i, chain, nullptr);
    int deep = Solution().maxDepth(chain);
    bool ok = deep == 10000;
    if (!ok) ++failed;
    cout << (ok ? "ok   " : "FAIL ") << "depth " << deep << " (10,000-node chain)" << endl;
    free_tree(chain);

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
