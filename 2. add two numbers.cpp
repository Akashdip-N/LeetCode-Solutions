/*
    https://leetcode.com/problems/add-two-numbers/
*/
/*
    Solution Approach:- Using Linked List

    Time Complexity:- O(max(N, M))
    Space Complexity:- O(max(N, M))
    N = size of l1
    M = size of l2

    Intuition:-
        - Given us two Linked List in reverse order.
        - We have to add the two numbers from each of the linked list and
            return the sum in reverse order as well.

        - We have to keep track of the carry while adding the two numbers.
        - Using a dummy node to store the result.
        - At the end, we would return the next of the dummy node as the result.

    Explanation:-
        * Creating a dummy node 'res' to store the result.
        * Using a pointer 'node' to traverse the result linked list.
        * Initializing the variables remainder, v1 and v2 to 0.
        * Iterating the loop while both l1 and l2 are not null,
            performing the following operations in each iteration:-
            i. Checking if l1 is null, then we set the value of l1 to 0,
                else we store the value of the current l1 node in v1 and move to the next node.
            ii. Performing the same operation for l2 and storing the value in v2.
            iii. Storing the sum of v1, v2 and remainder in a variable 'sum'.
            iv. Updating the value of remainder to sum/10.
            v. Creating a new node with the value of sum%10 and
                linking it to the next of the current node.
            vi. Moving the pointer 'node' to the next node.
        * After the loop, if the remainder is 1,
            we create a new node with the value of 1 and link it to the next of the current node.
        * Finally, we return the next of the dummy node 'res' as the result.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* node = res;

        int rem = 0;
        int v1 = 0, v2 = 0;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 == nullptr)
                v1 = 0;
            else{
                v1 = l1->val;
                l1 = l1->next;
            }

            if(l2 == nullptr)
                v2 = 0;
            else{
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + rem;
            rem = sum/10;

            node->next = new ListNode(sum%10);
            node = node->next;
        }

        if(rem == 1)
            node->next = new ListNode(1);

        return res->next;
    }
};
