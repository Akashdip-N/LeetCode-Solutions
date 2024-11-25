/*
    https://leetcode.com/problems/first-unique-character-in-a-string/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ump(26);
        for(int i = 0; i < s.size(); i++)
            ump[s[i]]++;

        for(int i = 0; i < s.size(); i++)
            if(ump[s[i]] == 1)
                return i;
        return -1;
    }
};

/**********************************************************************/
class Solution {
public:
    int firstUniqChar(string s) {
        int ret = -1;
        char ch = 0;
        if(s.length() == 1 )
            return 0;
        else
            for (int i = 0; i < s.length() - 1; i++){
                size_t found = s.find(s[i]);
                if(i < (s.length() - 1)){
                    if(found != string::npos){
                        if((s.find(s[i], found+1)) == string::npos)
                            return i;
                    }
                }
                else
                    return i;
            }
        return ret;
    }
};