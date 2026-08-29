/*
    https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/
/*
    Solution Approach:- Using Queue

    Time Complexity:- O(N*K)
    Space Complexity:- O(N)
    N = Number of Players
    K = Step Size

    Intuition:-
        - We have been given a circular game with 1 to N players,
            and we have to eleminate every Kth player until only one player is left.
        - Using queue, we can simulate this process.
        - At the end we would return the top of the queue as the winner.

    Explanation:-
        * Pushing 1 to N players into the queue.
        * While there are atleast more than 1 player in the queue,
            - We will first pop the first K - 1 players and push them back into the queue.
            - Then pop the Kth player from the queue, which is the player to be eliminated.
        * At the end, we will return the top of the queue as the winner.
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        for(int i = 1; i <= n; i++)
            q.push(i);

        while(q.size() > 1){
            for(int i = 1; i < k; i++){
                int ele = q.front();
                q.pop();
                q.push(ele);
            }

            q.pop();
        }

        return q.front();
    }
};

/***********************************************************************************************/
/*
    Solution Approach:- Using Josephus Problem

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = Number of Players

    Intuition:-
        - Same as above,
            but we use the Josephus problem formula to directly calculate the winner.
        - Link:- https://www.geeksforgeeks.org/dsa/josephus-problem/
        - We use the formula of
            start = (start + k) % i
        - At the end, we return start + 1 as the winner,
            because the players are numbered from 1 to N, but the index is 0-based.
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;

        for (int i = 2; i <= n; i++)
            winner = (winner + k) % i;

        return winner + 1;
    }
};
