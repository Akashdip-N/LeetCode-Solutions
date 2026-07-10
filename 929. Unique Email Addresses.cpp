/*
    https://leetcode.com/problems/unique-email-addresses/
*/
/*
    Solution Approach:- HashMap

    Time Complexity:- O(N*M)
    Space Complexity:- O(N*M)
    N = number of emails
    M = length of email

    Explanation:-
        * For each email in the list of emails
        * We will create a new email by removing the '.' and ignoring the characters after '+' in the local name.
        * We will use a hashmap to store the new email and its count.
        * Finally, we will return the size of the hashmap which will give us the number of unique emails.
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> m;

        for(string email : emails){
            string newEmail = "";
            bool plus = false;

            for(int i = 0; i < email.size(); i++){
                if(email[i] == '.')
                    continue;
                else
                    if(email[i] == '+')
                        plus = true;
                else
                    if(email[i] == '@'){
                        newEmail += email.substr(i, email.size());
                        break;
                    }

                if(!plus)
                newEmail += email[i];
            }

            m[newEmail]++;
        }

        return m.size();
    }
};
