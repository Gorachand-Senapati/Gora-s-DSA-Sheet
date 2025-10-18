class minHeap {
private:
    // Priority queue with smallest element at top
    priority_queue<int, vector<int>, greater<int>> pq;//because for minHeap we use greater<int> and it store as a vector type list 
    //for do maxHeap only write priority_queue<int> pq; because by default it is maxHeap
public:
    void push(int x) {
        pq.push(x);
    }

    void pop() {
        if (!pq.empty()) pq.pop();
    }

    int peek() {
        if (pq.empty()) return -1;
        return pq.top();
    }

    int size() {
        return pq.size();
    }
};