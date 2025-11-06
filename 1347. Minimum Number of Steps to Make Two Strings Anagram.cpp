/*
    https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
*/
/*
                                        OWN Solution
    Solution Approach: Using HashMap

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the string

    Explanation:
        * Creating two hashmaps to store the frequency of characters in both strings.
        * Iterating through the first hashmap and
            checking if the character is present in the second hashmap,
                if not present, add the frequency to steps.
            if present, check if the frequency in the second hashmap is less than the first,
                if yes, add the difference to steps.
        * Finally, return the steps.
*/
class Solution {
public:
    int minSteps(string s, string t) {
        int steps = 0;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(char c: s) m1[c]++;
        for(char c: t) m2[c]++;

        for(auto i : m1) {
            if(m2.find(i.first) == m2.end())
                steps += i.second;
            else{
                if(m2[i.first] < i.second)
                    steps += abs(i.second - m2[i.first]);
            }
        }

        return steps;
    }
};
