/*
    https://leetcode.com/problems/search-suggestions-system/
*/
/*
    Solution Approach:- Using Sorting and Two Pointers

    Time Complexity:- O(N * L * logN + M * L)
    Space Complexity:- O(M * L)
    N = number of products / words in the products list
    M = length of the searchWord
    L = average length of the words in the products list

    Intuition:-
        - Given us a list of product names and a search word.
        - We need to return a list of lists of suggested products after each character
            of the search word is typed.
        - If there are more than three products that match the search word,
            return the three lexicographically minimums products.

            Example:-
                    products = ["mobile","mouse","moneypot","monitor","mousepad"]
                    searchWord = "mouse"
                    Output: [
                        ["mobile","moneypot","monitor"], => After typing 'm'
                        ["mobile","moneypot","monitor"], => After typing 'mo'
                        ["mouse","mousepad"],            => After typing 'mou'
                        ["mouse","mousepad"],            => After typing 'mous'
                        ["mouse","mousepad"]             => After typing 'mouse'
                    ]

        - Since, we need the products in lexicographical order, we can sort the products list.
        - Then, instead of searching the entire products list for each character,
            we would use two pointer to check the range of products that matches the search word
                and then change the range of the search space after each character is typed.

            Ex:-
                products = ["mobile","mouse","moneypot","monitor","mousepad"]
                searchWord = "mouse"

                - When typed 'm', the range of products that matches is
                    [0, 4] => ["mobile","mouse","moneypot","monitor","mousepad"]
                - When typed 'mo', the range of products that matches is
                    [0, 4] => ["mobile","mouse","moneypot","monitor","mousepad"]
                - When typed 'mou', the range of products that matches is
                    [1, 4] => ["mouse","mousepad"]
                - When typed 'mous', the range of products that matches is
                    [1, 4] => ["mouse","mousepad"]
                - When typed 'mouse', the range of products that matches is
                    [1, 4] => ["mouse","mousepad"]

    Explanation:-
        * Sorting the products list in lexicographical order.
        * Setting the left pointer to index 0 and
            right pointer to the last index of the products list.
        * For each character in the search word,
            - Checking if the current character in the left
            and right pointers matches the current character in the search word.
            - If it doesn't match, we move the left pointer to the right and
                the right pointer to the left until we find a match.
            - After that, we add the products in the range of left and right pointers
                to the current suggestions list.
            - Finally, we add the current suggestions list to the result list.
        * Returning the result list after all characters in the search word are processed.
*/
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // O(N * logN * L)
        vector<vector<string>> result;

        int left = 0;
        int right = products.size() - 1;

        // O(M)
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];

            // O(N)
            while (left <= right && (products[left].size() <= i || products[left][i] != c))
                left++;

            // O(N)
            while (left <= right && (products[right].size() <= i || products[right][i] != c))
                right--;

            vector<string> currentSuggestions;
            for (int j = left, i = 0; j <= right && i < 3; j++, i++) // O(L * M)
                currentSuggestions.push_back(products[j]);

            result.push_back(currentSuggestions);
        }

        return result;
    }
};
