/*
    https://leetcode.com/problems/reverse-linked-list/
*/
/*
    Solution Approach:- Two pointers approach
    Time Complexity: O(n)
    Space Complexity: O(1)

    Taking two pointers prev and next and reversing the links between nodes.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return nullptr;

		ListNode *current = head;
        ListNode *prev = NULL, *next = NULL;

        while (current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }
};

/****************************************************** */
/*
    Solution Approach:- Recursive approach
    Time Complexity: O(n)
    Space Complexity: O(1)

*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) // base case
            return head;

        ListNode *newHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};
