/*
    https://leetcode.com/problems/length-of-last-word/
*/
/*
    Solution Approach:- Using StringStream

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = Length of the string

    Explanation:
        - Using stringstream to split the string into words.
        - We iterate through the words and store the last word in a variable.
        - Finally, we return the length of the last word.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;

        while (ss >> word) {}

        return word.size();
    }
};

/********************************************************************************************/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = Length of the string

    Explanation:
        - We use two pointers to iterate through the string from the end.
        - First, we skip any trailing spaces.
        - Then, we count the length of the last word until we reach a space
            or the beginning of the string.
        - Finally, we return the length of the last word.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;

        while(s[i] == ' ')
            i--;

        while(i >= 0 && s[i] != ' '){
            length++;
            i--;
        }

        return length;
    }
};

/********************************************************************************************/
/*
    Solution Approach:- Using Two Pointers (Optimized)

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = Length of the string

    Explanation:
        - We iterate through the string from the end.
        - We count the length of the last word until we reach a space or
            the beginning of the string.
        - If we encounter a space and we have already counted some characters,
            we return the length.
        - Finally, we return the length of the last word.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int size = s.size();

        while(size--){
            if(s[size] == ' ' && len !=0)
                return len;
            if(s[size] != ' ')
                len++;
        }

        return len;
    }
};
