/*
    https://leetcode.com/problems/linked-list-cycle-ii
*/
/*
    Solution Approach: Floyd's Cycle Detection Algorithm (Tortoise and Hare)

    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:
        - Finding if there is a cycle or not in the list.
        - Using two pointers, entry and slow to find the start of the cycle.
        - When the cycle is detected,
            we use the slow pointer to find the location of the cycle's start,
                and use the entry pointer to traverse
                    from the head to the start of the cycle.
        - Return the node where the cycle begins, else return nullptr.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* entry = head;

                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return nullptr;
    }
};

/************************* USING HASH MAP *************************/
/*
    Solution Approach: Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)

    Explanation:
        - We can use a hash map to keep track of the nodes we have visited.
        - If we encounter a node that is already in the hash map,
            then we know that there is a cycle in the linked list,
                and we return that node.
        - If we reach the end of the list (nullptr),
            then there is no cycle, and we return nullptr.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> visited;

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* current = head;

        while (current) {
            if (visited.find(current) != visited.end())
                return current;

            visited[current] = 1;
            current = current->next;
        }

        return nullptr;
    }
};
