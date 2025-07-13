/*
    https://leetcode.com/problems/delete-node-in-a-linked-list
*/
/*
    Solution Approach: Pointing the current node to the next node

    Time Complexity: O(1)
    Space Complexity: O(1)

    Explanation:
        - We are only given the node to be deleted, not the head of the list.
        - To remove the node from the list, we take the value of the next node
            and assign it to the current node.
        - Then we point the current node's next to the next node's next.
        - This will effectively remove the current node from the list.
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
