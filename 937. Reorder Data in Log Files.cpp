/*
    https://leetcode.com/problems/reorder-data-in-log-files
*/
/*
    Solution Approach: Using Custom Sort Function

    Time Complexity: O(N * M * logN)
    Space Complexity: O(N)

    N = number of logs
    M = lenght of the logs

    Explanation:

        Main Function: reorderLogFiles
        -------------------------------
        * First seperate the logs into two different vectors,
            one for digit-logs and one for letter-logs.
        * Then using custom sort function sort the letter-logs
            according to the problem statement.
        * Finally concatenate the two vectors and return the result.
        * Returning the concatenated vector.

        Custom Sort Function: comp
        --------------------------
        * First we find the position of the first space in both strings.
        * Then we extract the content of the logs (excluding the identifier).
        * If the contents are the same, we compare the identifiers.
        * Otherwise, we compare the contents.
        * Return true if the first log should come before the second log, false otherwise.
*/
bool comp(string &a, string &b){
    int p1 = a.find(' ');
    int p2 = b.find(' ');

    string s1 = a.substr(p1+1);
    string s2 = b.substr(p2+1);

    if(s1 == s2)
        return  a < b;

    return s1 < s2;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        vector<string> letters;
        vector<string> ret;

        for (const auto& log : logs) {
            size_t pos = log.find(' ');

            // No space found
            if (pos == string::npos) continue;

            const string& content = log.substr(pos + 1);
            if (isdigit(content[0]))
                digits.push_back(log);
            else
                letters.push_back(log);
        }

        sort(letters.begin(), letters.end(), comp);
        for(string letter : letters)
            ret.push_back(letter);

        for(string digit : digits)
            ret.push_back(digit);

        return ret;
    }
};
