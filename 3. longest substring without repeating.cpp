/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
/*
    Solution Approach:- Using Sliding Window with Fixed Size Array

    Time Complexity:- O(N)
    Space Complexity:- O(1) (Constant Space, fixed size array of size 128)
    N = length of the string

    Intuition:-
        - We have to find a substring without repeating characters from the given string.
        - Using sliding window technique, we would maintain the window of the substring
            without repeating characters.
        - Using a fixed size array of size 128
            to store the index of the current character of the string.
            (
                This vector would include the entrie ASCII character set,
                    including the special characters, digits, and alphabets.
            )
        - And in each iteration,
            we would check if the current character is already present in the hashmap,
                and update the left pointer to the index of the current character + 1.
        - Update the maximum length of the substring without repeating characters.

    Explanation:-
        * Base case:- If the string is empty, return 0.
            (
                That means no characters are present in the string,
                so the length of the longest substring without repeating characters is 0.
            )
        * Setting maxLength to 1, left pointer to 0, and vector of size 128.
        * Iterating through index 0 till the end of the string,
            and performing the following operations:-
            i. Checking if the current character is already present in the vector,
                - If it is,
                    then updating the left pointer to the index of the current character + 1.
            ii. Updating the maximum length of the substring without repeating characters.
            iii. Storing the index of the current character in the vector.
            Ex:-
                Input: s = "abcabcbb"
                Output: 3

                Iteration 1:-
                    left = 0, right = 0
                    current character = 'a',
                    is 'a' present in the vector? No

                    maxLength = max(maxLength, right - left + 1) = 1
                    maxLength = 1, mp['a'] = 1
                Iteration 2:-
                    left = 0, right = 1, maxLength = 2,
                    current character = 'b',
                    is 'b' present in the vector? No

                    maxLength = max(maxLength, right - left + 1) = 2
                    maxLength = 2, mp['b'] = 2
                Iteration 3:-
                    left = 0, right = 2, maxLength = 3,
                    current character = 'c',
                    is 'c' present in the vector? No

                    maxLength = max(maxLength, right - left + 1) = 3
                    maxLength = 3, mp['c'] = 3
                Iteration 4:-
                    left = 0, right = 3, maxLength = 3,
                    current character = 'a',
                    is 'a' present in the vector? Yes, at index 1
                    left = max(left, mp['a']) = 1

                    maxLength = max(maxLength, right - left + 1) = 3
                    maxLength = 3, mp['a'] = 4
                *
                *
                *
                Final result: maxLength = 3

        * Finally, returning the maximum length of the substring that we found.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) return 0;

        int left = 0, maxLength = 0;
        vector<int> mp(128, 0);

        for (int right = 0; right < size; right++) {
            if (mp[s[right]] > 0)
                left = max(left, mp[s[right]]);

            maxLength = max(maxLength, right - left + 1);
            mp[s[right]] = right + 1;
        }

        return maxLength;
    }
};

/******************************************************************************************/
/*
    Solution Approach:- Using Sliding Window with Hash Map

    Time Complexity: O(N)
    Space Complexity: O(1) (Constant Space, fixed size map of size 128)

    N = length of the string

    Intuition:-
        - Same approach to the above approach.
        - Instead using hash-map to store the
            index of the current character of the string.

    Explanation:-
        * Same as the above approach
        * Instead we are using hash-map to perform the
            same operations as the above approach.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0) return 0;

        int left = 0, maxLength = 0;
        unordered_map<char, int> mp(128);

        for(int right = 0; right < size; right++){
            if(mp.find(s[right]) != mp.end())
                left = max(left, mp[s[right]]);

            maxLength = max(maxLength, right - left + 1);
            mp[s[right]] = right + 1;
        }

        return maxLength;
    }
};

/******************************************************************************************/
/*
    Solution Approach:- Using Sliding Window with Hash Set

    Time Complexity: O(N)
    Space Complexity: O(min(M, N))

    N = length of the string
    M = lenght of the substring without repeating characters

    Intuition:-
        - Similar to the above approach.
        - Instead we would use a set to store the unique characters in the substring.
        - And in each iteration, we would put the new character in the set.
        - Update the maximum length of the substring without repeating characters.

    Explanation:-
        * Base case:- If the string is empty, return 0.
            (
                That means no characters are present in the string,
                so the length of the longest substring without repeating characters is 0.
            )

        * Setting maxLength to 1, left pointer to 0,
            and creating an unordered set to store the unique characters in the substring.
        * Iterating through index 0 till the end of the string,
            and performing the following operations:-
            i. Checking if the current character is already present in the set,
                - If it is,
                    then removing each element from left until,
                        the current character is not present in the set.
                    And bringing the left pointer to one side to the right.
            ii. Adding the current character to the set.
            iii. Updating the maximum length of the substring without repeating characters.

        * Finally, returning the maximum length of the substring that we found.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0)
            return 0;

        int maxLength = 1, left = 0;
        unordered_set<char> st;

        for(int right = 0; right < size; right++){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
