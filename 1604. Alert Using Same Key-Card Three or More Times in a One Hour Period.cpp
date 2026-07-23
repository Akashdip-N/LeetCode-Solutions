/*
    https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
*/
/*
    Solution Approach:- Using HashMap and Sorting

    Time Complexity: O(NlogN)
    Space Complexity: O(N)
    N = number of keyName/keyTime entries

    Explanation:-
        * Storing the keyName and keyTime in a hashmap
            with name as the key and a vector of times as the value.
        * Converting the times into minutes for easier comparison.
        * Iterating through each name and checking
            if there are entries with 3 or more times for that specific name.
        * Sorting the times for each names.
        * Checking the difference between the current time and the time 2 entries before it.
        * If the difference is less than or equal to 60 minutes,
            that means within a 1 hour of time period,
                adding the name to the result vector.
        * Sorting the result vector in lexicographical order before returning it.
*/
class Solution {
    private:
        int toMinutes(const string& t) {
            int hours = stoi(t.substr(0, 2));
            int mins = stoi(t.substr(3, 2));
            return hours * 60 + mins;
        }

    public:
        vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
            unordered_map<string, vector<int>> nameToTimes;

            for (int i = 0; i < keyName.size(); ++i)
                nameToTimes[keyName[i]].push_back(toMinutes(keyTime[i]));

            vector<string> result;

            for (auto& [name, times] : nameToTimes) {
                if (times.size() < 3)
                    continue;

                sort(times.begin(), times.end());

                for (int i = 2; i < times.size(); ++i) {
                    if (times[i] - times[i - 2] <= 60) {
                        result.push_back(name);
                        break;
                    }
                }
            }

            sort(result.begin(), result.end());
            return result;
        }
};
