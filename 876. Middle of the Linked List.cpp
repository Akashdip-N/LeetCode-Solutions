/*
    https://leetcode.com/problems/middle-of-the-linked-list/description/
*/
/*
    Solution Approach: Using Floyd's cycle detection algorithm (Two Pointers Approach)

    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:
        - Initialize two pointers, slow and fast, both pointing to the head.
        - Move the slow pointer one step at a time and
            the fast pointer two steps at a time.
        - When the fast pointer reaches the end of the list,
          the slow pointer will be at the middle node.
        - Return the slow pointer as it points to the middle node.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Edge case: if the list is empty, return nullptr
        if (!head)
            return nullptr;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
