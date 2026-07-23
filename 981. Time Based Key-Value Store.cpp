/*
    https://leetcode.com/problems/time-based-key-value-store/
*/
/*
    Solution Approach:- Using HashMap and Binary Search

    Time Complexity:- O(NlogK)
    Space Complexity:- O(N*K)
    N = number of set operations
    K = number of values for a given key

    Explanation:-
        * We have to find the value of the key at a given timestamp, such that
            the value of the timestamp is less than or equal to the given timestamp.
        * Using a HashMap to store the key and its corresponding timestamp and value.

        i. Set Operation:-
            * Storing the key and its corresponding timestamp and value in the HashMap.

        ii. Get Operation:-
            * Checking if the key exists in the HashMap, if not return an empty string.
            * If the key exists, performing a binary search on the array of the timestamp and value pairs.
            * First storing the array for the given key in a variable (arr).
            * Then initializing two pointers left and right to 0 and arr.size() - 1 respectively.
            * Then performing a binary search on the array to find the value of the key at the given timestamp.
            * If the timestamp at mid is less than or equal to the given timestamp,
                then storing the value at mid in a variable (res) and moving the left pointer to mid + 1.
            * Else moving the right pointer to mid - 1.
            * Finally returning the value stored in the variable (res).
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

        // Storing the array for the given key in a variable (arr)
        const auto& arr = m[key];
        int left = 0;
        int right = arr.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                // Storing the value of the mid position in the array.
                res = arr[mid].second;
                left = mid + 1;
            } else
                right = mid - 1;
        }

        return res;
    }
};
