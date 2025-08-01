/*
    https://leetcode.com/problems/reverse-bits/
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 31; i >= 0; i--){
           if(n%2 == 1)
                ans += pow(2,i);
            n/=2;
        }
        return ans;
    }
};