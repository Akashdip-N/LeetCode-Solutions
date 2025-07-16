/*
    https://leetcode.com/problems/4sum/
*/
/*
    Solution Approach:- Using Sorting and Two Pointers

    Time Complexity: O(N^3)
    Space Complexity: O(K)
    N = number of elements in the array
    K = number of quadruplets found

    Explanation:
        - This problem is an extension of the `15.3Sum` problem.
        - The only difference is we have to type cast the sum to `long long`
            to avoid overflow issues when dealing with large integers. (line 36)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int size = nums.size();

        for (int i = 0; i < size; i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < size; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = size - 1;

                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    } else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }
};
