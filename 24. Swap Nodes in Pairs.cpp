/*
    https://leetcode.com/problems/swap-nodes-in-pairs
*/
/*
    Solution Approach:- Using Recursion
    Time Complexity: O(n)
    Space Complexity: O(n) for recursion stack space
        n = number of nodes in the linked list

    Explanation:
        i. If the list is empty or has only one node, return the head.
        ii. Take the first two nodes (node1 and node2).
        iii. Recursively call the function and
            swap the pairs in the rest of the list.
        iv. Set node1's next to the result of the recursive call.
        v. Set node2's next to node1.
        vi. Return node2 as the new head of the swapped pair.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* node1 = head;
        ListNode* node2 = head->next;

        node1->next = swapPairs(node2->next);
        node2->next = node1;

        return node2;
    }
};

/*****************************************************************************/
/*
    Solution Approach:- Iterative Approach
    Time Complexity: O(n)
    Space Complexity: O(1) for pointers
        n = number of nodes in the linked list

    Explanation:
        i. Create a dummy node to simplify edge cases.
        ii. Use two pointers (prev and curr) to traverse the list.
        iii. For each pair of nodes, swap them by adjusting their next pointers.
        iv. Move the pointers to the next pair and repeat until the end of the list.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // Swap the pair
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            // Move to the next pair
            prev = curr;
            curr = nextPair;
        }

        return dummy->next;
    }
};
