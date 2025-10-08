/*
    https://leetcode.com/problems/candy
*/
/*
    Solution Approach: Two Passes

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = length of the input array

    Explanation:
        - First we need to traverse the ratings array from both the left and right sides,
            because we need to ensure that each child has more candies than their neighbors
                if they have a higher rating.
        - We create a vector `vec` initialized with 1 candy for each child.
        - In the first pass (left to right), we check
            if the current child's rating is greater than the previous child's rating.
                If it is, we give the current child one more candy than the previous child.
        - In the second pass (right to left), we start from the 2nd last element and check
            if the current child's rating is greater than the next child's rating.
                If it is, we ensure that the current child has
                    more candies than the next child by taking the maximum of its current
                        candy count and one more than the next child's candy count.
        - Finally, we sum up the candies in the `vec` to get the total number of candies needed.
        - Return the total count.
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int choco = 0;
        int size = ratings.size();
        vector<int> vec(size, 1);

        // Left to Right Pass
        for(int i = 1; i < size; i++){
            if(ratings[i] > ratings[i - 1])
                vec[i] = vec[i - 1] + 1;
        }

        // Right to Left Pass
        for(int i = size - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                vec[i] = max(vec[i], vec[i + 1] + 1);
        }

        // Summing up the total candies
        for(int v : vec)
            choco += v;

        return choco;
    }
};
