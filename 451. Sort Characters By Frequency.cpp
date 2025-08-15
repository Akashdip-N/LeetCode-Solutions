/*
    https://leetcode.com/problems/sort-characters-by-frequency
*/
/*
    Solution Approach:- Using Max Heap (Priority Queue)

    Time Complexity: O(n log n)
    Space Complexity: O(n)
    n = length of the input string s

    Explanation:
        - Count the frequency of each character in the string.
        - Use a max heap (priority queue) to store characters based on their frequency.
        - Pop characters from the heap and
            append them to the result string based on their frequency.
        - Return the result string.
*/
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<
            pair<int, char>,
            vector<pair<int, char>>,
            less<pair<int, char>>
        > pq;
        vector<int> freq(256, 0);

        for (char c : s)
            freq[c]++;


        for (int i = 0; i < 256; i++)
            if (freq[i] > 0) // time complexity: O(nlogn)
                pq.push({
                    freq[i], (char)i
                });

        string result = "";
        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();
            result += string(count, c);
        }
        return result;
    }
};
