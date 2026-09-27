// Week 1 Sunday redo, from memory: LC 21 Merge Two Sorted Lists
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
    ListNode* func(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = func(list1->next, list2);
            return list1;
        }
        else {
            list2->next = func(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return func(list1, list2);
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
    struct Case { vector<int> a, b, want; };
    Case cases[] = {
        {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
        {{}, {}, {}},
        {{}, {0}, {0}},
        {{5}, {}, {5}},
        {{1, 2, 3}, {4, 5, 6}, {1, 2, 3, 4, 5, 6}},
        {{4, 5, 6}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}},
        {{2, 2, 2}, {2, 2}, {2, 2, 2, 2, 2}},
        {{-100, 0, 100}, {-50, 50}, {-100, -50, 0, 50, 100}},
    };
    int failed = 0;
    for (auto& [a, b, want] : cases) {
        ListNode* merged = Solution().mergeTwoLists(build(a), build(b));
        bool ok = to_vector(merged) == want;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << a.size() << " + " << b.size() << " nodes" << endl;
        free_list(merged);   // one pass frees both: the nodes were spliced, not copied
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
