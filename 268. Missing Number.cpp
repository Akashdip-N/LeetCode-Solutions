/*
    https://leetcode.com/problems/missing-number/
*/
/*
    Solution Approach:- Using Sum Formula

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:-
        - We store the sum of all the elements from 0 to n in a variable `sum`.
        - We then subtract each element in the array from `sum`.
        - The final value of `sum` will be the missing number.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;

        for(auto i : nums)
            sum -= i;

        return sum;
    }
};

/********************************************************************************/
/*
    Solution Approach:- Using XOR

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:-
        - We use the XOR operation to find the missing number.
        - We XOR all numbers from 0 to n and also XOR all elements in the array.
        - The result will be the missing number
            since XORing a number with itself cancels it out.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int xorSum = 0;

        for(int i = 0; i <= size; i++)
            xorSum ^= i;

        for(auto num : nums)
            xorSum ^= num;

        return xorSum;
    }
};

/********************************************************************************/
/*
    Solution Approach:- Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the array

    Explanation:-
        - We use a hash map to store the presence of each number in the array.
        - We then iterate from 0 to n and check if each number is present in the hash map.
        - If a number is not found, we return it as the missing number.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> numSet;

        for(int num: nums)
            numSet[num] = true;

        for(int i = 0; i <= nums.size(); i++) {
            if(numSet.find(i) == numSet.end())
                return i;
        }

        return -1;
    }
};

/********************************************************************************/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(n log n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:-
        - First sorting the array.
        - Iterating through the sorted array and
            checking if the current index matches the value at that index.
        - If it doesn't match, we return the index as the missing number.
        - Outside the loop, we return the size of the array as the missing number
            if all indices matched their values.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for(int i = 0; i < size; i++)
            if(nums[i] != i)
                return i;

        return size;
    }
};
