/*
    https://leetcode.com/problems/linked-list-cycle/
*/
/*
    Solution Approach: Floyd's Cycle Detection Algorithm

    Floyd's Cycle Detection Algorithm is a two-pointer approach
        that uses a slow pointer and a fast pointer
            to detect cycles in a linked list.
    The slow pointer moves one step at a time,
        while the fast pointer moves two steps at a time.
    If there is a cycle in the linked list,
        the fast pointer will eventually catch up to the slow pointer.

    Time Complexity: O(n)
    Space Complexity: O(1)
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

/*****************************************************************/
/*
    Solution Approach: Hash Table

    Time Complexity: O(n)
    Space Complexity: O(n)

    We can use a hash table to keep track of the nodes we have visited.
    If we encounter a node that is already in the hash table,
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
