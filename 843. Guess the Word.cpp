/*
    https://leetcode.com/problems/guess-the-word/
*/
/*
    Solution Approach: Minimax + Greedy Algorithm

    Time Complexity: O(G * N^2 * L)
    Space Complexity: O(N * L)
    G = number of guesses
    N = number of words
    L = length of each word

    Explanation:-
        * The main idea is to minimize the maximum number of words that can be eliminated in each guess.
        * For each word in the list, we count how many words would remain for each possible number of matches (0 to 6).

        * For this we use a while loop to continue till our word list is not empty.
        * In each iteration we do the following:-
            i. Try to find the best guess word from the list of words.
            ii. For each word we compare it with every other word present in the list,
                    and find the number of characters that is same,
                        with the current word and the other word.
            iii. Using an array to store the count for
                    the number of characters that matched with the current word and the other word.
            iv. Finding the maximum group size for the current word.
            v. If the maximum group size is less than the current maximum array size,
                    we update the maximum array size and the best guess word.
            vi. After finding the best guess word, we store the number of matches with the secret word.
            vii. If the number of matches is 6, we have found the secret word and return.
            viii. If not, we create a new list of words that have the same number of matches
                with the best guess word and update the list of words to this new list.
        * This continues until we find the secret word or the list of words is empty.

    Code working with example:-
        * Words = ["acckzz","ccbazz","eiowzz","abcczz"]
        * Secret word = "abcczz

        * Iteration 0 (While loop):-
            - Words = ["acckzz","ccbazz","eiowzz","abcczz"]
            - maxArrSize = 101, bestGuess = ""

            * Iteration 1 (for loop):-
                - Best guess word = "acckzz"
                - Comparing with other words:
                    - "acckzz" vs "ccbazz" = 3 matches
                    - "acckzz" vs "eiowzz" = 2 matches
                    - "acckzz" vs "abcczz" = 4 matches
                - Count of matches = [0, 0, 1, 1, 1, 0, 0]
                - Maximum group size = 1
                - Update maxArrSize = 1, bestGuess = "acckzz"

            * Iteration 2 (for loop):-
                - Best guess word = "ccbazz"
                - Comparing with other words:
                    - "ccbazz" vs "acckzz" = 3 matches
                    - "ccbazz" vs "eiowzz" = 2 matches
                    - "ccbazz" vs "abcczz" = 4 matches
                - Count of matches = [0, 0, 1, 1, 1, 0, 0]
                - Maximum group size = 1
                - Since maxArrSize = 1, we do not update maxArrSize and bestGuess.

            * Iteration 3 (for loop):-
                - Best guess word = "eiowzz"
                - Comparing with other words:
                    - "eiowzz" vs "acckzz" = 2 matches
                    - "eiowzz" vs "ccbazz" = 2 matches
                    - "eiowzz" vs "abcczz" = 2 matches
                - Count of matches = [0, 0, 3, 0, 0, 0, 0]
                - Maximum group size = 3
                -Since maxArrSize = 1, we do not update maxArrSize and bestGuess.

            * Iteration 4 (for loop):-
                - Best guess word = "abcczz"
                - Comparing with other words:
                    - "abcczz" vs "acckzz" = 4 matches
                    - "abcczz" vs "ccbazz" = 4 matches
                    - "abcczz" vs "eiowzz" = 2 matches
                - Count of matches = [0, 0, 1, 0, 2, 0, 0]
                - Maximum group size = 2
                - Since maxArrSize = 1, we do not update maxArrSize and bestGuess.
            * After this we would have found the best guess word = "acckzz" and maxArrSize = 1.
        * Calling master.guess("acckzz") would return 4 matches.
        * Creating a new list of words that have 4 matches with "acckzz" would give us ["abcczz"].
        * Updating the list of words to this new list and continuing the while loop.
        * Iteration 1 (While loop):-
            - Words = ["abcczz"]
            - maxArrSize = 101, bestGuess = ""
            * After the for loop ends then we would have the best guess word = "abcczz" and maxArrSize = 101.
        * Calling master.guess("abcczz") would return 6 matches.
*/
class Solution {
    private:
        int getMatches(const string& s1, const string& s2) {
            int matches = 0;

            for (int i = 0; i < 6; ++i)
                if (s1[i] == s2[i])
                    matches++;

            return matches;
        }

    public:
        void findSecretWord(vector<string>& words, Master& master) {
            while (!words.empty()) {
                string bestGuess = "";
                int maxArrSize = 101; // given constraints that max word array size = 100

                for (const string& word : words) {
                    int countMatches[6] = {0};

                    for (const string& otherWord : words) {
                        if (word != otherWord) {
                            int m = getMatches(word, otherWord);

                            if (m < 6)
                                countMatches[m]++;
                        }
                    }

                    // Find the maximum group size for the current word
                    int maxGroupSize = *max_element(countMatches, countMatches + 6);

                    if (maxGroupSize < maxArrSize) {
                        maxArrSize = maxGroupSize;
                        bestGuess = word;
                    }
                }

                int matches = master.guess(bestGuess);
                if (matches == 6)
                    return;

                vector<string> nextwords;
                for (const string& word : words)
                    if (getMatches(bestGuess, word) == matches)
                        nextwords.push_back(word);

                words = move(nextwords);
            }
        }
};
