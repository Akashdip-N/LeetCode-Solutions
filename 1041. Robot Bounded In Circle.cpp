/*
    https://leetcode.com/problems/robot-bounded-in-circle/
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of string instructions

    Intuition:-
        * The robot is starting from pos (0,0) and is facing North.
        * The robot can move in any 4 directions, North, East, South and West.
        * The main point which we need to find is,
            after all the instructions are exectued,
                if the robot is back to the starting position or not,
                    or if the robot is facing in a different direction than North.
        * Using the following values to mark the direction at which the robot is facing,
            0 -> North
            1 -> East
            2 -> South
            3 -> West

    Explanation:-
        * Initializing the robot position and the direction in which the robot is facing.
        * Iterating through each of the instructions and updating the following values:-
            i. If the instruction is 'G', that means the robot has to move 1 step,
                then we are updating the direction based on the current direction.
            ii. If the instruction is 'L',
                that means the robot has to turn left or (counter-clockwise) 90 degrees,
                    hence, adding 3 to the current direction and
                        taking the modulo with 4 to make sure that
                            the direction is in the range of 0 to 3 and not exceeding 3.
            iii. If the instruction is 'R',
                that means the robot has to turn right or (clockwise) 90 degrees,
                    hence, adding 1 to the current direction and
                        taking the modulo with 4 to make sure that
                            the direction is in the range of 0 to 3 and not exceeding 3.
        * After all the instructions are executed,
            we are checking if the robot is back to the starting position or not,
                or if the robot is facing in a different direction than North.
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int r = 0, c = 0;
        int dir = 1;

        for (char instruction : instructions) {
            if (instruction == 'G') {
                switch (dir) {
                    case 0: r--; break;
                    case 1: c++; break;
                    case 2: r++; break;
                    case 3: c--; break;
                }
            }
            else if (instruction == 'L')
                dir = (dir + 3) % 4;
            else if (instruction == 'R')
                dir = (dir + 1) % 4;
        }

        return (r == 0 && c == 0) || (dir != 1);
    }
};
