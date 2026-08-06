/*
    https://leetcode.com/problems/top-k-frequent-elements/
*/
/*
    Solution Approach:- Using Priority Queue (Min Heap)

    Time Complexity: O(NlogK) (Better time complexity than the max heap O(NlogN))
    Space Complexity: O(N)
    N = number of elements in the input array
    K = number of top frequent elements to return

    Iniuition:-
        - We have to get the top K frequent elements from the input array.
        - To maintain the order of the elements based on their frequency,
            we can use a priority queue.
        - Since we are using min heap,
            element with the least frequency will be at the top of the heap.
        - So we maintain the size of the heap while pushing elements into the heap.

    Explanation:-
        * Using hashmap to count and store the frequency
            of each element in the input array.
        * Iterating through elements of the hashmap and
            pushing them into the min heap {frequency, number}.
        * While pushing elements into the heap,
            - If the size of the heap exceeds K, we pop the top element from the heap.
        * At the end, we pop the elements from the heap and
            store just the element into the result vector
        * Finally, we return the result vector.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num: nums)
            m[num]++;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;

        for(const auto& [num, freq] : m){
            pq.push({freq, num});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ret;
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};

/****************************************************************************************/
/*
    Solution Approach:- Using Priority Queue (Max Heap)

    Time Complexity: O(NlogN)
    Space Complexity: O(N)
    N = number of elements in the input array

    Intuituion:-
        - Since we are using max heap,
            element with the highest frequency will be at the top of the heap.
        - So in this case we would pop the top K elements from the heap and
            store the numbers into the result vector.

    Explanation:-
        * Storing number frequency in the hashmap.
        * Iterating through each element of the hashmap and
            pushing them into the max heap {frequency, number}.
        * Popping the top K elements from the heap and
            storing the numbers into the result vector.
        * Finally, we return the result vector.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num: nums)
            m[num]++;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>
        >pq;

        for(const auto& [num, freq] : m)
            pq.push({freq, num});

        vector<int> res;
        while(!pq.empty() && k > 0){
            const auto& [freq, num] = pq.top();
            res.push_back(num);
            k--;
            pq.pop();
        }

        return res;
    }
};
