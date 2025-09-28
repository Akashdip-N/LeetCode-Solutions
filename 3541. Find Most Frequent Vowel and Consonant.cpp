/*
    https://leetcode.com/problems/find-most-frequent-vowel-and-consonant
*/
/*
    Solution Approach: Using HashMap

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the string s

    Explanation:
        - Using hashmap to store the frequency of each character in the string.
        - Iterate through the string and for each character,
            update its frequency in the hashmap.
        - Using two variables to keep track of the maximum frequency
            of vowels and consonants.
        - Finally, return the sum of the maximum frequencies of vowels and consonants.
*/
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m;

        int freq_c = 0;
        int freq_v = 0;

        for(char c : s){
            m[c]++;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                freq_v = max(freq_v, m[c]);
            else
                freq_c = max(freq_c, m[c]);
        }

        return (freq_c + freq_v);
    }
};
