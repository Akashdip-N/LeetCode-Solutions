/*
    https://leetcode.com/problems/find-median-from-data-stream
*/
/*
    Solution Approach:      Using vector & sorting method
                        (GOOD APPROACH, BUT BAD FOR LARGE INPUTS)

    Time Complexity: O(NlogN)
    Space Complexity: O(N)
    N = number of elements in the data stream

    Explanation:-
        * This is not a optimal solution.
        * This would have issue when the input size is large.
 */
class MedianFinder {
private:
    vector<int> arr;
public:
    MedianFinder() {}

    void addNum(int num) {
        arr.push_back(num);
    }

    double findMedian() {
        int size = arr.size();
        sort(arr.begin(), arr.end());

        if (size % 2 == 0)
            return (static_cast<double>(arr[(size / 2) - 1]) + static_cast<double>(arr[size / 2])) / 2.0;
        else
            return arr[size / 2];
    }
};

/**************************************************************************************************************/
/*
    Solution Approach: Using two heaps (maxHeap and minHeap) to maintain the median

    Time Complexity: O(logN)
    Space Complexity: O(N)
    N = number of elements in the data stream

    Explanation:-
        * Using two heaps (maxHeap and minHeap) to maintain the smaller and larger halves of the data stream.
        * This will ensure that we can find the median in O(1) time and add new numbers in O(logN) time.
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
        // We have odd number of elements in the data stream, so the median is the top of the maxHeap
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
