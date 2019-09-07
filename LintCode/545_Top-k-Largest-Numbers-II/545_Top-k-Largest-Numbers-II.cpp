class Solution {
public:
    /*
    * @param k: An integer
    */
    Solution(int k) {
        this->k = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else {
            if (num > minHeap.top()) {
                minHeap.push(num);
                minHeap.pop();
            }
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap2 = minHeap;
        while(minHeap2.size() > 0) {
            int top = minHeap2.top();
            minHeap2.pop();
            result.push_back(top);
        }
        reverse(result.begin(),result.end());
        return result;
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};