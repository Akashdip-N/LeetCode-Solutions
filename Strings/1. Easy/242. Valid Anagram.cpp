/*
    https://leetcode.com/problems/valid-anagram/
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int size = 0;
        if(s.size() > t.size())
            size  = s.size();
        else
            if(s.size() < t.size())
            size = t.size();
        else if (s.size() == t.size())
            size = t.size();
        for(int i = 0; i < size; i++)
            if(s[i]!= t[i])
                return false;
        return true;
    }
};