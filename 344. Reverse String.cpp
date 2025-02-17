/*
    https://leetcode.com/problems/reverse-string/
*/
/*
                    TWO POINTER TECHNIQUE

    Solution Approach:
    * We are using two pointers l and r.
    * We are swapping the characters at the l and r indexes.
    * We are incrementing l and decrementing r.
    * We are doing this until l is less than r.
*/
class Solution {
public:
    void reverseString(vector<char>& str) {
        int l = 0, r = str.size()-1;

        while(l < r){
            swap(str[l], str[r]);
            l++;
            r--;
        }
    }
};
