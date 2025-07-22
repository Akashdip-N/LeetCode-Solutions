/*
    https://leetcode.com/problems/assign-cookies
*/
/*
    Solution Approach: Greedy Method

    Time Complexity: min( O(n log n), O(m log m) )
    Space Complexity: O(1)
        n = number of children,
        m = number of cookies

    Explanation:
        - Sort the arrays of children and cookies.
        - Use a greedy approach to assign cookies to children.
        - Iterate through the cookies and
            assign them to the children if the cookie size is
                greater than or equal to the child's greed factor.
        - Count how many children can be satisfied with the cookies.
        - Return the count of satisfied children.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sizeS = s.size();
        int sizeG = g.size();

        if (sizeS == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;

        for (int i = 0; (i < sizeS) && (child < sizeG); i++) {
            if (s[i] >= g[child])
                ++child;
        }

        return child;
    }
};
