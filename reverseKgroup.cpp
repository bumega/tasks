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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* l;
        ListNode* m;
        ListNode* r;
        int n = 0;
        ListNode* el = head;
        while (el != nullptr) {
            n++;
            el = el->next;
        }
        for (int i = 0; i < n / k; ++i) {
            l = el;
            m = el->next;
            r = el->next->next;
            
        }
    }

};



int main() {
    std::cout << "Hello, World!" << std::endl;
    int b = 10;
    int* a = &b;
    b = 111;
    std::cout << *a;
    return 0;
}
