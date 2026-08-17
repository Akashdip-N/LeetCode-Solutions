/*
    https://leetcode.com/problems/validate-ip-address/
*/
/*
    Solution Approach:- Using String Stream

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = Size of the input query

    Intuition:-
        - The input query can be either IPv4 or IPv6 or neither.
        - For IPv4, the following conditions must be satisfied:-
            i. The query must contain exactly 3 dots ('.') and 4 segments.
            ii. Each segment must be a valid integer between 0 and 255.
            iii. Each segment must not have leading zeros (except for the number 0 itself).

            Ex:-
                i. 192.168.1.1 (Valid IPv4 address)
                    Because it satisfies all the above conditions.

                ii. 192.168.01.1 (Invalid IPv4 address)
                    Because it has a leading zero in the third segment '01'.

        - For IPv6, the following conditions must be satisfied:-
            i. The query must contain exactly 7 colons (':') and 8 segments.
            ii. Each segment must be a valid hexadecimal number (0-9, a-f, A-F)
            iii. Each segment must not be empty and must not exceed 4 characters in length.

            Ex:-
                i. 2001:0db8:85a3:0000:0000:8a2e:0370:7334 (Valid IPv6 address)
                    Because it satisfies all the above conditions.

                ii. 2001:0db8:85a3::8a2e:0370:7334 (Invalid IPv6 address)
                    Because it has an empty segment between the two colons '::'.

        - Using string stream, we can split the input query into segments.
        - For IPv4 we split by '.' and for IPv6 we split by ':'.

    Explanation:-
        * First checking if the query contains '.' or ':' to determine if it is IPv4 or IPv6.
        * If it contains '.', we check for IPv4 conditions,
            i. Couting the number of segments and checking if it is 4.
            ii. With stringstream taking each segment,
                - Checking if the segment is empty or has more than 3 characters.
                - Checking if the segment has leading zeros.
                - Checking if the segment contains only digits.
                - Converting the segment to an integer
                - Checking if it is a valid integer between 0 and 255.
            iii. At the end checking if the last character is not '.' to avoid edge cases.
        * If it contains ':', we check for IPv6 conditions,
            i. Couting the number of segments and checking if it is 8.
            ii. With stringstream taking each segment,
                - Checking if the segment is empty or has more than 4 characters.
                - Checking if the segment is a valid hexadecimal number.
            iii. At the end checking if the last character is not ':' to avoid edge cases.
        * If none of the above conditions are satisfied, we return "Neither".
*/
class Solution {
public:
    string validIPAddress(string queryIP) {
        string ipType = "Neither";
        int size = queryIP.size();

        if(queryIP.find(".") != string::npos){
            if(count(queryIP.begin(), queryIP.end(), '.') != 3)
                return ipType;

            stringstream ss(queryIP);
            string segment;
            int count = 0;

            while (getline(ss, segment, '.')) {
                count++;

                if (segment.empty() || segment.size() > 3)
                    return "Neither";

                if (segment.size() > 1 && segment[0] == '0')
                    return "Neither";

                for (char c : segment)
                    if (!isdigit(c))
                        return "Neither";

                int val = stoi(segment);
                if (val < 0 || val > 255)
                    return "Neither";
            }

            return (count == 4 && queryIP.back() != '.') ? "IPv4" : "Neither";
        }
        else
            if(queryIP.find(":") != string::npos){
                if (count(queryIP.begin(), queryIP.end(), ':') != 7)
                    return "Neither";

                stringstream ss(queryIP);
                string segment;
                int count = 0;

                while (getline(ss, segment, ':')) {
                    count++;

                    if (segment.empty() || segment.size() > 4)
                        return "Neither";

                    for (char c : segment)
                        if (!isxdigit(c))
                            return "Neither";
                }

                return (count == 8 && queryIP.back() != ':') ? "IPv6" : "Neither";
        }

        return "Neither";
    }
};
