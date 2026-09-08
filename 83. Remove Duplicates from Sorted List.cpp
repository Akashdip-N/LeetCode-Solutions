/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/
/*
    Solution Approach:- Using In-Place LinkedList Traversal and Mutation

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = Number of Nodes in the LinkedList

    Intuition:-
        - Given us a asending order sorted linked list, where we may have duplicate values.
        - We need to remove the duplicates from the linked list,
            and return the head of the linked list.

        - We can solve this problem by traversing the linked list in-place,
            and mutating the linked list to remove the duplicates.

    Explanation:-
        * Base case:- If the head is nullptr, return nullptr.

        * Initialize a pointer node to the head of the linked list.
        * While there exists a node next to the current node, performing the following steps:-
            - Checking if the current node's value is equal to the next node's value,
                - If they are equal, then we point
                    the current node's next to the node after the next node.
                - If they are not equal, then we move the current node to the next node.
        * Finally, we return the head of the linked list.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* node = head;

        while (node->next != nullptr) {
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }

        return head;
    }
};

/***********************************************************************************************/
/*
    Solution Approach:- Using Recursion

    Time Complexity:- O(N)
    Space Complexity:- O(N) (Due to recursion call stack)
    N = Number of Nodes in the LinkedList

    Intuition:-
        - Same as the previous approach, but using recursion to traverse the linked list.

    Explanation:-
        * Base case:- If the head or the node next to the head is nullptr, return the head.

        * Calling the function on head->next, and storing the result in head->next.

        * Checking if the current node's value is equal to the next node's value,
            - If they are equal, then we return the next node.
            - If they are not equal, then we return the current node.

        * Finally, we return the head of the linked list.
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        head->next = deleteDuplicates(head->next);

        if (head->val == head->next->val)
            return head->next;

        return head;
    }
};
