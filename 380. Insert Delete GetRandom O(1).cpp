/*
    https://leetcode.com/problems/insert-delete-getrandom-o1/
*/
/*
    Solution Approach:- Using HashMap and Vector

    Time Complexity:- O(1)
    Space Complexity:- O(N) (   The actual space complexity is O(2N),
                                but since 2 is constant we ignore 2          )

    N = Number of elements inserted

    Intuition:-
        - We have to design a data structure to support the following operations,
            and each having time complexity of O(1):-
                i. insert(val) - Inserts an item val into the set if not present.
                ii. remove(val) - Removes an item val from the set if present.
                iii. getRandom() - Returns a random element from
                                   the current set of elements,
                                   when this function would be called,
                                   there would be atleast one element present in the set.
                                   The probability for each elements should be equal.
        - To achieve this, we can use a HashMap and a Vector.
        - The vector will be used to store the elements in the order they are inserted.
        - The hashmap will be used to store the elements and it's index with respect to the vector.

    Explanation:-
        * Intitializing a HashMap and a Vector.
        * For the insert operation,
            - Checking in the hashmap if the element is already present or not.
            - If present, return false.
            - Else,
                first push the element in the vector
                Then store the element with respect to the index of the vector in the hashmap.
                (
                    To do this, we use the idea of size of the vector - 1,

                    Because elements are inserted at the end of the vector,
                        so the index of the last element will be size - 1
                )
            - Return true.
        * For the remove operation,
            - Checking in the hashmap if the element is already present or not.
            - If not present, return false.
            - Else,
                first get the index of the element to be removed from the hashmap.
                Then get the last element of the vector.
                Then swap the last element with the element to be removed in the vector.
                (
                    Since the order of the elements in the vector does not matter,
                    we can swap the last element with the element to be removed,
                    and then pop the last element from the vector in O(1) time complexity.
                )
                Then update the index of the last element in the hashmap.
                Then pop the last element from the vector.
                Then erase the element to be removed from the hashmap.
            - Return true.
        * For the getRandom operation,
            - Generate a random index between 0 and size of the vector - 1.
            - Return the element at that index in the vector.
*/
class RandomizedSet {
    private:
            unordered_map<int, int>m;
            vector<int> arr;
    public:
        RandomizedSet() {}

        bool insert(int val) {
            if(m.find(val) != m.end())
                return false;

            arr.push_back(val);
            m[val] = arr.size() - 1;

            return true;
        }

        bool remove(int val) {
            if(m.find(val) == m.end())
                return false;

            int index = m[val];
            int lastval = arr.back();

            arr[index] = lastval;
            m[lastval] = index;

            arr.pop_back();
            m.erase(val);

            return true;
        }

        int getRandom() {
            int randomIndex = rand() % arr.size();
            return arr[randomIndex];
        }
};
