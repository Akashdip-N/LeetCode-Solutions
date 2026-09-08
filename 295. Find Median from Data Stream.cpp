/*
    https://leetcode.com/problems/find-median-from-data-stream
*/
/*
    Solution Approach: Using Min and Max Heaps

    Time Complexity: O(logN)
    Space Complexity: O(N)
    N = number of elements in the data stream

    Intuition:-
        - We have to create a data structure such that it can perform the following:-
            i. addNum(int num) - Add a integer number from the data stream to the data structure,
                                    such that it's stored in sorted order.
            ii. findMedian() - Return the median of all elements so far,
                    a. if the size of the data stream is odd, then the middle element is the median.
                    b. If the size of the data stream is even,
                        then the median is the average of the two middle elements.
        - We have to also make sure that the operations are performed in very efficient manner.

        - We would use dual heaps to maintain the smaller and larger halves of the data stream,
            so that we can find the median in O(1) time and add new numbers in O(logN) time.

    Explanation:-
        i. AddNum() function:-
            - Taking input the number to insert into the data structure.
            - First pushing the number into the maxHeap,
                which brings the largest number to the top of the maxHeap.
            - Then pushing the top of the maxHeap into the minHeap,
                which brings the smallest number to the top of the minHeap.
            - Then popping the top of the maxHeap, which is the largest number in the maxHeap.
                (
                    Ex:-
                        maxHeap = [1, 2, 3]
                        minHeap = [4, 5, 6]

                        Adding 7 to the maxHeap, the heap would be as follows:-
                            maxHeap = [1, 2, 3, 7]

                        Pushing the top of the maxHeap (7) into the minHeap:
                            minHeap = [4, 5, 6, 7]

                        Popping the top of the maxHeap (7):
                            maxHeap = [1, 2, 3]

                        Now the heaps are as follows:-
                            maxHeap = [1, 2, 3] <- top of maxHeap = 3
                            minHeap = [4, 5, 6, 7] <- top of minHeap = 4
                )

            - Then checking if the size of the maxHeap is less than the size of the minHeap,
                then we push the top of the minHeap
                    i.e. the smallest number in the minHeap into the maxHeap,
                and pop the top of the minHeap,

                so that the maxHeap always has the same number of elements as the minHeap,
                        or one more element than the minHeap.
                (
                    Ex:-
                        maxHeap = [1, 2, 3] <- top of maxHeap = 3
                        minHeap = [4, 5, 6, 7] <- top of minHeap = 4

                        Pushing the top of the minHeap (4) into the maxHeap:
                            maxHeap = [1, 2, 3, 4]

                        Popping the top of the minHeap (4):
                            minHeap = [5, 6, 7]

                        Now the heaps are as follows:-
                            maxHeap = [1, 2, 3, 4] <- top of maxHeap = 4
                            minHeap = [5, 6, 7] <- top of minHeap = 5

                        Now if the median is called,
                            then the answer would be the top of the maxHeap, which is 4.
                )

        ii. FindMedian() function:-
            - Checking if the size of the maxHeap is greater than the size of the minHeap,
                that means we have odd number of elements in the data stream,
                    so we return the top of the maxHeap, which is the middle element.
            - If the size of the maxHeap is equal to the size of the minHeap,
                that means we have even number of elements in the data stream,
                    so we return the average of the top of the maxHeap and the top of the minHeap,
                    which are the two middle elements.
*/
class MedianFinder {
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
    public:
        MedianFinder() {}

        void addNum(int num) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double findMedian() {
            if (maxHeap.size() > minHeap.size())
                return maxHeap.top();

            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
};
