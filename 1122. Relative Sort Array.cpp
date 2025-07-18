/*
    https://leetcode.com/problems/relative-sort-array
*/
/*
    Solution Approach:- Using HashMap and Sorting

    Time Complexity:- O(n log n) (Because we are using in-built sort function)
    Space Complexity:- O(n)
    n = arr1 size

    Explanation:-
        - Using a hashmap to store the occurances of elements in arr2.
        - Using a vector to store the elements of arr1 that are not in arr2.
        - Sorting the vector of elements not in arr2.
        - Using the hashmap to store the occurances of elements in arr1.
        - Iterating through arr2 and
            adding the elements that are in arr2 to the result vector.
        - Finally, adding the elements that are not in arr2 to the result vector.
        - Returning the result vector.
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int> arr_other;

        unordered_map<int, int> mp;
        for(int ele : arr2)
            mp[ele]++;

        for(int num : arr1)
            if(mp.find(num) == mp.end())
                arr_other.push_back(num);

        // time complexity of sort is O(n log n)
        sort(arr_other.begin(), arr_other.end());
        mp.clear();

        for(int ele : arr1)
            mp[ele]++;

        for(int num : arr2){
            if(mp.find(num) != mp.end()){
                int count = mp[num];
                for(int i = 0; i < count; i++)
                    result.push_back(num);
                mp.erase(num);
            }
        }

        for(int num : arr_other)
            result.push_back(num);

        return result;
    }
};
