/*
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = haystack.size(), b = needle.size();

        if(a == 0)
            return 0;
        
        size_t found = haystack.find(needle);
        if(found != string::npos)
            return found;
        return (-1);
    }
};