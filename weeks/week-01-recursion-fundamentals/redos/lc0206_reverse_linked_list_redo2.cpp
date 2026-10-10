// Week 1 redo 2, from memory (Sat Oct 10, two weeks after redo 1): LC 206 Reverse Linked List
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* pre = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        head = reverse(head);
        return head;
    }
};

// --- local harness (LeetCode supplies these) ---

ListNode* build(const vector<int>& vals) {
    ListNode* head = nullptr;
    for (int i = (int)vals.size() - 1; i >= 0; --i) head = new ListNode(vals[i], head);
    return head;
}

vector<int> to_vector(ListNode* head) {
    vector<int> v;
    for (ListNode* p = head; p; p = p->next) v.push_back(p->val);
    return v;
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    vector<int> longest(5000);                       // LeetCode's largest: 5000 nodes, 5000 frames deep
    for (int i = 0; i < 5000; ++i) longest[i] = i - 2500;

    vector<vector<int>> inputs = {
        {1, 2, 3, 4, 5},                             // LeetCode example 1
        {1, 2},                                      // LeetCode example 2
        {},                                          // LeetCode example 3
        {7},
        longest,
    };
    int failed = 0;
    for (auto& in : inputs) {
        vector<int> want(in.rbegin(), in.rend());
        ListNode* got = Solution().reverseList(build(in));
        bool ok = to_vector(got) == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << in.size() << " nodes reversed" << endl;
        free_list(got);
    }

    // The nodes themselves must be relinked, not their values copied.
    ListNode* a = build({1, 2, 3});
    ListNode *n1 = a, *n2 = a->next, *n3 = a->next->next;
    ListNode* r = Solution().reverseList(a);
    bool relinked = r == n3 && n3->next == n2 && n2->next == n1 && n1->next == nullptr;
    if (!relinked) ++failed;
    cout << (relinked ? "ok   " : "FAIL ") << "same nodes, links flipped, old head now ends the list" << endl;
    free_list(r);

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
