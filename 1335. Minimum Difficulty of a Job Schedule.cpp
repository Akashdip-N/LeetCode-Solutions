/*
    https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
*/
/*
    Solution Approach:- Using Dynamic Programming & Memoization

    Time Complexity:- O(N^2 * D)
    Space Complexity:- O(N * D)
    N = number of jobs
    D = number of days

    Intuition:-
        - We have been given a list of jobs with their respective difficulties
        - Also we have been given a number of days which we have to take to complete all the jobs.
        - We have to find the minimum difficulty of a job schedule.
        - The difficulty of a day is determined by the maximum difficulty of a job done on that day.
        - The total difficulty of a job schedule is the sum of the difficulties of each day.

        - What we can do is we can split the jobs into d days,
            and for each day we can find the maximum difficulty of the jobs done on that day.
        - We would use a memoization technique to store and
            find the minimum difficulty of a job schedule for a given index and
                number of days left.
        - At the end we would return the minimum difficulty of a job schedule
            for the given index and number of days left.

    Explanation:-
        * Main function:-
            - Checking base case if the number of days is greater than the number of jobs,
                then we cannot complete all the jobs in the given days,
                    so we return -1.
            - Initializing the memoization table with -1.
            - Calling the helper function with the following parameters:-
                i. Job difficulty array
                ii. Current index (0)
                iii. Number of days left (d)

        * Creating a memoization table to store the job difficulty for
            the given index and number of days left.
            (
                The size of the table is 301 x 11 because,
                    maximum number of jobs is 300 and
                    maximum number of days is 10
            )

        * Helper function:-
            - Base case:-
                * If no more days left and we have completed all the jobs,
                    then we return 0.
                * If no more days left or we have reached the end of the job difficulty array,
                        then we return a large number (1e9)
                    (
                        because we cannot complete all the jobs in the given days,
                        and this would be ignored when we use the min function.
                    )

            - If the value for the current index and the number of days left
                is not -1, then we return the value from the memoization table.
            - We iterate through all the jobs from the current index till the
                size of the job array - number of days left.
                (
                    Since every remaining day must get at least 1 job,
                        we must save at least d - 1 jobs for the future d - 1 days.
                    Hence, j <= size - daysLeft
                )
            - For each,
                i. first we initialize the current day max to 0 or
                    the maximum difficulty of the jobs done on that day.
                ii. Then we find the remaining cost by calling the helper function,
                    with the next index and number of days left - 1.
                iii. Then we find the minimum total difficulty by taking the minimum of
                    the current day max and the remaining cost.
            - Finally, we store the minimum total difficulty in the memoization table
                and return the value.
*/
class Solution {
    private:
        int memo[301][11];

        int dfs(
            const vector<int>& jobDifficulty,
            int i,
            int daysLeft
        ) {
            int size = jobDifficulty.size();

            if(daysLeft == 0){
                if(i == size)
                    return 0;
                else
                    return 1e9;
            }

            if (memo[i][daysLeft] != -1)
                return memo[i][daysLeft];

            int currentDayMax = 0;
            int minTotalDifficulty = 1e9;

            for (int j = i; j <= size - daysLeft; j++) {
                currentDayMax = max(currentDayMax, jobDifficulty[j]);
                int remainingCost = dfs(jobDifficulty, j + 1, daysLeft - 1);
                minTotalDifficulty = min(minTotalDifficulty, currentDayMax + remainingCost);
            }

            return memo[i][daysLeft] = minTotalDifficulty;
        }

    public:
        int minDifficulty(vector<int>& jobDifficulty, int d) {
            if (jobDifficulty.size() < d)
                    return -1;

            for(int i = 0; i < 301; i++)
                for(int j = 0; j < 11; j++)
                    memo[i][j] = -1;

            return dfs(jobDifficulty, 0, d);
        }
};
