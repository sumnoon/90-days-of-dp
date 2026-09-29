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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (p == nullptr || q == nullptr) return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    struct Case { vector<optional<int>> p, q; bool want; };
    Case cases[] = {
        {{1, 2, 3}, {1, 2, 3}, true},          // LeetCode example 1
        {{1, 2}, {1, null, 2}, false},         // LeetCode example 2: same values, different shape
        {{1, 2, 1}, {1, 1, 2}, false},         // LeetCode example 3
        {{}, {}, true},                        // both empty
        {{1}, {}, false},                      // one empty
        {{}, {1}, false},                      // the other empty
        {{1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9},
         {1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9}, true},
        {{1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9},
         {1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 10}, false},   // one deep leaf differs
    };
    int failed = 0;
    for (auto& [p, q, want] : cases) {
        TreeNode* a = build(p);
        TreeNode* b = build(q);
        bool got = Solution().isSameTree(a, b);
        bool ok = got == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << boolalpha << got << endl;
        free_tree(a);
        free_tree(b);
    }

    TreeNode* t = build({1, 2, 3});
    bool ok = Solution().isSameTree(t, t);
    if (!ok) ++failed;
    cout << (ok ? "ok   " : "FAIL ") << "a tree against itself: " << boolalpha << ok << endl;
    free_tree(t);

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
