/*
    https://leetcode.com/problems/flatten-nested-list-iterator/
*/
/*
    Solution Approach:- Iterative Approach

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = Number of integers in the nested list

    Intuition:-
        - We have to flatten the nested list and integers into a single list of integers.
        - Given some of the built-in functions of the NestedInteger class
            which we have to use to understand which is an integer and which is a nested list.
        - Functions given are:-
            i. isInteger() - Returns true if the NestedInteger holds a single integer, otherwise false.
            ii. getInteger() - Returns the single integer that the NestedInteger holds, if it holds a single integer.
                    The result is undefined if this NestedInteger holds a nested list.
            iii. getList() - Returns the nested list that the NestedInteger holds, if it holds a nested list.
                The result is undefined if this NestedInteger holds a single integer.
        - We can recursively flatten the nested list by checking if the current NestedInteger is an integer or a list.

    Explanation:-
        * Using vector to store the flattened integers.
        * Using index variable to keep track of the current position in the flattened list.
        * Using the helper function, iterating through each items in the nestedList class:-
            - If the current item is an integer, we push it to the res vector.
            - If the current item is a list, we recursively call the flatten function on that list.
        * In the next() function,
            we return the integer at the current index and increment the index.
        * In the hasNext() function,
            we check if the current index is less than the size of the res vector,
                indicating that there are more integers to return.
*/
class NestedIterator {
    private:
        vector<int> res;
        int index = 0;

        void flatten(const vector<NestedInteger>& nestedList) {
            for (const auto& item : nestedList) {
                if (item.isInteger())
                    res.push_back(item.getInteger());
                else
                    flatten(item.getList());
            }
        }

    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            flatten(nestedList);
        }

        int next() {
            return res[index++];
        }

        bool hasNext() {
            return index < res.size();
        }
};
