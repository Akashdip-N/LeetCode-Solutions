/*
    https://leetcode.com/problems/text-justification/
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = number of words in the input vector

    Intuition:-
        - We have list of words and a number (maxWidth),
            we have to make sure that each lines are justified to the maxWidth length.
        - It is also said that after each word there would be atleast a single space.
        - What we would do is,
            i. Iterate over each word from the list of words.
            ii. Keep track of the words to be added in that specific line.
            iii. Sum of total size of the words to be added in that specific line.
            iv. Calulate the spaces needed to added between each word.
        - Then add the spaces and words and return the result vector of strings.

    Explanation:-
        * Using two vector,
            i. One to store the result lines (res)
            ii. One to store the words for the current line (line)
        * Iterating each word from the list of words.
        * In each iteration we would check the sum of the following,
            whether it's greater than the maxWidth or not
                (then we pass the current word into the next line):-
            i. Number of words stored in the array (i.e. number of white spaces)
            ii. Sum of length of all the words that are stored in the array.
            iii. Length of the current word that we are iterating over.

            * Then we would calculate the following:-
                i. Extra space needed to be filled for the current line.
                ii. Number of gaps needed that would the
                    number of words present for that specific line - 1.
                iii. Equally dividing the extra space by the number of gaps to
                    get the number of spaces that would be added to each gap.
                iv. Then we would find if there is any spaces that are left,
                        that couldn't be equally divided amoung the gaps
                            (i.e. odd number of spaces)
                        and we would add that to the leftmost gaps.
            * For each of the word that is present in that current line,
                adding the number of spaces to it.
            * Also adding an extra space if there is any remaining spaces
                that couldn't be equally divided amoung the gaps.
            * Then adding each word to a new string and pushing that into the result vector.
        * Then clearing the line vector and resetting the length to 0.
        * Adding the size of the current word to the length,
            and pushing the current word into the line vector.

        * For the last line, since we have to left justify it,
            adding a space after each word except the last word
                from the list of words for that specific line.
        * Then calculating the remaining spaces that needed to be added,
            and adding that to the end of the last line.
        * Pushing the last line into the result vector.
        * Returning the result vector of strings.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line;
        int length = 0;

        for(string word : words) {
            if (length + line.size() + word.size() > maxWidth) {
                int extra_space = maxWidth - length;
                int gaps = max(1, (int)line.size() - 1);
                int spaces = extra_space / gaps;
                int remainder = extra_space % gaps;

                for (int j = 0; j < gaps; j++) {
                    line[j] += string(spaces, ' ');

                    if (remainder > 0) {
                        line[j] += " ";
                        remainder--;
                    }
                }

                string formatted_line = "";
                for (const string& w : line)
                    formatted_line += w;

                res.push_back(formatted_line);

                line.clear();
                length = 0;
            }

            line.push_back(word);
            length += word.size();
        }

        string last_line = "";
        for (int k = 0; k < line.size(); k++) {
            last_line += line[k];

            if (k < line.size() - 1)
                last_line += " ";
        }

        int trail_space = maxWidth - last_line.size();
        last_line += string(trail_space, ' ');
        res.push_back(last_line);

        return res;
    }
};
