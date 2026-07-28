/*
    https://leetcode.com/problems/alternating-groups-iii
*/
/******************** IMPOSSIBLE TO SOLVE PROBLEM : ) ********************/
/******************** CURRENTLY OUT OF MY SCOPE OF EXPERTISE AND REQ ********************/
/*
    Solution Approach: Sliding Window (Time Complexity is not Good)
 */
class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> ret;

        int size = colors.size();
        int left = 0;
        int count = 0;

        for(auto query : queries){
            int q_size = query.size();

            if(q_size == 2){
                count = 0;
                left = 0;
                int k = query[1];

                for(int right = 1; right < size + k - 1; right++){
                    if(colors[right % size] == colors[(right - 1) % size])
                        left = right;

                    if(right - left + 1 > k)
                        left++;

                    if(right - left + 1 == k)
                        count++;
                }

                ret.push_back(count);
            }
            else if(q_size == 3){
                int newindex = query[1];
                int newColor = query[2];
                colors[newindex] = newColor;
            }

        }

        return ret;
    }
};
