/*
    https://leetcode.com/problems/shifting-letters/
*/
/*
    Solution Approach:- Using Prefix Sum

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the string s or shifts array

    Intuition:-
        - Given us a string s and an integer array shifts of the same length.
        - For each shifts[i], we need to shift the first i + 1 letters of s, shifts[i] times.
            Ex:-
                s = "abc"
                shifts = [3, 5, 9]
                - For shifts[0] = 3,
                    we shift the first 1 letter (i.e., 'a') 3 times,
                        resulting in "dbc".
                - For shifts[1] = 5,
                    we shift the first 2 letters (i.e., 'd' and 'b') 5 times,
                        resulting in "igc".
                - For shifts[2] = 9,
                    we shift the first 3 letters (i.e., 'i', 'g', and 'c') 9 times,
                        resulting in "rpl".
                - The final result is "rpl".
        - We have to create a function named 'shift()' that would take a character,
            and shift it by a given value, and return the shifted character.
        - We have to return the newly formed string after all the shifts have been applied.

        - We would find the shifts needed from the end of the string to the beginning,
            and keep a running sum of the shifts needed for each character.

    Explanation:-
        Base function 'shiftingLetters()' :-
            * Iterating from the end of the shifts array till the beginning,
                and we keep track of the total shifts needed for each character in the string.
            * For each character, we call the 'shift()' function to get the shifted character
                and update the character in the string.
            * Finally, we return the updated string after all shifts have been applied.

        Helper function 'shift()':-
            * This function takes the following as input parameters:
                - A character 'c' to be shifted.
                - A long long integer 'val' representing the number of shifts needed.
            * Using the formula ((val % 26) + 26) % 26, we calculate the effective shift value
                to ensure it is within the range of 0 to 25 (the number of letters in the alphabet).
                (
                    Explanation:-
                        val = -2
                        -2 % 26 = -2
                        (-2 + 26) % 26 = 24
                )
            * Subtracting char 'a' from the passed character,
                making the current character's position in the alphabet (0-25).
            * Adding the effective shift value to the current character's position,
                and taking modulo 26 to ensure it wraps around if it exceeds 'z'.
            * Finally, we add char 'a' back to the result to convert it back to a character and
                return the shifted character.
*/
class Solution {
public:
    char shift(char c, long long val) {
        int shiftval = ((val % 26) + 26) % 26;
        return 'a' + (c - 'a' + shiftval) % 26;
    }

    string shiftingLetters(string s, vector<int>& shifts) {
        int shiftSize = shifts.size();

        long long sum = 0;
        for (int i = shiftSize - 1; i >= 0; i--) {
            sum += shifts[i];
            s[i] = shift(s[i], sum);
        }

        return s;
    }
};
