/*
    https://leetcode.com/problems/maximum-average-subarray-i
*/
/*
    Solution Approach:- Using Sliding Window Technique

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = size of the input array

    Explanation:-
        1. Summing up the first k elements of the array to get the initial sum.
        2. Using a sliding window approach, we iterate through the array starting from the k-th element.
        3. For each new element, we add it to the sum and subtract the begining of the window element.
        4. We keep track of the maximum sum encountered during this process.
        5. Finally, we return the maximum sum divided by k to get the maximum average.
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        for (int i = 0; i < k; ++i)
            sum += nums[i];

        double maxSum = sum;

        for (size_t i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};

/****************************** MY OWN APPROACH :) ****************************************/
/*
    Solution Approach: Sliding Window Technique

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = size of the input array

    Explanation:-
        * Same as above, but I used a different approach to calculate the average
            and keep track of the maximum average.
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double average = 0.0;
        double sum = 0.0;
        int size = nums.size(), left = 0;

        if(k > size)
            return 0;

        int i = 0;

        while(i < k){
            sum += double(nums[i]);
            i++;
        }
        average = double(sum)/double(k);

        while(i < size){
            sum -= double(nums[left]);
            sum += double(nums[i]);
            double new_average = sum / double(k);
            average = max(new_average, average);
            i++;
            left++;
        }

        return average;
    }
};
