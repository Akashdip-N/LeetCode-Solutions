/*
    https://leetcode.com/problems/subtree-of-another-tree
*/
/*
    Solution Approach:- Using Recursion

    Explanation:
        i. Checking if the current node is null, if it is, return nullptr.
        ii. Checking if the value of the current node is equal to the value to be removed,
                if yes, then we are going to the next node.
            else,
                we are going to the next node and linking it to the current node.
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr; // If the list is empty, return nullptr

        if(head->val == val)
            return removeElements(head->next, val);
        else {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
