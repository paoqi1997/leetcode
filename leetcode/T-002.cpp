/**
 * 2. 两数相加
 * https://leetcode-cn.com/problems/add-two-numbers/
 */

#include <memory>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        unique_ptr<ListNode> dummy(new ListNode());

        auto p = dummy.get();

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = l1 != nullptr ? l1->val : 0;
            int val2 = l2 != nullptr ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;

            auto node = new ListNode(sum % 10);
            p->next = node;
            p = node;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return dummy->next;
    }

    ListNode* addTwoNumbers_v2(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        ListNode *p = nullptr;

        // n为进位变量
        int x = 0, y = 0, n = 0;

        auto p1 = l1, p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            x = p1->val;
            y = p2->val;

            int v = (x + y) % 10;
            v += n;
            n = 0;

            // x=2, y=7, n=1
            if (v >= 10) {
                v %= 10;
                n = 1;
            }

            if (x + y >= 10) {
                n = 1;
            }

            if (head == nullptr) {
                head = new ListNode(v);
                p = head;
            } else {
                p->next = new ListNode(v);
                p = p->next;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != nullptr) {
            x = p1->val;

            int v = (x + n) % 10;

            if (x + n >= 10) {
                n = 1;
            } else {
                n = 0;
            }

            if (head == nullptr) {
                head = new ListNode(v);
                p = head;
            } else {
                p->next = new ListNode(v);
                p = p->next;
            }

            p1 = p1->next;
        }

        while (p2 != nullptr) {
            y = p2->val;

            int v = (y + n) % 10;

            if (y + n >= 10) {
                n = 1;
            } else {
                n = 0;
            }

            if (head == nullptr) {
                head = new ListNode(v);
                p = head;
            } else {
                p->next = new ListNode(v);
                p = p->next;
            }

            p2 = p2->next;
        }

        if (n != 0) {
            if (head == nullptr) {
                head = new ListNode(n);
                p = head;
            } else {
                p->next = new ListNode(n);
                p = p->next;
            }
        }

        return head;
    }
};
