/*
    https://leetcode.com/problems/longest-common-prefix/
*/
/*
    Solution approach:- Using String Comparison

    Time complexity:- O(N*M)
    Space Complexity:- O(M)
    N = number of strings
    M = lenght of the first string

    Intuition:-
        - We have to find the longest common prefix string amongst the array of strings.
        - We would perform character comparison for all the characters of the first string
            with the rest of the strings present in the string vector.
        - At the end we would return the longest common prefix string.

    Explanation:-
        * Running the loop from the 0th index till the end of the first string.
        * For each character of the first string, we would check if it is equal to the
            character at the same index of the rest of the strings.
        * If it is equal, we would add the character to the prefix string.
        * If it is not equal, we would return the prefix string.

        Ex:-
            input = ["flower","flow","flight"]
            output = "fl"

            Iteration 1:-
                i = 0
                check = 'f'
                j = 1
                    check == strs[1][0] => 'f' == 'f' => true
                j = 2
                    check == strs[2][0] => 'f' == 'f' => true
                prefix += check => prefix = "f"

            Iteration 2:-
                i = 1
                check = 'l'
                j = 1
                    check == strs[1][1] => 'l' == 'l' => true
                j = 2
                    check == strs[2][1] => 'l' == 'l' => true
                prefix += check => prefix = "fl"

            Iteration 3:-
                i = 2
                check = 'o'
                j = 1
                    check == strs[1][2] => 'o' == 'o' => true
                j = 2
                    check == strs[2][2] => 'o' == 'i' => false
                return prefix => "fl"
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for(int i = 0; i < strs[0].size(); i++){
            char ch = strs[0][i];

            for(int j = 1; j < strs.size(); j++)
                if(ch != strs[j][i])
                    return prefix;

            prefix += ch;
        }

        return prefix;
    }
};
