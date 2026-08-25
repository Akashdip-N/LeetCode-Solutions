/*
    https://leetcode.com/problems/valid-palindrome-ii/
*/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = Length of the string

    Intuition:-
        - We have to check if we can find a palindrome in the given string,
            by removing at most one character from it.
        - We would use two pointers to check the characters from
            the start and the end of the string.
        - If the characters are not the same in that case, we check the following two cases:
            i. We move the left pointer to one step forward, and keep the right the same,
                and check if the substring is a palindrome.
            ii. We move the right pointer to one step backward, and keep the left the same,
                and check if the substring is a palindrome.
        - If the characters are not same then we return false,
            else we continue to check the next characters.
        - We would shorten the window of the search space
            by moving the pointers towards each other.

        Ex:-
            string:- "aaabaaca"

            Iteration 1:-
                left = 0, right = 7
                s[left] = 'a', s[right] = 'a' => same, move both pointers

            Iteration 2:-
                left = 1, right = 6
                s[left] = 'a', s[right] = 'c' => not same,
                check the two cases:
                    i. left = 2, right = 6 => "abaaca" => not a palindrome
                    ii. left = 1, right = 5 => "aaaba" => is a palindrome
                Since we found a palindrome in one of the cases, we return true.

                Finally we return true, since we found a palindrome.

    Explanation:-
        Main function:-
            * Initializing left pointer to 0, and right to the last index of the string.
            * We run the loop while the left pointer is less than the right pointer.
            * First we check if the characters are different,
                if they are then, we check the two cases mentioned above.
            * If we get true in any of the cases, we return true, else we return false.

            * If the characters are same, we move both the pointers towards each other.
            * Finally we return true, since the given string itself a palindrome.

        Helper function:-
            * Taking the following as input:
                - The string
                - The left pointer
                - The right pointer
            * Running the loop while the left pointer is less than the right pointer.
            * If the characters are different, we return false.
            * If the characters are same, we move both the pointers towards each other.
            (
                what we are doing here is basically we are checking the characters from the
                extreme ends of the string, and moving the pointer accordingly.
            )
*/
class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return
                    isPalindrome(s, left + 1, right) ||
                    isPalindrome(s, left, right - 1);

            left++;
            right--;
        }

        return true;
    }
};

/**********************************************************************************/
/*
    Solution Approach:- Using Two Pointers and String comparison

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = Length of the string

    Intuition:-
        - Same as above but instead of checking the characters one by one,
            we can check the substring of the string formed by the following the two cases:-
                i. Moving the left pointer to one step forward, till the end of the string.
                ii. Moving the right pointer to one step backward, till the start of the string.

        - If both the string and its reverse are same, then it is a palindrome.

        Ex:-
            string:- "aaabaaca"

            Iteration 1:-
                left = 0, right = 7
                s[left] = 'a', s[right] = 'a' => same, move both pointers

            Iteration 2:-
                left = 1, right = 6
                s[left] = 'a', s[right] = 'c' => not same,
                substring from left+1 to right => "abaaca" => not a palindrome
                substring from left to right-1 => "aaaba" => is a palindrome
                Since we found a palindrome in one of the cases, we return true.

    Explanation:-
        Main function:-
            * Initializing left pointer to 0, and right to the last index of the string
            * We run the loop while the left pointer is less than the right pointer.
            * First we check if the characters are different,
                if they are then we get the two substrings mentioned above and
                    check if they are palindromes.
            * If we get true in any of the cases, we return true, else we return false.
            * If the characters are same, we move both the pointers towards each other.
            * Finally we return true, since the given string itself a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string sub) {
        string reversedSub = sub;
        reverse(reversedSub.begin(), reversedSub.end());
        return sub == reversedSub;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                string option1 = s.substr(left + 1, right - left);
                string option2 = s.substr(left, right - left);
                return isPalindrome(option1) || isPalindrome(option2);
            }

            left++;
            right--;
        }

        return true;
    }
};
