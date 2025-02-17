/*
    https://leetcode.com/problems/fizz-buzz/
*/
/*
    Solution Approach:
    * First We will check if the number is divisible by 3
        if yes, then will check if it is divisible by 5
            if yes, then will add "FizzBuzz" to the vector
            else will add "Fizz" to the vector
    * else will check if it is divisible by 5
            if yes, then will add "Buzz" to the vector
    * else will add the number to the vector
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for (int i = 1; i <= n; i++)
            if(i % 3 == 0){
                if(i % 5 == 0)
                    s.push_back("FizzBuzz");
                else
                    s.push_back("Fizz");
            }
            else
                if(i % 5 == 0)
                    s.push_back("Buzz");
            else
                s.push_back(to_string(i));
        return s;
    }
};
