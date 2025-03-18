/*
    https://leetcode.com/problems/add-two-numbers/
*/
/*
    Solution Approach: Using a dummy node to simplify the code.

    * Created two nodes, one for the result and one for the current node.
    * Initialized the digit v1, v2 to 0
    * Using while loop to itertate over the two linked lists,
        checking if the either of the linked lists is null,
            then we setting the value of v1 or v2 to 0,
                this is done in case when the size of the linked list are different.
    * Storing the 1s place in the result linked list.
    * Storing the 10s place in the rem variable, to use it for the next iteration.

    * After the loop is complete, checking if the rem is 1,
        which means that there is a carry left over,
            so we create a new node with value 1,
                and set the next pointer of the current node to this new node.
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
