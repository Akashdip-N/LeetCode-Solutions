/*
    https://leetcode.com/problems/merge-two-sorted-lists/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        ListNode *result = new ListNode();
        ListNode *head = result;
        while(List1 != nullptr && List2 != nullptr){
            if(List1->val < List2->val){
               result->next = List1;
               List1 = List1->next;
            }else{
              result->next = List2;
              List2 = List2->next;
            }
            
            result = result->next;
        }       
        
        if(List1!=nullptr)
            result->next=List1;
        else
            result->next=List2;
        
        return head->next;
    }
};