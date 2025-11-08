/*
    https://leetcode.com/problems/subdomain-visit-count
*/
/*
    Solution Approach: Using HashMap to store counts of each domain and subdomain.

    Time Complexity: O(N * M)
    Space Complexity: O(N * M)
    N = number of entries in cpdomains
    M = average length of each domain string

    Explanation:
        * We iterate through each entry in cpdomains.
        * For each entry, we split it into count and domain.
        * We update the count for the full domain in the hashmap.
        * We then extract each subdomain by finding '.' and update their counts in the hashmap.
        * Finally, we construct and return the result vector from the hashmap.
*/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        vector<string> ret;

        for (string domain : cpdomains) {
            int size = domain.size();
            size_t pos = domain.find(' ');
            if (pos == string::npos) continue;

            int num = stoi(domain.substr(0, pos));
            string low_level = domain.substr(pos + 1);

            // full domain
            m[low_level] += num;

            // subdomains
            for (size_t i = 0; i < low_level.size(); ++i) {
                if (low_level[i] == '.') {
                    string sub = low_level.substr(i + 1);
                    m[sub] += num;
                }
            }
        }

        for (auto &p : m)
            ret.push_back(to_string(p.second) + " " + p.first);

        return ret;
    }
};
