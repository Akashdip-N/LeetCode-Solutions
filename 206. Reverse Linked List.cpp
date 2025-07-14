/*
    https://leetcode.com/problems/reverse-linked-list/
*/
/*
    Solution Approach:- Two pointers approach
    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:-
        - Using two pointers concept to reverse the linked list.
        - One pointer (current) will traverse the list,
          while the other pointer (prev) will keep track of the previous node.
        - The next pointer will store the next node of the current node.
        - At each step, we reverse the link
            by pointing the current node's next to the previous node.
        - Finally, we return the new head of the reversed linked list.
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

    Explanation:-
        - Using recursion to reverse the linked list.
        - The base case is when the head is NULL or has no next node.
        - We recursively call the function for the next node,
            and then reverse the link
                by pointing the next node's next to the current node.
        - Finally, we set the current node's next to NULL to avoid cycles.
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
