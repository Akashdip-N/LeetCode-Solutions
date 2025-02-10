/*
    https://leetcode.com/problems/string-to-integer-atoi/
*/
/*
    Solution Approach:-

    1. We will try to avoid the white spaces at the beginning.
    2. We will check for the sign of the number.
    3. We will keep track of the number.
    4. We will check if the number is within the range of INT_MAX and INT_MIN.
    5. We will return the number.
*/
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        if(size == 0)
            return 0;

        long long int ans = 0;

        int l = 0;
        while(l < size && s[l] == ' ')
            l++;

        if(l == size)
            return 0;

        int sign = 1;
        if(s[l] == '-'){
            sign = -1;
            l++;
        }
        else if(s[l] == '+')
            l++;


        while(l < size && isdigit(s[l])){
            if(s[l] == ' ')
                break;

            ans = ans * 10 + s[l] - '0';
            if(ans > INT_MAX){
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            l++;
        }

        return (int)(sign*ans);
    }
};
