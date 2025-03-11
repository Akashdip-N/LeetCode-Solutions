/*
    https://leetcode.com/problems/intersection-of-two-linked-lists/
*/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity: O(n+m)
    Space Complexity: O(1)

    The time complexity of this solution is good, and the space complexity is best!
*/
class Solution {
public:
    int get_size(ListNode* node){
        int size = 0;
        while(node != nullptr){
            size++;
            node = node->next;
        }
        return size;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = get_size(headA);
        int sizeB = get_size(headB);

        while(sizeA > sizeB){
            headA = headA->next;
            sizeA--;
        }

        while(sizeB > sizeA){
            headB = headB->next;
            sizeB--;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

/*****************************************************************************/
/*
    Solution Approach:- Using Hash-Map to store visited nodes

    Time Complexity: O(n+m)
    Space Complexity: O(n)

    The time complexity of this solution is good, but the space complexity is poor!
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        unordered_map<ListNode*,int> visited;

        while(headA != nullptr){
            visited[headA] = 1;
            headA = headA->next;
        }

        while(headB != nullptr){
            if(visited.find(headB) != visited.end()){
                ListNode* ret = headB;
                return ret;
            }

            headB = headB->next;
        }

        return nullptr;
    }
};
