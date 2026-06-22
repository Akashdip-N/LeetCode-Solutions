/*
    https://leetcode.com/problems/unique-binary-search-trees
*/
/*
    Solution Approach:- Using Dynamic Programming

    Time Complexity:- O(N^2)
    Space Complexity:- O(N)
    N:- Number of nodes in the tree

    Explanation:-
        - So since we have to return the number of unique binary search trees,
            we can use dynamic programming to solve this problem.
        - So for every value, we would have two sides of the tree, left and right.
        - So first we are going to count the number of unique trees in left and then right
            then we will multiply the two values and add it to the total number of unique trees.
        - We will do this for every value in the tree and return the total number of unique trees.
*/
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;

        unordered_map<int, int> m;
        m[0] = 1;
        m[1] = 1;

        for(int node = 2; node < (n + 1); node++){
            int total = 0;
            for(int root = 1; root < (node + 1); root++){
                int left = root - 1;
                int right = node - root;
                total += m[left] * m[right];
            }
            m[node] = total;
        }

        return m[n];
    }
};
