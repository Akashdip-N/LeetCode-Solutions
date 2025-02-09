/*
    https://leetcode.com/problems/fizz-buzz/
*/
/*
    Solution Approach:
    * We are iterating from 1 to n.
    * If the number is divisible by 3 and 5, we are adding "FizzBuzz" to the vector.
    * If the number is divisible by 3, we are adding "Fizz" to the vector.
    * If the number is divisible by 5, we are adding "Buzz" to the vector.
    * If the number is not divisible by 3 or 5, we are adding the number to the vector.
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for (int i = 1; i <= n; i++)
            if((i % 3 == 0)&&(i % 5 == 0))
                s.push_back("FizzBuzz");
            else
                if(i % 3 == 0)
                s.push_back("Fizz");
            else
                if(i % 5 == 0)
                s.push_back("Buzz");
            else
                    s.push_back(to_string(i));

        return s;
    }
};
