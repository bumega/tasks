#include <iostream>
#include <vector>
#include <algorithm>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* head = new ListNode;
        size_t mx_i;
        ListNode* el;
        bool flag = true;
        while (!lists.empty() and std::any_of(lists.begin(), lists.end(), [](const ListNode* ch) {return ch != nullptr;})) {
            mx_i = -1;
            for (size_t i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr) {
                    if (mx_i == -1 or lists[i]->val < lists[mx_i]->val) {
                        mx_i = i;
                    }
                }
            }
            if (flag) {
                flag = false;
                el = lists[mx_i];
                lists[mx_i] = lists[mx_i]->next;
                el->next = nullptr;
                head = el;
            } else {
                el->next = lists[mx_i];
                lists[mx_i] = lists[mx_i]->next;
                el = el->next;
                el->next = nullptr;
            }
        }
        return head;
    }
};*/



class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        size_t mx_i;
        ListNode* el;
        bool flag = true;
        while (!lists.empty()) {
            mx_i = -1;
            for (size_t i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr) {
                    if (mx_i == -1 or lists[i]->val < lists[mx_i]->val) {
                        mx_i = i;
                    }
                }
            }
            std::cout << "yep\n";
            if (flag) {
                flag = false;
                el = lists[mx_i];
                head = el;
            } else {
                el->next = lists[mx_i];
                el = el->next;
            }
            if (lists[mx_i]->next != nullptr) {
                lists[mx_i] = lists[mx_i]->next;
            } else {
                lists.erase(lists.begin() + mx_i);
            }
            el->next = nullptr;
        }
        return head;
    }
};



int main() {
    ListNode* m1_1 = new ListNode(1);
    ListNode* m1_2 = new ListNode(4);
    ListNode* m1_3 = new ListNode(5);
    ListNode* m2_1 = new ListNode(1);
    ListNode* m2_2 = new ListNode(3);
    ListNode* m2_3 = new ListNode(4);
    ListNode* m3_1 = new ListNode(2);
    ListNode* m3_2 = new ListNode(6);
    m1_1->next = m1_2;
    m1_2->next = m1_3;
    m1_3->next = nullptr;

    m2_1->next = m2_2;
    m2_2->next = m2_3;
    m2_3->next = nullptr;

    m3_1->next = m3_2;
    m3_2->next = nullptr;

    std::vector<ListNode*> v = {m1_1, m2_1, m3_1};
    ListNode* ans = new ListNode;
    ans = Solution().mergeKLists(v);
    while (ans != nullptr) {
        std::cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
