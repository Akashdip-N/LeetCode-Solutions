/*
    https://leetcode.com/problems/longest-absolute-file-path
*/
/*
    Solution Approach:- Using String Stream and Hash Map

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Intuition:-
        - Given a string input representing the file system paths.
        - The path is have several directories and sub-directories, and files.
        - From the root the directories are seperated using '\n\t'.
        - Each sub-directories are sperated using '\n\t\t'.
        - We have to find the longest absolute path from the directory to the file.

        Ex:-
            input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"

            visual representation of the input string is as follows:-
                dir
                 |---subdir1
                 |---subdir2
                        |----file.ext

            output = 20 = "dir/subdir2/file.ext"

        - For this we can using the concept of string stream,
            and hashmap to store the length of the absolute path based on
                the depth of the current directory or file.
        - Based on each '\t' we can calculate the depth of the current directory or file.

        Ex:-
            input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"

            depth[0] = 0
            depth[1] = 4 = "dir/"
            depth[2] = 12 = "dir/subdir2/"
            depth[3] = 20 = "dir/subdir2/file.ext"

    Explanation:-
        * Iterating over each new line separated string using string stream.
        * Then we find the last occurrence of '\t' using find_last_of() function.
            Ex:-
                string = "dir",
                find_last_of('\t') will return -1, because no '\t' is present in the string.

                string = "\tsubdir1",
                find_last_of('\t') will return 0, because '\t' is present at index 0.

                string = "\t\tfile.ext",
                find_last_of('\t') will return 1, because '\t' is present at index 1.

        * Then we find the word from the last occurrence of '\t' till the end of the string.
        * Then we check if the current string is a file or not
            by checking if the string contains a '.' character.
        * If it's a file, then we store the maximum
            between the current maximum length and
                the sum of the current depth length and the length of the current string.
        * If it's a directory, then we store the sum of the current depth length and
            the length of the current string + 1 (for the '/' character) in the hashmap.
        * At the end we return the maximum length of the absolute path to the file.
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

        while (getline(ss, line)) {
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
