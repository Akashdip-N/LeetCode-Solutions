/*
    https://leetcode.com/problems/3sum/
*/
/*
    Solution Approach:- Using Sorting and Two Pointers

    Time Complexity: O(N^2)
    Space Complexity: O(K)
    N = number of elements in the array
    K = number of triplets found

    Explanation:
        - First, we sort the array.
        - Then, we iterate through the array and for each element.
        - We use two pointers, one starting from the next element
            and the other starting from the end of the array.
        - We check the sum of the three elements.
            - If the sum is zero,
                we add the triplet to the result.
            - If the sum is less than zero,
                we move the left pointer to one step to the right.
            - If the sum is greater than zero,
                we move the right pointer to one step to the left.
        - We also handle duplicates to avoid adding the same triplet multiple times.
        - Finally, we return the result.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            else
                if (i > 0 && (nums[i] == nums[i-1]))
                    continue;

            int l = i + 1, r = nums.size() - 1;

            // Searching the whole array for the triplet
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.clear();

                    l++;
                    r--;

                    // To avoid duplicates
                    while (l < r) {
                        if (nums[l] == nums[l-1])
                            l++;
                        else if (nums[r] == nums[r+1])
                                r--;
                        else
                            break;
                    }
                }
                else if (sum < 0)
                        l++;
                else
                    r--;
            }
        }

        return res;
    }
};
