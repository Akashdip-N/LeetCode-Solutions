/*
    https://leetcode.com/problems/add-binary/
*/
/*
    Solution Approach:- String Manipulation

    Time Complexity:- O(max(N, M))
    Space Complexity:- O(max(N, M))
    N = length of string a
    M = length of string b

    Intuition:-
        - We have to add the two strings which has 0s and 1s only.
        - Since we add from the last value, we are reversing both the strings.
        - We are iterating through the strings
            and adding the values of the strings and the carry.
        - At the end, we are reversing the result string and returning it.

    Explanation:-
        * Reversing both the strings to add from the last value.
        * Storing the maximum size of the two strings in a variable,
            since we have to iterate through the maximum size of the two strings.
        * Initializing the carry variable to 0.
        * Iterating through the maximum size of the two strings.
            - If the index is less than the size of the string,
                we are getting the value of the string at that index and
                    converting it to integer.
            - If the index is greater than
                the size of the string, we are assigning the value to 0.
            - Adding the values of the two strings and the carry.
            - Storing the result of the addition in the result string.
            - Updating the carry variable to the value of the addition divided by 2.
        * At the end, if there is a carry value,
            we are adding it in the front of the result string.
        * Reversing the result string and returning it.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;

        int size = max(a.size(), b.size());
        int carry = 0;

        for(int i = 0; i < size; i++){
            int vala = (i < a.size()) ? a[i] - '0' : 0;
            int valb = (i < b.size()) ? b[i] - '0' : 0;

            int total = vala + valb + carry;
            res += (total % 2) + '0';
            carry = total / 2;
        }

        if(carry)
            res += '1';

        reverse(res.begin(), res.end());
        return res;
    }
};

/***********************************************************************************/
/*
    Solution Approach:- Using math

    Time Complexity:- O(max(N, M))
    Space Complexity:- O(max(N, M))
    N = length of string a
    M = length of string b

    Intuition:-
        - Same as the above approach, but we are not reversing the strings.
        - We would iterate from the end till the start of the strings and
            add the values of the strings and the carry.
        - At the end, we are reversing the result string and returning it.
            Since we are adding the values from the end, we have to reverse the result string.

    Explanation:-
        * Initializing the i and j pointers to the end of the strings a and b respectively.
        * Initializing the carry variable to 0.
        * Iterating through the strings while i and j are greater than or equal to 0
            or the carry is greater than 0.
            (that means there is value present either in the string or as a carry)
        * Checking the following conditions and performing the operations accordingly:
            i. If i is greater than or equal to 0,
                (that means there is value present for string a)
                we are adding the integer value of the string to the sum variable
                and decrementing the i pointer.
            ii. If j is greater than or equal to 0,
                (that means there is value present for string b)
                we are adding the integer value of the string to the sum variable
                and decrementing the j pointer.
            iii. Finding the binary value of the sum converting it into character
                and adding it to the result string.
            iv. Updating the carry variable to the value of the sum divided by 2.
        * At the end, we are reversing the result string and returning it.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            res += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
