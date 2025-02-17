/*
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/
/*
    Solution Approach:
    * We will run 2 loops, one for the haystack and one for the needle.
    * The outer loop will run for the length of the haystack.
    * The inner loop will run for the length of the needle.
    * The inner loop has been set the following conditions:-
        i. Counter variable (j) < size of the needle string.
        ii. Sum of the counter variable of,
            inner loop(j) and outer loop (i) is < size of haystack string.
        iii. The character of needle string is same as the haystack string.
    * We are keeping a variable to check if the inner loop has been
        exectued till the end of the needle string.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;

        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i < n; i++) {
            if(haystack[i] == needle[0]) {
                int j = 0;
                while(j < m && (i + j) < n && haystack[i+j] == needle[j])
                    j++;
                if(j == m)
                    return i;
            }
        }
        return -1;
    }
};
