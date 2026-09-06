/*
    https://leetcode.com/problems/shifting-letters-ii/
*/
/*
    Solution Approach:- Using Prefix Sum Technique

    Time Complexity:- O(N + M)
    Space Complexity:- O(N)
    N = length of the string s
    M = length of the shifts array

    Intuition:-
        - We have been given a string s, and an array of shifts.
        - Each shifts has the following three values:-
            i. Start index
            ii. End index
            iii. Direction of shift (1 for right, 0 for left)
        - We have to shift the characters in the string s according to the shifts array.
        - And then return the final string s after all the shifts have been applied.
        Example:-
            s = "abc"
            shifts = [[0, 1, 0], [1, 2, 1], [0, 2, 1]]

            Iteration 1:
                S = "abc"
                Shift 1: [0, 1, 0] => Shift left from index 0 to 1 => "ab" => "zbc"
                Shift 2: [1, 2, 1] => Shift right from index 1 to 2 => "bc" => "zcd"
                Shift 3: [0, 2, 1] => Shift right from index 0 to 2 => "zcd" => "ade"
            Final Output: "ade"

        - Using Prefix sum to store the net shift for each index in the string s.
            (
                The implementation is similar to Pr. 1094 Car Pooling
                    https://leetcode.com/problems/car-pooling/

                where we have to find the net change in the number of passengers at each index.
            )
        - Then converting the characters in the string s according to the net shift for each index.
            (
                The implementation is similar to Pr. 848 Shifting Letters
                    https://leetcode.com/problems/shifting-letters/
            )
        - And returning the final string s after all the shifts have been applied.

    Explanation:-
        * Creating a difference array of size (size of string s + 1)
            to store the net shift for each index in the string s.
        * Iterating through each shifts and updating the start and end index by
            adding the shift value to the start index and
                subtracting the shift value from the end index + 1.
            (
                Because the shifts would be applied from the start index till the end index,
                so (index + 1) would be the index where the shift would stop being applied.
            )
        * Then iterating through the difference array and
            calculating the net shift for each index in the string s.
        * Then converting the characters in the string s according to the net shift for each index.
        * And returning the final string s after all the shifts have been applied.
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size = s.size();

        vector<int> diff(size + 1, 0);

        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int val = (shift[2] == 1) ? 1 : -1;

            diff[start] += val;
            diff[end + 1] -= val;
        }

        int currentShift = 0;
        for (int i = 0; i < size; i++) {
            currentShift += diff[i];

            int netShift = ((currentShift % 26) + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};
