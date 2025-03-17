/*
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/
/*
    Solution Approach: Two Pointers, String Comparison

    * Storing the size of both the strings
    * Using a for loop iterate over the main string
    * Using inner while loop to compare the character of the main string,
        with the other string.
    * Running the inner while loop until,
        the count of other string is less than the size of the main string.
    * Returning the starting index of the first occurrence,
        of the needle string if and only if the count of,
            the occurance of the needle string is equal to the size of the needle string.
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
