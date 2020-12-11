class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        //data_stream.assign(nums.begin(), nums.end());
        for (auto n : nums) {
            if (minHeap.size() == k) {
                if (n > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(n);
                }
            } else {
                minHeap.push(n);
            }
        }
        
    }
    
    int add(int val) {
        if (minHeap.size() == k) {
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
        } else {
            minHeap.push(val);
        }
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    //vector<int> data_stream;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */