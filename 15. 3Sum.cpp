/*
    https://leetcode.com/problems/3sum/
*/
/*
    Problem:- We have to find all the unique triplets in the array which gives the sum of zero.

    Explantion:-
    * Sorting the array to get a proper sequence.
    * We are taking a loop from 0 to size of the array.
    * We are checking if the current element is greater than 0,
        that means all the elements are in increasing order,
            so we break the loop, as we can't get the sum as zero.

    * We are checking if the current element is same as the previous element,
        that means we have already checked the triplets for the current element,
            so we continue to the next element.

    * Setting pointer l to i+1 and r to (size of the array) - 1.
    * We are checking if the sum is zero,
        if yes, then we add the elements to the temp vector and
            add the temp vector to the result vector.
            we clear the temp vector, to store the next triplet.
        then we increment l and decrement r, to reduce the search space within the array.

        Then, we run a while loop to find the new distinct elements.
    * If the sum is less than zero,
        which means we need a smaller element, so we increment l.
    * If the sum is greater than zero,
        which means we need a larger element, so we decrement r.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) // edge case, where are the elements are in increasing order
                break;
            else if (i > 0 && (nums[i] == nums[i-1]))
                    continue;

            // we come to this part, when the current element is less than 0
            // and the current element is not same as the previous element
            int l = i + 1, r = nums.size() - 1;

            while(l < r) // to find a new triplets with the current element
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.clear();

                    l++;
                    r--;

                    while (l < r)  // To avoid duplicates
                        if (nums[l] == nums[l-1])
                            l++;
                        else if (nums[r] == nums[r+1])
                                r--;
                        else
                            break;
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
