/*
    https://leetcode.com/problems/koko-eating-bananas
*/
/*
    Solution Approach:- Binary Search

    Time Complexity:- O(N * logM)
    Space Complexity:- O(1)
    N = number of piles
    M = maximum number of bananas in a pile

    Explanation:-
        * We have to find the min number of bananas that koko can eat in an hour
            to finish all the bananas in h hours.
        * We would find the min and max number of bananas in a pile.
        * Then based on the range of min and max number of bananas in a pile,
            we would do a binary search.
        * In this process we would find how much time does it takes
            to finish all the bananas based on the number of bananas koko can eat in an hour.
        * If the time taken is less than or equal to h,
            then we would update the value of the minimum number of bananas
                that koko would be able to eat in an hour.
        * And also update our right pointer to k - 1,
            because we want to find the minimum number of bananas koko can eat in an hour.
        * If the time taken is more than h,
            then we would update our left pointer to k + 1,
                because we want to find the minimum number of bananas koko can eat in an hour.
        * At the end we would return the minimum number of bananas koko can eat in an hour.
*/
class Solution {
public:
    long long int minVal(vector<int>& piles, int k){
        long long int hours = 0;

        for(int i = 0; i < piles.size(); i++)
            hours += (piles[i] + k - 1) / k;

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        for(int i = 0; i < piles.size(); i++)
            right = max(piles[i], right);

        int left = 1;
        int min_val = right;

        while(left <= right){
            int k = (left + right)/2;
            long long int hours = minVal(piles, k);

            if(hours <= h){
                min_val = min(min_val, k);
                right = k - 1;
            }
            else if(hours > h)
                left = k + 1;
        }

        return min_val;
    }
};
