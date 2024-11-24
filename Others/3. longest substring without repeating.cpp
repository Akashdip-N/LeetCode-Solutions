/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int start = 0, end = 0;
        map<char, int> position;
        while(end < s.size()){
            ans = max(ans, end-start+1);
            position[s[end]] = end;
            if(end+1 < s.size()){
                if(position.find(s[end+1]) == position.end())
                    end++;
                else{
                    int newStart = position[s[end+1]]+1;
                    for(int i = start; i < newStart; i++)
                        position.erase(s[i]);
                    start = newStart;
                    end++;
                }
            }else
                break;
        }
        return ans;
    }
};