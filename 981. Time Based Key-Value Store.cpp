/*
    https://leetcode.com/problems/time-based-key-value-store/
*/
/*
    Solution Approach:- Using HashMap and Binary Search

    Time Complexity:- O(NlogK)
    Space Complexity:- O(N*K)
    N = number of set operations
    K = number of values for a given key

    Intiution:-
        - We have to implement a time-based key-value store, which supports three operations:
            i. TimeStamp():- This operation is used to initialize the timestamp for the key-value store.
            ii. set:- This operation is used to store the key and
                it's corresponding timestamp and value.
            iii. get :- This operation is used to retrieve the value of the key at a given timestamp,
                    BUT IF there are more than one value for the given key at the given timestamp,
                        then we have to return the value of the key which is at the latest timestamp
                            but the timestamp of the value should be less than or
                                equal to the given timestamp.
        - We would use a hashmap to store the key and its corresponding timestamp and value.
            Ex:-
                Input:-
                    ["TimeMap", "set", "get", "get", "set", "get", "get"]
                    [
                        [],
                        ["foo", "bar", 1],
                        ["foo", 1],
                        ["foo", 3],
                        ["foo", "bar2", 4],
                        ["foo", 4],
                        ["foo", 5]
                    ]

                The output would be:-
                    [null, null, "bar", "bar", null, "bar2", "bar2"]
                -------------------------------------------------------------------------------------------
                The hashmap would look like this:-
                    {
                        "foo": [(1, "bar"), (4, "bar2")]
                    }
        - Given that `All the timestamps timestamp of set are strictly increasing.` that means,
            the values are stored in a sorted manner based on the timestamp for the respective key,
        - We can perform a binary search on the array of the timestamp and value pairs
                to find the value of the key at the given timestamp.

    Explanation:-
        * Intializing a hashmap to store the key and a vector in pair to store the timestamp and value.
        * In the set function,
            pushing the timestamp and the value in the vector for the given key.
        * In the get function,
            - If there is no key present in the hashmap, then return an empty string.
            - Else, we create an array for the given key value.
            - Then we perform a binary search on the array.
            - We point the left pointer to start of the array i.e. index 0
            - The right pointer to the end of the array i.e. index arr.size() - 1

            - We continue the loop till the left pointer is less than or equal to the right pointer.
                - We calculate the mid index of the array.
                - If the timestamp at the mid index is less than or equal to the given timestamp,
                    - We store the value of the mid index in the result variable.
                    - We move the left pointer to mid + 1, to search for a greater timestamp
                - Else, we move the right pointer to mid - 1, to search for a smaller timestamp.
            - Finally, we return the result variable which contains
                the value of the key at the given timestamp.
*/
class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> m;
    public:
        TimeMap() {}

        void set(string key, string value, int timestamp) {
            m[key].push_back({timestamp, value});
        }

        string get(string key, int timestamp) {
            if (m.find(key) == m.end())
                return "";

            const auto& arr = m[key];
            int left = 0;
            int right = arr.size() - 1;
            string res = "";

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[mid].first <= timestamp) {
                    res = arr[mid].second;
                    left = mid + 1;
                } else
                    right = mid - 1;
            }

            return res;
        }
};
