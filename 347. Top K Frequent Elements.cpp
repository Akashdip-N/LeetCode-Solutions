/*
    https://leetcode.com/problems/top-k-frequent-elements/
*/
/*
    Solution Approach:- PriorityQueue changed into min heap

    * Using map to store frequency of each element.
    * Using priority queue which has been changed into min heap to
        store elements based on their frequency,
            but only keep the top k elements in the heap.
                hence, if the heap size exceeds k, we are popping the smallest element.
    * Using vector to finally store the top k frequent elements and return it.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        for(auto num : nums)
            freq[num]++;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        for(auto pair : freq){
            minHeap.push(
                {
                    pair.second, pair.first
                }
            );

            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
