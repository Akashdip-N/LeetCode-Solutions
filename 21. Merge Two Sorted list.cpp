/*
    https://leetcode.com/problems/merge-two-sorted-lists/
*/
/*
    Solution Approach:- Iterative Method

    Time Complexity: O(n + m)
    Space Complexity: O(1) (no new node being created each time, just rearranging the pointers)
    n = number of nodes in list1
    m = number of nodes in list2

    Explanation:-
        * Create a new node to store the merged list.
        * Create a pointer to the head of the new list.
        * Iterate through both lists until one of them is empty.
        * Compare the values of the two lists and add the smaller value to the new list.
        * Move the pointer of the list from which the value was taken to the next node.
        * Move the pointer of the new list to the next node.
        * After the loop, if one of the lists is not empty,
            add the remaining nodes to the new list.
        * Finally, return the head of the new list.
            i.e. head->next (as head is a dummy node).
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *node = new ListNode;
        ListNode *head = node;

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

        return head->next;
    }
};

/********************************************************************************************/
/*
    Solution Approach:- Recursive Method

    Time Complexity: O(n + m)
    Space Complexity: O(n + m)
    n = number of nodes in list1
    m = number of nodes in list2

    Explanation:-
        * Checking if any of the lists is empty, if so return the other list.
        * Compare the values of the two lists.
        * If the value of list1 is smaller, set the next pointer of list1 to
            the result of merging the next node of list1 with list2.
        * If the value of list2 is smaller or equal, set the next pointer of list2 to
            the result of merging list1 with the next node of list2.
        * Return the list which has the smaller value.
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
