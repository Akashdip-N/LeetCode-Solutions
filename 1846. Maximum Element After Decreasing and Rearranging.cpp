/*
    https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
*/
/*
    Solution Approach:- Using HashMap (Using vector as HashMap) (Editorial Solution)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the array

    Intuition:-
        * We have to make sure that the first element in the array is always 1.
        * So ideally the elements should look something like this,
            [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        * That means the maximum element in the array should
            be at most the length of the array
        * Hence we are storing the frequency of each element in a vector of (size + 1)
            because we want to store the frequency of the element
                at the index equal to the element itself.

    Explanation:-
        * Creating a fixed size vector of n+1
        * Incrementing the frequency of each element in the vector.
        * Iterating over each element of the vector,
            and for each element, we take the minimum of (prev + 1) and the current element,
                and store it in the variable ans.
        * Finally, returning the maximum element after decrementing and rearranging.

    Example:-
        Arr = [100, 1, 1000, 1000]
        Size = 4
        Counts = [0, 1, 0, 0, 2]
        Ans = 1

        Iterating over the counts vector,
        i. i = 2
            ans = min(ans + counts[2], 2) = min(1 + 0, 2) = 1
        ii. i = 3
            ans = min(ans + counts[3], 3) = min(1 + 0, 3) = 1
        iii. i = 4
            ans = min(ans + counts[4], 4) = min(1 + 2, 4) = 3

        Finally, returning ans = 3
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size = arr.size();
        vector<int> counts(size + 1, 0);

        for (int ele : arr)
            counts[min(ele, size)]++;

        int ans = 1;
        for (int i = 2; i <= size; i++)
            ans = min(ans + counts[i], i);

        return ans;
    }
};

/*****************************************************************************************************/
/*
    Solution Approach:- Using sorting and greedy approach.

    Time Complexity: O(NlogN) (since sorting takes O(NlogN) time)
    Space Complexity: O(1)
    N = length of the array

    Intuition:-
        * We have to make sure that the first element is always 1,
            hence first we sort the element so that elements are in increasing order.
        * Also we have to make sure that the difference between any two adjacent elements
            is at most 1, hence using greedy approach to make sure that we have the right element.

    Explanation:-
        * Sort the array in increasing order.
        * Initialize a variable prev to 0,
            by doing this we are making sure that the first element is always 1.
        * Iterate over each element of the array,
            and for each element, we take the minimum of (prev + 1) and the current element.
        * This way we are making sure that the difference between any two adjacent elements is at most 1.
        * Finally, return the value of prev which will be the maximum element
            after decrementing and rearranging the array.
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prev = 0;

        for(int ele : arr)
            prev = min(prev + 1, ele);

        return prev;
    }
};
