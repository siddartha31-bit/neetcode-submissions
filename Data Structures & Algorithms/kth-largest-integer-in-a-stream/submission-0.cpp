class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};