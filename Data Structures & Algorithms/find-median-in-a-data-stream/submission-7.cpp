//see again
class MedianFinder {
private:
    priority_queue<int> maxHeap;   // Smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Larger half

public:
    MedianFinder() {
    }

    void addNum(int num) {

        // Step 1: Insert into appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // Step 2: Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
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