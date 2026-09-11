/*
    https://leetcode.com/problems/unique-3-digit-even-numbers
*/
/*
    Solution Approach: Using Set to store the unique numbers

    Time Complexity: O(N^3)
    Space Complexity: O(1) (Since the maximum number of unique 3-digit even numbers is 900)
    N = number of digits in the input array

    Intuition:-
        - Given an array of digits.
        - We need to find the total number of unique 3-digit even numbers,
            that can be formed using the digits in the array.
        - We can't use the same index of the digits array more than once in a number.
        Ex:-
            digits = [0,2,2]
            output = 2
            The numbers that can be formed are 202 and 220.
        - We also can't use trailing zeros in the number.
        Ex:-
            digits = [0,0,2]
            output = 0
            The numbers that can be formed are 200 and 020, but both have trailing zeros

        - Using a set to store the unique numbers in order to avoid duplicates.
        - At the end return the size of the set which contains the unique 3-digit even numbers.

    Explanation:-
        * Creating a set to store the unique numbers.
        * Using three nested loops all iterating from index 0 till the size of the digits array.
        * In the first loop, we check if the current digit is 0,
            if it is, then we skip that iteration,
                since we can't use 0 as the first digit of a 3-digit number.
        * In both the second and the third loops,
            we make sure that the index of the 2nd loop and 3rd loop are unique
                and are not equal to the index of each other.
        * In the third loop, we check whether the current digit is even or not,
            if it's even that means we can use it as the last digit of the 3-digit number.
        * Then we form the 3-digit number using the digits and insert it into the set.
        * At the end, we return the size of the set which contains the unique 3-digit even numbers.
*/
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int size = digits.size();

        for (int i = 0; i < size; i++) {
            if (digits[i] == 0) continue;

            for (int j = 0; j < size; j++) {
                if (i == j) continue;

                for (int k = 0; k < size; k++) {
                    if (i == k || j == k) continue;

                    if (digits[k] % 2 == 0) {
                        int number = digits[i]*100 + digits[j]*10 + digits[k];
                        uniqueNumbers.insert(number);
                    }
                }
            }
        }

        return uniqueNumbers.size();
    }
};

/**************************************************************************************************/
/*
    Solution Approach:- Using HashMap except using Set to store the unique numbers

    Time Complexity: O(N^3)
    Space Complexity: O(1) (Since the maximum number of unique 3-digit even numbers is 900)
    N = number of digits in the input array

    Intuition:-
        - Same as the previous solution.
        - Instead we are using a HashMap to store the unique numbers instead of a Set.
        - Here before store we check if the number is already present in the HashMap or not,
            if it's not present then we store it in the HashMap.
        - At the end return the size of the HashMap which contains the unique 3-digit even numbers.
*/
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        int size = digits.size();

        for(int i = 0; i < size; i++){
            if(digits[i] == 0) continue;

            for(int j = 0; j < size; j++){
                if(i == j) continue;

                for(int k = 0; k < size; k++){
                    if(j == k || k == i) continue;

                    if(digits[k] % 2 == 0){
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        if(m.find(num) == m.end())
                            m[num]++;
                    }
                }
            }
        }

        return m.size();
    }
};
