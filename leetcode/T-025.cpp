/**
 * 25. K 个一组翻转链表
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode *head, int k) {
        unique_ptr<ListNode> dummy(new ListNode());
        dummy->next = head;

        auto p = dummy.get();

        int len = getLength(head);

        for (int i = 0; i < len / k; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                // dummy ---> 1 ---> 2 ---> 3 ---> 4
                auto q = head->next;

                //            ---------------
                //            |             |
                //            |             v
                // dummy ---> 1      2 ---> 3 ---> 4
                head->next = q->next;

                //            ---------------
                //            |             |
                //            |             v
                // dummy ---> 1 <--- 2      3 ---> 4
                q->next = p->next;

                // dummy ---> 2 ---> 1 ---> 3 ---> 4
                p->next = q;

                // 1(head)被换到了2的位置
            }

            p = head;
            head = p->next;
        }

        return dummy->next;
    }

    int getLength(ListNode *head) {
        int len = 0;

        while (head != nullptr) {
            head = head->next;
            ++len;
        }

        return len;
    }
};
