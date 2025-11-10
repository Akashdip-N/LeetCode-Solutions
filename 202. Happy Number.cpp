/*
    https://leetcode.com/problems/happy-number/
*/
/*
    Solution Approach:- Using Set to detect cycle

    Time Complexity:- O(log N)
    Space Complexity:- O(log N)
    N = input number

    Explanation:-
        * We can use a set to keep track of the numbers we have seen so far.
        * We will keep calculating the sum of the squares of the digits of the number
            until we either reach 1 or we see a number that we have seen before.
        * If we reach 1, we return true.
        * If we see a number that we have seen before, we return false.
*/
class Solution {
public:
    int num_sum(int n){
        int sum = 0;

        while(n > 0){
            int dig = n % 10;
            sum += pow(dig, 2);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;

        while(s.find(n) == s.end()){
            s.insert(n);
            n = num_sum(n);

            if (n == 1) return true;
        }

        return false;
    }
};

/*******************************************************************************************/
/*
    Solution Approach:- Using Floyd's Cycle Detection Algorithm

    Time Complexity:- O(log N)
    Space Complexity:- O(1)
    N = input number

    Explanation:-
        * By observing the problem, we can see that if a number is not happy,
            it will enter into a cycle that does not include 1.
        * We can use Floyd's Cycle Detection Algorithm to detect this cycle.
        * We will use two pointers, slow and fast.
        * The slow pointer will move one step at a time, while the fast pointer will move
            two steps at a time.
        * If there is a cycle, the two pointers will eventually meet.
        * If the number is happy, the slow pointer will eventually reach 1.
*/
class Solution {
public:
    int num_sum(int n){
        int sum = 0;

        while(n > 0){
            int dig = n % 10;
            sum += pow(dig, 2);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int num) {
      int slow = num;
      int fast = num;

      do{
          slow = num_sum(slow);
          fast = num_sum(num_sum(fast));
      }while(slow!=fast);

      return (slow == 1);
    }
};
