/*
    https://leetcode.com/problems/longest-common-prefix/

    Approach:-
    * We will check with for all the characters in the first string, to the other strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for(int i = 0; i < strs[0].length(); i++){
            char check = strs[0][i];

            for(int j = 1; j < strs.size(); j++) // comparing with other strings
                if(check != strs[j][i])          // Comparing the character
                    return prefix;

            prefix += check; // Add the character to the prefix
        }
        return prefix;
    }
};
