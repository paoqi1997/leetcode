/**
 * 92. 反转链表 II
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode *head, int left, int right) {
        unique_ptr<ListNode> dummy(new ListNode());
        dummy->next = head;

        auto p = dummy.get();
        for (int i = 1; i < left; ++i) {
            p = p->next;
        }

        head = p->next;

        //        ---------------------------------------
        //        |                                     |
        //        |                                     v
        // p ---> p->next(head) ---> head->next(q) ---> q->next
        //        ^                  |
        //        |                  |
        //        --------------------
        for (int i = left; i < right; ++i) {
            auto q = head->next;
            head->next = q->next;
            q->next = p->next;
            p->next = q;
        }

        return dummy->next;
    }
};
