/*
    https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/
/*
    Solution Approach: Using Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = size of the input array

    Intuition:-
        - We have to pick k cards at a time from either ends of the array.
        - Instead of picking k cards, we can think of it as leaving n-k cards in the middle.
        - The sum of the remaining n-k cards will be minimized to maximize the score
        - We can use a sliding window of size n-k to find the minimum sum
            of the remaining cards.
        - The maximum score will be the total sum of the array minus
            the minimum sum of the remaining cards.

        Ex:-
            * cardPoints = [1,2,3,4,5,6,1],
            * k = 3, size = 7, n-k = 4
            * sum of the last k(3) cards [5,6,1] = 5 + 6 + 1 = 12

            * now we will move the window of size n-k(4) to find
                the minimum sum of the remaining cards
            * Iteration 1:
                - left = 0, right = 4
                - current window (excluding) = [2,3,4,5]
                - sum = total_sum (12) + cardPoints[left] (1) - cardPoints[right] (5)
                    = 12 + 1 - 5 = 8
                - res = max(res, sum) = max(12, 8) = 12
            * Iteration 2:
                - left = 1, right = 5
                - current window (excluding) = [3,4,5,6]
                - sum = total_sum (8) + cardPoints[left] (2) - cardPoints[right] (6)
                    = 8 + 2 - 6 = 4
                - res = max(res, sum) = max(12, 4) = 12
            * Iteration 3:
                - left = 2, right = 6
                - current window (excluding) = [4,5,6,1]
                - sum = total_sum (4) + cardPoints[left] (3) - cardPoints[right] (1)
                    = 4 + 3 - 1 = 6
                - res = max(res, sum) = max(12, 6) = 12
            * Iteration 4:
                - left = 3, right = 7,
                - (right > size), so we stop the iteration
            * Final result = 12

    Explanation:-
        * Initializing left pointer to 0 and right pointer to (size - k)
        * Finding the sum of the last k cards and storing it in res
        * Using a while loop to iterate until right pointer is less than size
            - Adding the cardPoints[left] to sum and subtracting cardPoints[right] from sum
            - Updating res with the maximum of res and sum
        * Returning res as the final result
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int left = 0, right = size - k;
        int sum = 0, res = 0;

        for(int i = right; i < size; i++)
            sum += cardPoints[i];

        res = sum;

        while(right < size){
            sum += (cardPoints[left] - cardPoints[right]);
            res = max(res, sum);
            left++;
            right++;
        }

        return res;
    }
};
