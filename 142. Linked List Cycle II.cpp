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

        while (fast != nullptr && fast->next != nullptr) {
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
