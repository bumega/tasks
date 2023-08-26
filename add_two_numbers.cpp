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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* el = new ListNode();
        ListNode* head = el;
        bool flag;
        while (l1 != nullptr and l2 != nullptr) {
            flag = false;
            el->val += l1->val + l2->val;
            std::cout << l1->val << " " << l2->val << " " << el->val << "\n";
            if (el->val > 9) {
                flag = true;
                el->val -= 10;
            }
            if (l1->next != nullptr or l2->next != nullptr or flag == true) {
                el->next = new ListNode();
                el = el->next;
                if (flag == true) {
                    el->val += 1;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            el->val += l1->val;
            flag = false;
            std::cout << l1->val << " "  << el->val << "\n";
            if (el->val > 9) {
                flag = true;
                el->val -= 10;
            }
            if (l1->next != nullptr or flag == true) {
                el->next = new ListNode();
                el = el->next;
                if (flag == true) {
                    el->val += 1;
                }
            }
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            el->val += l2->val;
            flag = false;
            std::cout  << l2->val << " " << el->val << "\n";
            if (el->val > 9) {
                flag = true;
                el->val -= 10;
            }
            if (l2->next != nullptr or flag == true) {
                el->next = new ListNode();
                el = el->next;
                if (flag == true) {
                    el->val += 1;
                }
            }
            l2 = l2->next;
        }
        if (el->val >= 10) {
            el->val -= 10;
            el->next = new ListNode(1);
        }
        return head;
    }
};



int main() {
    ListNode* l1 = new ListNode(5);
    ListNode* h1 = l1;
    ListNode* l2 = new ListNode(5);
    ListNode* h2 = l2;



    ListNode* ans = Solution().addTwoNumbers(h1, h2);
    while (ans != nullptr) {
        std::cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

