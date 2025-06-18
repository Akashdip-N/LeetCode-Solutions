/*
    https://leetcode.com/problems/different-ways-to-add-parentheses
*/
/*
    Ex:-
        Input: "2*3-4*5"
        Output: [-34, -14, -10, -10, 10]
        Possible Combinations:
            (2*(3-(4*5))) = -34
            ((2*3)-(4*5)) = -14
            ((2*(3-4))*5) = -10
            (2*((3-4)*5)) = -10
            (((2*3)-4)*5) = 10
    --------------------------------------------------------
        Solution Approach: Using Recursion, and two pointers

        Time Complexity: O(2^n) where n is the number of operators
        Space Complexity: O(n) for recursion stack space

        Explanation:
            i. Iterate through the expression to find operators.
            ii. For each operator, split the expression into left and right parts.
            iii. Recursively compute the results for left and right parts.
            iv. Combine the results using the operator.
            v. If the expression is purely a number, convert it to an integer and return it.
            vi. Return the list of results.
*/
class Solution {
public:
    // function to get the result of the operation
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;

        return 0;
    }

    vector<int> diffWaysToCompute(string exp) {

        vector<int> results;
        bool isNumber = 1;

        for(int i = 0; i < exp.length(); i++) {
            // check if current character is an operator
            if(!isdigit(exp[i])) {

                // if current character is not a digit then
                // exp is not purely a number
                isNumber = 0;

                // list of first operands
                vector<int> left = diffWaysToCompute(exp.substr(0, i));

                // list of second operands
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                // performing operations
                for(int x : left)
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
            }
        }

        if(isNumber == 1)
            results.push_back(stoi(exp));

        return results;
    }
};
