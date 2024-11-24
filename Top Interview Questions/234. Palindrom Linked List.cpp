/*
    https://leetcode.com/problems/palindrome-linked-list/
*/

/*------------------------------------------------------------------------*/
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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> a;
        while (temp->next != nullptr){
            a.push_back(temp->val);
            temp = temp->next;
        }
        a.push_back(temp->val);
        for (int i = 0, j = (a.size() - 1); i < (a.size()/2); i++, j--)
            if(a[i] != a[j])
                return false;
        return true;
    
    }
};