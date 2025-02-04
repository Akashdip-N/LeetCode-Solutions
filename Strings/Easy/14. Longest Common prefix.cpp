/*
    https://leetcode.com/problems/longest-common-prefix/
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a;
        bool ch = false;
        int n = strs.size();
        sort(strs.begin() ,strs.begin() + n);
        int size = strs.size();
        for (int i = 0; i < strs[1].size(); i++)
        {
            for (int j = 1; i < size; j++)
                if (strs[1][i] == strs[j][i]) // I was having an error of segmenatation 
                    ch = true; 
                else
                    ch = false;

            if(ch)
                a.push_back(strs[1][i]);
            else
                break;
        }

        return a;
    }
};

/*-----------------------------------------------------------------------------
            SOLUTION ON THE INTERNET
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i, j, n = strs.size();
        if (n == 0) return "";
        sort(strs.begin() ,strs.begin() + n);
        for (j = 0; j < strs[0].size() && j < strs[n - 1].size() && strs[0][j] == strs[n - 1][j]; j++);
        return strs[0].substr(0, j);
    }
};
