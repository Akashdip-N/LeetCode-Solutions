/*
    https://leetcode.com/problems/simplify-path/
*/
/*
    Solution Approach:- Using Stringstream and Stack

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the input path

    Intuition:-
        - We have been given a directory path, and we need to simplify it and return it.
        - The following are the rules for simplifying the path:
            i. A single dot (.) refers to the current directory,
                so we can ignore it and move on to the next part of the path.
            ii. A double dot (..) refers to the previous/parent directory,
                so we need to go up one level in the directory structure.
            iii. If anything else occurs such as "..." or "....",
                we treat it as invalid and ignore it.

            Ex:-
                input path:- "/home/../usr/./bin/../lib"
                output path:- "/usr/lib"

        - Using stack to keep track of the directories we encounter as we parse the input path.
        - At the end pop the directories from the stack and construct the simplified path.

    Explanation:-
        * Initializing string stream with the input path,
            to split each part of the path using the '/' delimiter.
        * Continuing to read each part of the path until no more '/' are left,
            and perform the following checks:
                - If the current part is empty or a single dot (.),
                    we ignore it and move on to the next part of the path.
                - If the current part is a double dot (..),
                    then check if the stack is not empty,
                        then we pop the top directory from the stack,
                            which represents the most recent directory we encountered.
                - Else we push the current part onto the stack,
                    which represents a valid directory we encountered.
        * Then we construct the simplified path by popping the directories from the stack,
            and joining them with a '/' delimiter to the result string.
        * If the current result string is empty,
            then we return a single forward slash (/), which represents the root directory
            else we return the constructed result string as the simplified path.
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".")
                continue;
            else if (token == "..") {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(token);
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
