/*
    https://leetcode.com/problems/find-the-town-judge
*/
/*
    Solution Approach:-
    * We are counting and storing the number of connections to & from each person.
    * Then we are comparing the indegree and outdegree of each person.
    * If the indegree is n - 1 and outdegree is 0, then we have found the judge.
    * Otherwise, we return -1, which means there is no judge.
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for (auto& t : trust) {
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }

        for (int i = 1; i <= n; i++)
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;

        return -1;
    }
};
