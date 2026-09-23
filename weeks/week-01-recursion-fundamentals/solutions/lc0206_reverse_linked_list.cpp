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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *prev = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return prev;
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

int main() {
    // Reads a count then that many values, e.g. "5  1 2 3 4 5".
    int n;
    if (!(cin >> n)) return 0;

    vector<int> vals(n);
    for (int& v : vals) cin >> v;

    ListNode* head = build(vals);
    cout << "before: ";
    print_list(head);
    cout << endl;

    head = Solution().reverseList(head);
    cout << "after:  ";
    print_list(head);
    cout << endl;

    free_list(head);
    return 0;
}
