/**
 * 237. 删除链表中的节点
 * https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 */

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
    void deleteNode(ListNode *node) {
        if (node == nullptr) {
            return;
        }

        auto p = node->next;

        node->next = p->next;
        node->val = p->val;

        delete p;
        p = nullptr;
    }
};
