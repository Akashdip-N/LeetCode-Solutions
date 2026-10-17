/*
    https://leetcode.com/problems/asteroid-collision/
*/
/*
    Solution Approach:- Using Stack Concept

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = Number of Asteroids

    Intuition:-
        - Given us a list of asteroids.
        - Each asteroid has a size and a direction (positive for right, negative for left).
        - When two asteroids meet, the smaller one will explode.
        - If they are the same size, both will explode.
        - At the end, we need to return the state of the asteroids after all collisions.

        - So, what we can do is, till the time we don not encounter a
            negative asteroid, we can keep pushing the asteroids in a vector stack.
        - When we encounter a negative asteroid, we keep on popping
            till we find a positive asteroid or the vector stack is empty.
        - At the end we return the vector containing the asteroids in the stack.

    Explanation:-
        * Iterating over all the asteroids from the given list.
        * Performing the following operations for each asteroid:-
            i. Marking the asteroid as not destroyed.
            ii. Checking if the vector stack is not empty
                and the last asteroid that is present in the vector stack is non-negative
                    and the current asteroid is negative.
                - If the above condition is true, we check the following conditions:-
                    a. If the absolute size of the last asteroid in the vector stack
                        is less than the absolute size of the current asteroid,
                            then we pop the last asteroid from the vector stack.
                    b. If the absolute size of the last asteroid in the vector stack
                        is equal to the absolute size of the current asteroid,
                            then we pop the last asteroid from the vector stack,
                                mark the current asteroid as destroyed and break the loop.
                    c. If the absolute size of the last asteroid in the vector stack
                        is greater than the absolute size of the current asteroid,
                            then we mark the current asteroid as destroyed and break the loop.
                    *****************************************************************************
                    * vector stack = [5, 10]
                    * current asteroid = -5
                    *
                    * The size of the last asteroid in the vector stack is > the
                        size of the current asteroid, that means
                        the current asterossid will be destroyed and we break the loop.

                    *****************************************************************************

            iii. If the current asteroid is not destroyed, we push it into the vector stack.
        * At the end, we return the vector stack containing the asteroids
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (abs(st.back()) < abs(ast))
                    st.pop_back();
                else if (abs(st.back()) == abs(ast)) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
                st.push_back(ast);
        }

        return st;
    }
};
