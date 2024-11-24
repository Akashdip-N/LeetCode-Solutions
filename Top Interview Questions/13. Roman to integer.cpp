/*
    https://leetcode.com/problems/roman-to-integer/
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
        int size = s.size();
        for(int i = 0; i < size; i++){
            if(s[i] == 'I' && i < (size - 1) && ((s[i+1] == 'V' || s[i+1] == 'X')) ){
                val += (map[s[i+1]] - 1);
                i++;
            }
            else
            if(s[i] == 'X' && i < (size - 1) && (s[i+1] == 'L' || s[i+1] == 'C')){
                val += (map[s[i+1]] - 10);
                i++;
            }
            else
            if(s[i] == 'C' && i < (size - 1) && (s[i+1] == 'D' || s[i+1] == 'M')){
                val += (map[s[i+1]] - 100);
                i++;
            }
            else
                if(map.find(s[i]) != map.end())
                    val += map[s[i]];
        }
        return val;
    }
};