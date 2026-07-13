/*
    https://leetcode.com/problems/odd-even-jump/
*/
/*
    Solution Approach:- Dynamic Programming with Map

    Time Complexity:- O(NlogN)
    Space Complexity:- O(N)
    N = size of the input vector

    Added Note
        * What the question wants is, we would do
            1st jump as odd jump
            2nd jump as even jump
            3rd jump as odd jump
            and so on...

    Explanation:-
        * Since we know that the last index is always reachable,
            we would start from the second last index and check if we can reach the last index.
        * First creating two vectors to store the odd and even jumps.
        * Then we will create a map to store the values and their indices.
        * First we would store the last index value and its index in the map.
        * Then we will iterate from the second last index to the first index
            and check if we can reach the last index.
        * For odd jumps, we will check if there is a value greater than or equal to the current value in the map.
        * And we would try to find the index of that value.
        * Then if the index exists in the map, that means we can reach the last index from the current index with odd jump.
        * For even jumps, we will check if there is a value strictly greater than the current value in the map.
        * And we would try to find the index of that value.
        * Then if the index exists in the map, that means we can reach the last index from the current index with even jump.
        * Finally, we will return the total number of jumps
*/
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int size = arr.size();
        if (size <= 1) return size;

        vector<bool> oddJumps(size, false);
        vector<bool> evenJumps(size, false);

        oddJumps[size - 1] = true;
        evenJumps[size - 1] = true;

        // Map to store the values and their indices
        map<int, int> m;
        m[arr[size - 1]] = size - 1;

        int totalJumps = 1;

        for (int i = size - 2; i >= 0; i--) {
            // Returns an iterator that is greater than or equal to arr[i] for odd jumps
            auto odd_it = m.lower_bound(arr[i]);
            if (odd_it != m.end())
                oddJumps[i] = evenJumps[odd_it->second]; // since the alternate jump is even, we check evenJumps

            // Returns an iterator that is strictly greater than arr[i] for even jumps
            auto even_it = m.upper_bound(arr[i]);
            if (even_it != m.begin())
                evenJumps[i] = oddJumps[prev(even_it)->second]; // since the alternate jump is odd, we check oddJumps

            if (oddJumps[i]) // that means we can reach the end from this index with odd jump
                totalJumps++;

            m[arr[i]] = i;
        }

        return totalJumps;
    }
};
