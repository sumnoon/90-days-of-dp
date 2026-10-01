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
    ListNode* func(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        firstNode->next = func(secondNode->next);
        secondNode->next = firstNode;

        return secondNode;
    }
    ListNode* swapPairs(ListNode* head) {
        return func(head);
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
    struct Case { vector<int> in, want; };
    Case cases[] = {
        {{1, 2, 3, 4}, {2, 1, 4, 3}},          // LeetCode example 1
        {{}, {}},                              // LeetCode example 2
        {{1}, {1}},                            // LeetCode example 3
        {{1, 2, 3}, {2, 1, 3}},                // LeetCode example 4: odd length, last node stays
        {{1, 2}, {2, 1}},
        {{1, 2, 3, 4, 5, 6, 7}, {2, 1, 4, 3, 6, 5, 7}},
    };
    int failed = 0;
    for (auto& [in, want] : cases) {
        ListNode* got = Solution().swapPairs(build(in));
        bool ok = to_vector(got) == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << in.size() << " nodes" << endl;
        free_list(got);
    }

    // LeetCode forbids swapping values: the nodes themselves must move.
    ListNode* a = build({1, 2, 3, 4});
    ListNode *n1 = a, *n2 = a->next, *n3 = a->next->next, *n4 = a->next->next->next;
    ListNode* r = Solution().swapPairs(a);
    bool moved = r == n2 && n2->next == n1 && n1->next == n4 && n4->next == n3 && n3->next == nullptr;
    if (!moved) ++failed;
    cout << (moved ? "ok   " : "FAIL ") << "nodes relinked, values untouched" << endl;
    free_list(r);

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
