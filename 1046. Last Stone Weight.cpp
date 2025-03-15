/*
    https://leetcode.com/problems/last-stone-weight/
*/
/*
    Solution Approach:- Using Max Heap

    * Max Heap (Priority Queue) to store the stones in descending order.
    * Comparing the value of the last two stones,
        if they are not equal, storing the difference back into the heap.
            and popping the top element.
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];

        priority_queue<int> pq;

        for(auto stone : stones)
            pq.push(stone);

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x != y)
                pq.push(x-y);
        }

        if(pq.empty())
            return 0;
        return pq.top();
    }
};
