/*
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
/*
    Solution Approach:- Two pointers Approach & Linked List

    * Using a dummy node to handle cases,
        where the n points to the head node.

    * Using for loop to move fast pointer n steps ahead,
        because we want to keep the gap between slow and fast pointers constant.
    * Using while loop to move both pointers until ,
        fast pointer reaches the end,
            and we will move the slow pointer to the
                node before the nth node from the end.
    * Making new connection to skip the nth node from the end.
    * Deleting the nth node from the end.
    * Returnining dummy_node->next which is the new head of the list.
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;

        delete temp;

        return dummy->next;
    }
};
