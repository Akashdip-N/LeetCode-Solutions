/*
    https://leetcode.com/problems/happy-number/
*/
class Solution {
public:
    int fun(int n){
        int ans  = 0;
        while(n > 0){
            ans += (n%10)*(n%10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int num) {
      int slow = num;
      int fast = num;
      do{
          slow = fun(slow);
          fast = fun(fun(fast));
      }while(slow!=fast);
      return (slow == 1);
    }
};