/*
    https://leetcode.com/problems/nim-game/
*/
/*
    Solution Approach:- Using Mathematical Approach

    Time Complexity:- O(1)
    Space Complexity:- O(1)

    Intuition:-
        - Given us (n) number of stones, we can take 1, 2 or 3 stones in each turn.
        - We have to determine if we can win the game or not.


        - If we can take 1, 2 or 3 stones in each turn,
            then we can always win if the number of stones is not a multiple of 4.
        - Hence, if the number of stones is a multiple of 4, we will lose the game.
*/
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
