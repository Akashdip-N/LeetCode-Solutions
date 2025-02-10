/*
    https://leetcode.com/problems/palindrome-number/
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long long int rev = 0;

        while(x > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return temp == rev;
    }
};

/*                      USING STACK                  */
/*                    BAD TIME COMPLEXITY            */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        stack<int> s;
        int temp = x;
        while(x > 0){
            s.push(x % 10);
            x /= 10;
        }

        while(!s.empty()){
            if(s.top() != temp % 10)
                return false;

            s.pop();
            temp /= 10;
        }
        return true;
    }
};
