/*
    https://leetcode.com/problems/top-k-frequent-words
*/
/*
    Solution Approach:- Using HashMap and Priority Queue

    Time Complexity: O(N log N)
    Space Complexity: O(N)
    N = Number of words in the input list

    Explanation:-
        * Create a frequency map using an unordered_map to count occurrences of each word.
        * Use a priority queue (min-heap) to keep track of the top k frequent words.
        * Define a custom comparator to order the words first by frequency (descending)
             and then lexicographically (ascending) for words with the same frequency.
        * Push all words from the frequency map into the priority queue.
        * Extract the top k elements from the priority queue to form the result list.
*/
struct Cmp {
    bool operator()(const pair<string,int>& a, const pair<string,int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;

        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto &w : words)
            m[w]++;

        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            Cmp
        > pq;

        for (auto &p : m)
            pq.push({p.first, p.second});

        vector<string> ret;

        while (k-- && !pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};
