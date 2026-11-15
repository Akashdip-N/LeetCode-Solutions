/*
    https://leetcode.com/problems/reconstruct-original-digits-from-english/
*/
/*
    Solution Approach:- Using HashMap and logic

    Time Complexity: O(N)
    Space Complexity: O(1) (Since the size of the hashmap is constant)
    N = Length of the string s

    Problem Statement:-
        - Given us a string s that contains an out-of-order English representation of digits 0-9.
        - We have to fetch the digits and return them in ascending order in a string format.

    Intuition:-
        - Since we don't have the information about which digits is present in the string,
            using a frequency array to count and store the frequency of each character in the string.
        - Then storing the frequency of each digit in a count array using the frequency array,
            so that the resulting string will be constructed in ascending order.
        - Then we can construct the result string using the count array.

    Explanation:-
        * Creating two vectors, one for storing the frequency of each character of the string.
        * Other for storing the frequency of each digit.
        * Iterating through the string and storing the frequency of each character
            in the frequency vector.

        * Since the starting of the following digits have unique characters,
            we can find the frequency of those digits using the frequency vector.
            i. 'z' is unique to 0
            ii. 'w' is unique to 2
            iii. 'u' is unique to 4
            iv. 'x' is unique to 6
            v. 'g' is unique to 8
        * Now finding and storing the frequency of the characters which appears twice in the word list:-
            i. 'h' appears in both 3 and 8,
                since we have already found the frequency of 8,
                    we can subtract it from the frequency of 'h' to get the frequency of 3.
            ii. 'f' appears in both 4 and 5,
                since we have already found the frequency of 4,
                    we can subtract it from the frequency of 'f' to get the frequency of 5.
            iii. 's' appears in both 6 and 7,
                since we have already found the frequency of 6,
                    we can subtract it from the frequency of 's' to get the frequency of 7.
        * Now finding and storing the frequency of the characters which
            appears thrice in the word list:-

            i. 'o' appears in 0, 1, 2 and 4,
                since we have already found the frequency of 0, 2 and 4,
                    we can subtract it from the frequency of 'o' to get the frequency of 1.
            ii. 'i' appears in 5, 6, 8 and 9,
                since we have already found the frequency of 5, 6 and 8,
                    we can subtract it from the frequency of 'i' to get the frequency of 9.
        * Now we can construct the result string using the count array,
            by appending the digit to the result string count[i] times.
*/
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        count[0] = freq['z' - 'a'];
        count[2] = freq['w' - 'a'];
        count[4] = freq['u' - 'a'];
        count[6] = freq['x' - 'a'];
        count[8] = freq['g' - 'a'];

        count[3] = freq['h' - 'a'] - count[8];
        count[5] = freq['f' - 'a'] - count[4];
        count[7] = freq['s' - 'a'] - count[6];

        count[1] = freq['o' - 'a'] - count[0] - count[2] - count[4];
        count[9] = freq['i' - 'a'] - count[5] - count[6] - count[8];

        string result = "";
        for (int i = 0; i <= 9; i++)
            result.append(count[i], '0' + i);

        return result;
    }
};
