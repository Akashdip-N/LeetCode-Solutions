/*
    https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
*/
/*
    Solution Approach:- Using two pointers.

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input string

    Explanation:
        - If the two strings are equal, return true.
        - Create a vector to store the positions of the characters
            that are different in the two strings.
        - If the size of the vector is greater than 2, return false.
        - If the size of the vector is 2,
            check if swapping the characters at those positions makes the strings equal.
        - If the size of the vector is 0, return true.
        - Otherwise, return false.
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;

        vector<int> pos;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(pos.size() > 2)
                    return false;
                else
                    pos.push_back(i);
            }
        }

        if(pos.size() == 2)
            return (s1[pos[0]] == s2[pos[1]] && s2[pos[0]] == s1[pos[1]]);

        return (pos.size() == 0);
    }
};
