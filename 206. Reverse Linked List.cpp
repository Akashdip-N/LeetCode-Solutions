/*
    https://leetcode.com/problems/reverse-linked-list/
*/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of nodes in the linked list

    Intuition:-
        - Given us a linked list, we need to reverse it.

        - Using two pointers, to solve this problem.
        - We are changing the direction of the next pointer for each node in the linked list.
        - At the end, we will return the new head of the reversed linked list.

    Explanation:-
        * Base case:- If the head is null, return null.
        * Initialize three pointers:
            - current: points to the current node being processed (initially head).
            - prev: points to the previous node (initially null).
            - next: points to the next node (initially null).
        * Iterate through the linked list until current is null:
            - Store the next node (current->next) in next.
            - Reverse the link by pointing current->next to prev.
            - Move prev to current and current to next.
        * After the loop, prev will point to the new head of the reversed linked list.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

		ListNode *current = head;
        ListNode *prev = nullptr, *next = nullptr;

        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }
};

/********************************************************************************************/
/*
    Solution Approach:- Using Recursive approach
    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of nodes in the linked list

    Intuition:-
        - Same as the previous approach, but using recursion to reverse the linked list.

        - Here also we are changing the direction of the next pointer for each node.
        - How we are tackling this problem is we are dividing the linked list into two parts,
            and then we are reversing the second part of the linked list recursively.

    Explanation:-
        * Base case:- If the head is null that means
                    it's either an empty linked list or it's the last node of the linked list
                        hence we will return the nullptr.

        * Creating a newHead pointer that would point to the
            new head of the reversed linked list.
        * If the next node of the current node / head is not null,
            we will call the reverseList function recursively for the next node.
        * After the recursive call,
            we will change the direction of the next pointer of the next node
                to point to the current node / head.

        * Finally, we will set the next pointer of the current node / head to null
            to avoid a cycle in the linked list.
        * After all the recursive calls are completed,
            we will return the new head of the reversed linked list.

        Ex:-
            Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
            After reversing: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

            Iteration 1:
                head = 1, head->next = 2
                newHead = reverseList(2)

            Iteration 2:
                head = 2, head->next = 3
                newHead = reverseList(3)

            Iteration 3:
                head = 3, head->next = 4
                newHead = reverseList(4)

            Iteration 4:
                head = 4, head->next = 5
                newHead = reverseList(5)

            Iteration 5:
                head = 5, head->next = nullptr
                return nullptr

            Iteration 6:
                currently: head = 4, head->next = 5

                head->next->next = head (5->next = 4)
                head->next = nullptr (4->next = nullptr)
                Linked List: 5 -> 4 -> nullptr

            Iteration 7:
                currently: head = 3, head->next = 4
                head->next->next = head (4->next = 3)
                head->next = nullptr (3->next = nullptr)
                Linked List: 5 -> 4 -> 3 -> nullptr

            Iteration 8:
                currently: head = 2, head->next = 3
                head->next->next = head (3->next = 2)
                head->next = nullptr (2->next = nullptr)
                Linked List: 5 -> 4 -> 3 -> 2 -> nullptr

            Iteration 9:
                currently: head = 1, head->next = 2
                head->next->next = head (2->next = 1)
                head->next = nullptr (1->next = nullptr)
                Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr

            Iteration 10:
                currently: head = 1, head->next = nullptr
                return newHead (5)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;

        ListNode* newHead = head;

        if(head->next != nullptr){
            newHead = reverseList(head->next);
            head->next->next = head;
        }

        head->next = nullptr;
        return newHead;
    }
};
