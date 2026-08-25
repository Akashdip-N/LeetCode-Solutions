/*
    https://leetcode.com/problems/reverse-words-in-a-string/
*/
/*
    Solution Approach: Using Two Pointers

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input string

    Intuition:-
        - We have to reserve the occurance of the words in the string.
        - We would use the two pointers concept to find the words in the string and
            store them in the result string in reverse order.
        - We would also trim the leading and trailing spaces from the string.
        - At the end we would return the result string
            containing the reversed words in the string.

    Explanation:
        * Creating an empty string which would store the reversed words in the string.
        * Using two pointersm and initializing the left to 0 and right to size - 1.
        * Trimming the leading spaces from both the left and right side of the string.
        * While the left pointer and right pointer does not cross each other,
            we perform the following steps:
            i. Storing the right pointer into a variable,
                    that would be used as a start of the last word in the string.
            ii. Finding the white space from the right side of the string,
                    decrementing the right pointer.
            iii. Storing the substring from the right pointer (i.e. the end variable)
                    till the right pointer into the result string and adding a space after it.
            iv. Updating the right pointer to the end variable - 1.
            v. Trimming the leading spaces from the right side of the string.
        * Finally, we check if the result string is not empty and
            the last character of the result string is a space,
                we pop the last character from the result string.
        * Then we return the result string which contains the reversed words in the string.
*/
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int size = s.size();
        int left = 0, right = size - 1;

        while(left < size && s[left] == ' ')
            left++;

        while(right >= 0 && s[right] == ' ')
            right--;

        while(left <= right) {
            int end = right;

            while(end >= left && s[end] != ' ')
                end--;

            result += s.substr(end + 1, right - end) + ' ';

            right = end - 1;

            while(right >= left && s[right] == ' ')
                right--;
        }

        if(!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};
