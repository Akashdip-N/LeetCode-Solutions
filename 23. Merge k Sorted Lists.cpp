/*
    https://leetcode.com/problems/merge-k-sorted-lists/
*/
/*
    Solution Approach:- Divide and Conquer approach (Recursive Method)

    Time Complexity: O(N log k) (Binary Search Approach)
    Space Complexity: O(1)
    N = total number of nodes in all lists
    k = number of lists

    Explanation:-
        * Helper function (same as 21. Merge Two Sorted list)
        * Iterating through the lists and merging two lists at a time.
        * And then store the two merged lists in the same list.
        Ex:-
            list[0] = [1, 4, 5]
            list[1] = [1, 3, 4]
            list[2] = [2, 6]

            First pass:-
            list[0] = merge(list[0], list[1]) = [1, 1, 3, 4, 4, 5]
            list[1] = merge(list[2], list[3]) = [2, 6]

            Second pass:-
            list[0] = merge(list[0], list[1]) = [1, 1, 2, 3, 4, 4, 5, 6]
            list[1] = merge(list[2], list[3]) = []

        * Finally, return the first list which contains the merged list.
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int size = lists.size();

        while (size > 1) {
            int next_size = 0;

            for (int i = 0; i < size; i += 2) {
                if (i + 1 < size)
                    lists[next_size] = mergeTwoLists(lists[i], lists[i + 1]);
                else
                    lists[next_size] = lists[i];

                next_size++;
            }

            size = next_size;
        }

        return lists[0];
    }
};
