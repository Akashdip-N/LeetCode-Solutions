/*
    https://leetcode.com/problems/roman-to-integer/

    Solution:-

    1. Create a map of char and int to store the roman values.
    2. We are checking if the initial string value is smaller than the next value
        then we are subtracting the value from the result.
    3. Else we are adding the value to the result.
    4. Return the result.
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I']= 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int val = 0;

        for(int i = 0; i < s.size(); i++)
            if ((i+1) < s.size() && (map[s[i]] < map[s[i+1]]))
                val -= map[s[i]];
            else
                val += map[s[i]];

        return val;
    }
};
