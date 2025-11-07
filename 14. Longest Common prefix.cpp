/*
    https://leetcode.com/problems/longest-common-prefix/
*/
/*
    Solution approach:- string comparison

    Time complexity:- O(N*M)
    Space Complexity:- O(M)
    N = number of strings
    M = lenght of the first string

    Explanation:-
        * Run the for loop for the entire string length for the first string.
        * Compare the characters of the characters of the first string with 
            other string present in the string vector.
        * If the characters don't match we return the max current prefix string,
            else we add the current character to the prefix string to be returned.
        * Return the frefix string.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for(int i = 0; i < strs[0].length(); i++){
            char check = strs[0][i];

            for(int j = 1; j < strs.size(); j++)
                if(check != strs[j][i])
                    return prefix;

            prefix += check;
        }
        return prefix;
    }
};
