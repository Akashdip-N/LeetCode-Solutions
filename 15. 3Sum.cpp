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
        - Sort the array
        - Store one element and find the other two elements using two pointers.
        - Move the left pointer to one step right if the sum is less than zero.
        - Move the right pointer to one step left if the sum is greater than zero.
        - If the sum is equal to zero, store the triplet and move both pointers to
            avoid duplicates.
        - Repeat the process for all elements in the array.
        - Return the result vector.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        vector<vector<int>> res;
        vector<int> temp;

        for(int i = 0; i < size; i++) {
            if (nums[i] > 0)
                break;
            else
                if (i > 0 && (nums[i] == nums[i-1]))
                    continue;

            int l = i + 1, r = size - 1;

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
