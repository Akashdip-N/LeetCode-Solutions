/*
    https://leetcode.com/problems/find-the-k-th-character-in-string-game-i
*/
/*************************** MY OWN SOLUTION :) *************************/
/*
    Solution Approach: Using Recursion, using a helper function.

    Time Complexity: O(n*k),
        n = size of the string,
        k = the k-th character to find.

    Explanation:
        i. If the size of the string is greater than or equal to k,
            return the string.
        ii. Otherwise, for each character in the string,
                increment the character and append it to the string.
                    and recursively call the function with the new string and k.
*/
class Solution {
public:
    string fun(string s, int k) {
        if (s.size() >= k)
            return s;
        else {
            int originalSize = s.size();
            for (int i = 0; i < originalSize; i++) {
                char in = s[i];
                if(in == 'z')
                    in = 'a';
                else
                    in++;
                s += in;
            }

            return fun(s, k);
        }
    }

    char kthCharacter(int k) {
        string ret = fun("a", k);
        return ret[k-1];
    }
};

/*************** OTHER SOLUTION WITH BETTER TIME COMPLEXITY *****************/
/*
    Solution Approach: Using Recursion

    Time Complexity: O(log k),
        since we are halving the problem size at each step.

    Explanation:
        i.
*/
class Solution {
public:
    char kthCharacter(int k) {
        int len = 1;

        // Compute smallest power of 2 ≥ k
        while (len < k)
            len *= 2;


        return kthCharHelper(k, 'a', len);
    }

private:
    char kthCharHelper(int k, char start, int len) {
        // Base case, i.e. if the length is 1 return the string
        if (k == 1)
            return start;

        int mid = len / 2;

        if (k <= mid) {
            return kthCharHelper(k, start, mid);
        } else {
            char prev = kthCharHelper(k - mid, start, mid);
            return nextChar(prev);
        }
    }

    char nextChar(char c) {
        return (c == 'z') ? 'a' : c + 1;
    }
};
