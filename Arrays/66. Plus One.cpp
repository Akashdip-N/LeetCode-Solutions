/*
    https://leetcode.com/problems/plus-one/
*/
// This is my solution but was incorrect in other test cases
// because when the test cases are very large then this function is not working properly
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long sum = 0, b = (digits.size()-1);
        for (int i = 0; i < digits.size(); i++, b--)
            sum = sum + (pow(10, b)*digits[i]);

        sum = sum + 1;
        vector<int> a;
        while (sum > 0){
            a.push_back(sum%10);
            sum /= 10;
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

/*-----------------------------------------------------*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                ++digits[i];
                return digits;
            }
        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};