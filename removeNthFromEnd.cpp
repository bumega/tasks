#include <iostream>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t t = 0;
        ListNode* el = head;
        while (el != nullptr) {
            t++;
            el = el->next;
        }
        t = t - n + 1;
        el = head;
        t--;
        for (size_t i = 0; i < t - 1; ++i) {
            el = el->next;
        }
        ListNode* tmp = el->next;
        el->next = el->next->next;
        delete tmp;
        if (t != 0) {
            return head;
        }
        return nullptr;
    }
};




int main() {
    int a = 11;
    int* b = &a;
    std::cout << *b;
    return 0;
}
