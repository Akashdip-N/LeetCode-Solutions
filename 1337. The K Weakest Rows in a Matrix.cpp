/*
    https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
*/
/*
    Solution Approach:- Priority Queue (MinHeap)

    * Using MinHeap to store the count of soldiers and index of row.
    * Using ans vector to store the result and return it.
*/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int count = 0;
        int index = 0;
        for(auto mats : mat){
            for(int i = 0; i < mats.size(); i++)
                if(mats[i] == 1)
                    count++;
            pq.push({count, index});
            count = 0;
            index++;
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
