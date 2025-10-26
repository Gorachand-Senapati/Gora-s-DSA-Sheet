class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);//first push in maxHeap
        minHeap.push(maxHeap.top());//balance by pusing largest element from min heap
        maxHeap.pop();
        //if minheap more size than max heap then again backtrack push in maxHeap
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top())/2.0;
        }
        //if odd return maxHeap top
        return maxHeap.top();
    }
};

//BFA
class MedianFinder {
private:
    // Store all numbers added so far
    vector<int> nums;

public:
    // Constructor to initialize the object
    MedianFinder() {
    }

    // Function to add a number to the data structure
    void addNum(int num) {
        // Insert the number into the list
        nums.push_back(num);
    }

    // Function to return the median of all numbers added so far
    double findMedian() {
        // Sort the list to find median
        sort(nums.begin(), nums.end());

        // Get the size of the list
        int n = nums.size();

        // If odd number of elements, return middle one
        if (n % 2 == 1) {
            return nums[n / 2];
        }

        // If even number of elements, return average of two middle elements
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};
