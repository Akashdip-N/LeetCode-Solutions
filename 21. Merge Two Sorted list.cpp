/*
    https://leetcode.com/problems/merge-two-sorted-lists/
*/
/*
    Solution Approach:- Recursive Method

    Explanation:- Recursively checking the lowest value and moving to the next node,
        until one of the lists is empty, then appending the rest of the other list.
*/
class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // If l1 is empty, return l2
        if (!l1)
            return l2;

        // If l2 is empty, return l1
        if (!l2)
            return l1;

        ListNode* node = new ListNode();
        if (l1->val < l2->val) {
            node->val = l1->val;
            node->next = mergeTwoLists(l1->next, l2);
        } else {
            node->val = l2->val;
            node->next = mergeTwoLists(l1, l2->next);
        }

        return node;
    }
};

/****************************************************************************/
/*
    Solution Approach:- Iterative Method, Two Pointers

    Explanation:- Storing the lowest value first then moving to the next node,
        until one of the lists is empty, then appending the rest of the other list.
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node = new ListNode;
        ListNode *ret = node;

        while (list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        if(list1 == nullptr)
            node->next = list2;
        else
            node->next = list1;

        return ret->next;
    }
};
