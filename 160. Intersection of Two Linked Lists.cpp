/*
    https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // The runtime of this solution is 708 ms
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        else{
            ListNode *temp;
            while (headA != NULL){
                temp = headB;
                while (temp != NULL){
                    if(headA == temp)
                    return headA;
                    temp = temp->next;
                }
                headA = headA->next;
            }
        }
        return nullptr;
    }
};

/**************************************************************************/

class Solution {
    // The runtime of this solution is 38 ms
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA, *second = headB;
        while(first != second) {
            if(!first)
                first = headB;
            else
                first = first->next;

            if(!second)
                second = headA;
            else
                second = second->next;
        }
        return first;
    }
};