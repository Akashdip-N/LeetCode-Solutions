/*
    https://leetcode.com/problems/fibonacci-number/
*/
class Solution {
public:
    int fib(int n) {
        // 0 1 1 2 3 5 8 
        int a = 1, b = 1, c = 1;
        if(n == 0)
            return 0;
        else
            if (n == 1)
                return a;
        else
            if(n == 2)
                return b;
        else{
                for (int i = 2; i < n; i++){
                    a = b;
                    b = c;
                    c = a + b;
                }
        }
        return c;
    }
};