/*
    https://leetcode.com/problems/reorder-list/
*/
/*
    Solution Approach:

    1. Find the middle of the list using slow and fast pointer.
    2. Reverse the second half of the list.
    3. Merge the two lists.
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing the second half of the list
        ListNode *second = slow->next;
        ListNode* prev = slow->next = nullptr;

        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // merging the two list
        ListNode* first = head;
        second = prev;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
