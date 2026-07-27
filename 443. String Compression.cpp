/*
    https://leetcode.com/problems/string-compression/
*/
/*
    Solution Approach:- Using two pointer

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of elements in the array

    Intuition:
        - First we need to find the count of each consecutive character in the array.
        - And if the count of the character is greater than 1, we need to store the count in the array
            else we just store the character in the array.
        - We need to return the length of the compressed array.
        - Since the question says that the output would be considered till the length of the array that is passed,
            we have to update the array in place and return the length of the compressed array.
        - WE DO NOT HAVE TO REMOVE THE EXTRA ELEMENTS FROM THE ARRAY, JUST RETURN THE LENGTH OF THE COMPRESSED ARRAY.

    Explanation:
        * Using two pointers to keep track of the current character and its count.
        * When we find a new character, first we store the current character in the array
            and then check if the count is greater than 1.
        * If the count is greater than 1,
            we convert the count to string and store each digit of the count in the array.
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            chars[write++] = currentChar;

            if (count > 1) {
                string countStr = to_string(count);

                for (char digit : countStr)
                    chars[write++] = digit;
            }
        }

        return write;
    }
};
