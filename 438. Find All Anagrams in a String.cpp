/*
    https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
/*
    Solution Approach:- Using Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1) (Using only 26 characters for the count in the hash map)

    N = length of the string s

    Intuition:-
        - We have to return all the anagrams in string s of string p.
        - Anagram:- Phrase/word which has the same contiguous characters
                    in string s as in string p.
        Ex:-
            Input:- s = "abab", p = "ab"
            Output:- [0, 1, 2]
            Reason, there are three anagrams present in string s of string p.
            pos[0] = "ab", pos[1] = "ba", pos[2] = "ab"

        - We would use hashmap to keep track of the count of characters both
            in string s and string p.
        - Using sliding window approach,
            and updating the character count of string s in the hashmap,
                and comparing the hashmap of string s with the hashmap of string p.
        - At the end returning the lists of starting indices of the anagrams
            in string s of string p.

    Explanation:-
        * Base case:-
            If size of string p is greater than size of string s,
                then return empty list, as there can't be any anagrams present.

        * Creating two hashmaps to store the character count of string s and string p.
        * Iterating through index 0 till the end of string p,
            and updating both the hashmap with the character count of string s and string p.

        * Checking if the anagram is present at the start of the string s,
            if yes, then adding the starting index 0 to the result list.
        * Iterating from the position after the end of string p till the end of string s,
            and performing the following operations:-
                - Incrementing the character count of the current character of string s,
                    in the hashmap of string s.
                - Decrementing the character count of the character at the left pointer,
                    in the hashmap of string s.
                - If the character count of the character at the left pointer becomes 0,
                    then removing that character from the hashmap of string s.
                - If both the hashmaps of string s and string p are equal,
                    then adding the starting index (i.e the left pointer)
                        of the anagram to the result list.
        * At the end returning the lists of starting indices of
            the anagrams in string s of string p.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        unordered_map<char, int> pCount(26), sCount(26);

        for (int i = 0; i < p.size(); i++) {
            pCount[p[i]]++;
            sCount[s[i]]++;
        }

        vector<int> res;

        // If the anagram is present at the start of the string s
        if (sCount == pCount)
            res.push_back(0);

        int left = 0;
        for (int right = p.size(); right < s.size(); right++) {
            sCount[s[right]]++;
            sCount[s[left]]--;

            if (sCount[s[left]] == 0)
                sCount.erase(s[left]);

            left++;

            if (sCount == pCount)
                res.push_back(left);
        }

        return res;
    }
};
