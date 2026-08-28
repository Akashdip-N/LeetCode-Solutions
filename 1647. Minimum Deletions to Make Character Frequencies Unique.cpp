/*
    https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/
/*
    Solution Approach:- Using HashMap and Set

    Time Complexity:- O(N) (Only for the set insertion part, Hashmap constant run time i.e. 26)
    Space Complexity:- O(K)
    N = length of s
    K = number of unique characters in s

    Intuition:-
        - We have to make sure that no two characters in the string have the same frequency.
        - Using HashMap to store the frequency of each character in the string.
        - Then using a Set to store the frequencies of the characters.
        - If the frequency of a character is already present in the Set,
            then we have to decrease the frequency of that character until it is unique.
        - At the end return the count of deletions made.

    Explanation:-
        * Storing the frequency of each character in the string in the HashMap.
        * Iterating over the HashMap and
            - If the frequency of a character is already present in the Set,
                then we have to decrease the frequency of that character until it is unique
                    i.e. the frequecy is greater than 0,
                        because we can have more than one character with 0 frequency count.
            - For each decrease in frequency, we have to increase the count of deletions made.
        * At the end return the count of deletions made.
*/
class Solution {
public:
    int minDeletions(string s) {
        int count = 0;
        unordered_map<char, int> m(26);
        for(char c:s) m[c]++;

        set<int> freqSet;
        for(auto [c, freq] : m){
            while(freq > 0 && freqSet.find(freq) != freqSet.end()){
                freq--;
                count++;
            }

            freqSet.insert(freq);
        }

        return count;
    }
};
