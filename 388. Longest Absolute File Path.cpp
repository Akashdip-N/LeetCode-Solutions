/*
    https://leetcode.com/problems/longest-absolute-file-path
*/
/*
    Solution Approach:- Using String Stream and Hash Map

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Explanation:-
        * Using the string stream to split each string by '\n' and
            get the depth of the current file or directory by counting the number of '\t'.
        * Then, using the 'find_last_of()' function to get
                the last position of '\t' in the string.
            i.e. input string = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"

            then first it would fetch "dir"
            which has no '\t' so the depth is 0

            then it would fetch "\tsubdir1"
            which has 1 '\t' so the depth is 1
        * Then, using the substr function to get the string
            excluding any special characters like '\t' or '\n'.
        * In the substr function, the variable 'namePos' is used
            to determine the starting position of the string to be extracted.
        * Then we check if the string contains '.' or not,
            if it does, that means it's a file,
                then we calculate the length of the absolute path and store it.
        * Else using the hash map and using the depth as a key,
            we store the sum of the size of the current directory
                and the size of the previous directory
                    and add 1 for the '/' character.
        * Finally, we return the longest length of the absolute path.
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        int longest = 0;
        unordered_map<int, int> pathMap;
        pathMap[0] = 0;

        istringstream ss(input);
        string line;

        stack<string> s;

        // This will fetch each line from the input string, split by '\n'
        while (getline(ss, line)) {
            // Returns the last position of '\t' in the string
            auto namePos = line.find_last_of('\t') + 1;
            int depth = namePos;
            string name = line.substr(namePos);
            int size = name.size();

            if (name.find('.') != string::npos)
                longest = max(longest, pathMap[depth] + size);
            else
                pathMap[depth + 1] = pathMap[depth] + size + 1;
        }

        return longest;
    }
};

/******************************************************************************************/
/*
    Solution Approach:- Using Stack

    Time Complexity:  O(N)
    Space Complexity: O(N)
    N = length of the string

    Explanation:-
        * Same as previous solution, fetching individual strings.
        * Checking if the depth of the current string is less than the size of the stack,
            then we pop the stack until we reach the parent directory.
        * Then we calculate the length of the current string and push it onto the stack.
        * If the current string is a file, we calculate the length of the absolute path
            and update the maximum length if it's greater than the previous maximum length.
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        st.push(0);
        int maxLen = 0;

        istringstream ss(input);
        string s;

        while (getline(ss, s)) {
            size_t lastTab = s.find_last_of('\t') + 1;
            int level = lastTab;

            // Pop the stack until we reach the parent directory
            while (level < (st.size() - 1))
                st.pop();

            int len = st.top() + (s.size() - level) + 1;
            st.push(len);

            if (s.find('.') != string::npos)
                maxLen = max(maxLen, len - 1);
        }

        return maxLen;
    }
};
