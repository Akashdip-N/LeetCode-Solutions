/*
    https://leetcode.com/problems/find-the-duplicate-number
*/
/************* Little complicated in understanding the solution *************/
/*
    Problem explanation:-

    To solve this problem, we have to think the array as a linked list,
        where each number points to the next index.
    Since there is a duplicate number, there will be a cycle in this linked list.

    It is said in the problem that the numbers are in the range [1, n],
        where n is the size of the array.

    That means we can say that the first number would be,
        starting point of the linked list, and the
            next number would be the next node in the linked list.
    Ex:-
        nums = [1, 3, 4, 2, 2]
        pos  = [0, 1, 2, 3, 4] // this is not given, but for understanding

        From the above example, we can say the following about the linked list:
            i. The first number (1) points to the index 1 (3).
            ii. The second number (3) points to the index 3 (2).
            iii. The third number (4) points to the index 4 (2).
            iv. The fourth number (2) points to the index 2 (4).
            v. The fifth number (2) points to the index 2 (4).

        The linked list representation will be:
            1 → 3 → 4 → 2
                    ↑   ↓
                    ← ← ←

        So, here we can see that there is a cycle in the linked list,
            and we can use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
                to find the duplicate number.
*/
/*
    Solution Approach: Floyd's Cycle Detection Algorithm

    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:
        - We use two pointers, slow and fast.
        - The slow pointer moves one step at a time,
            while the fast pointer moves two steps at a time.
        - If there is a cycle, the two pointers will eventually meet.
        - Once they meet, we reset the slow pointer to the start of the array
            and move both pointers one step at a time until they meet again.
        - The point where they meet is the duplicate number.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
