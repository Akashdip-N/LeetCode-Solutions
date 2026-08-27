/*
    https://leetcode.com/problems/integer-to-english-words/
*/
/*
    Solution Approach:- Using Recursion & Vector

    Time Complexity: O(1) (At Max it will perform 4 iterations)
    Space Complexity: O(1) (Not using any extra space except for the result string)

    Intuition:-
        - We have been given a number and we have to convert it into words.
        - We can divide the number into groups of 3 digits and convert each group into words.
        - Storing the word value for each group in a vector,
            for faster retrieval of the word value instead of using hashmap or unordered map.
        - We can use recursion to convert each group into words.
        - At the end we can combine the words of each group and return the final result.

    Explanation:-
        * Using vector to store the words for numbers from 1 to 19, tens and thousands.

        Main function:-
            * Base case: If the number is 0, return "Zero".
            * Creating an empty string to store the result,
                and using a variable to keep track of the thousands place.
            * While the number is not 0,
                - We check if the last 3 digits of the number are not 0,
                    then we call the helper function
                        with the last 3 digits and the corresponding thousands place,
                            and add the old result string in the back,
                                and store the new result in the result string.
                - We divide the number by 1000 to remove the last 3 digits,
                    and increment the thousands place variable.
            * Finally, we remove any trailing spaces from the result string and return it.

        Helper function:-
            * Taking input the number.
            * Base case: If the number is 0, return an empty string.
            * If the number is less than 20,
                then we search for the corresponding word in the ones vector
                    and return it.
            * If the number is between 20 and 99,
                then we search the corresponding last digit from the ones vector,
                    and call the same function with
                        the remaining number after removing the last digit.
            * If the number is greater than or equal to 100,
                then we search for the corresponding word
                    for the first digit from the ones vector,
                        and call the same function with
                            the remaining number after removing the first digit.
*/
class Solution {
    private:
        vector<string> ones = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
            "Seventeen", "Eighteen", "Nineteen"
        };

        vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string helper(int num) {
            if (num == 0)
                return "";
            else if (num < 20)
                return ones[num] + " ";
            else if (num < 100)
                return tens[num / 10] + " " + helper(num % 10);
            else
                return ones[num / 100] + " Hundred " + helper(num % 100);
        }

    public:
        string numberToWords(int num) {
            if (num == 0)
                return "Zero";

            string result = "";
            int i = 0;

            while (num > 0) {
                int lastThreeDigits = num % 1000;

                if (lastThreeDigits != 0)
                    result = helper(lastThreeDigits) + thousands[i] + " " + result;

                num /= 1000;
                i++;
            }

            while (!result.empty() && result.back() == ' ')
                result.pop_back();

            return result;
        }
};
