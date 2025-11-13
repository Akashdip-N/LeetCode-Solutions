/*
    https://leetcode.com/problems/isomorphic-strings
*/
/*
    Solution Approach:- Using Two HashMaps

    Time Complexity: O(N)
    Space Complexity: O(1) (Since the character set is fixed)
    N = length of the input strings

    Explanation:
        * Check if the lengths of the two strings are equal.
            If not, they cannot be isomorphic.
        (not required as per problem constraints)
        * Using two HashMaps to store the character mappings from s to t and t to s.
        * Iterate through the characters of both strings simultaneously.
        * For each character pair (c1 from s and c2 from t):
            - If c1 is already mapped to a different character than c2 in the first map,
                return false.
            - If c2 is already mapped to a different character than c1 in the second map,
                return false.
            - Otherwise, add the mapping c1 -> c2 in the first map and
                c2 -> c1 in the second map.
        * If we complete the iteration without conflicts, return true.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> m1, m2;

        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i], c2 = t[i];

            if (m1.count(c1) && m1[c1] != c2)
                return false;

            if (m2.count(c2) && m2[c2] != c1)
                return false;

            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
};
