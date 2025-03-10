/*
    https://leetcode.com/problems/merge-two-sorted-lists/
*/
/*
    Solution Approach:-
    * Storing the lowest value first then
        moving to the next node.
    * If traversal of any of the one list is complete,
        then we can simply append the remaining list to the result.
    * Returning the ret->next because
        the first value of the node is a null pointer.
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
