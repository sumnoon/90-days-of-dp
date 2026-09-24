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
        else if (list2 == nullptr) {
            return list1;
        }
        else if (list1->val <= list2->val) {
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

void print_list(ListNode* head) {
    cout << "[";
    for (ListNode* p = head; p; p = p->next) {
        cout << p->val;
        if (p->next) cout << ",";
    }
    cout << "]";
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

vector<int> read_list() {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) cin >> x;
    return v;
}

int main() {
    // Two lists, each as a count then that many values:
    //     3 1 2 4   3 1 3 4
    vector<int> a = read_list();
    vector<int> b = read_list();

    ListNode* l1 = build(a);
    ListNode* l2 = build(b);

    cout << "list1: "; print_list(l1); cout << endl;
    cout << "list2: "; print_list(l2); cout << endl;

    ListNode* merged = Solution().mergeTwoLists(l1, l2);
    cout << "merged: "; print_list(merged); cout << endl;

    free_list(merged);   // one pass frees both: the nodes were spliced, not copied
    return 0;
}
