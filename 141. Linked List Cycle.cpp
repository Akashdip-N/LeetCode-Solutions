/*
    https://leetcode.com/problems/linked-list-cycle/
*/
/*
    Solution Approach: Floyd's Cycle Detection Algorithm

    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:
        - Using two pointers, slow and fast.
        - Slow pointer moves one step at a time,
            while fast pointer moves two steps at a time.
        - If there is a cycle,
            the fast pointer will eventually meet the slow pointer,
                we return true.
        - If the fast pointer reaches the end of the list (nullptr),
            then there is no cycle,
                we return false.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
        return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

/********************** NOT BETTER SPACE COMPLEXITY ***************************/
/*
    Solution Approach: Hash Table

    Time Complexity: O(n)
    Space Complexity: O(n)

    Explanation:
        - We can use a hash table to keep track of the nodes we have visited.
        - If we encounter a node that is already in the hash table,
            then we know that there is a cycle in the linked list.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;

        unordered_map<ListNode*, int> visited;
        ListNode* curr = head;

        while(curr != nullptr) {
            if(visited.find(curr) != visited.end())
                return true;

            visited[curr] = 1;
            curr = curr->next;
        }

        return false;
    }
};
