/*
    https://leetcode.com/problems/encode-and-decode-strings (premium)

    https://neetcode.io/problems/string-encode-and-decode (neetcode)
*/
/*
    Solution Approach:- Length Prefixing

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = total number of characters in all strings combined

    Explanation:
        - We encode each string by prefixing it with its length followed by
            a special character (e.g., '#') and then the string itself.

            Example: "hello" becomes "5#hello".
            This means that it is a string of length 5 followed by the actual string.
        - During decoding,
            we read the length prefix to determine how many characters to extract
                for each string.
        - Then we convert the length prefix back to an integer and extract the corresponding substring.
        - This ensures that we can accurately reconstruct the original list of strings.
*/
class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& str : strs)
            res += to_string(str.size()) + "#" + str;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();

        while (i < n) {
            int j = i;
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            res.push_back(str);
            i = j + 1 + len;
        }

        return res;
    }
};
