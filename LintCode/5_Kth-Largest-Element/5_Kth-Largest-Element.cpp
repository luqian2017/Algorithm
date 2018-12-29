class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < len; ++i) {
            int number = nums[i];
            if (i < n) {
                pq.push(number);
            } else {
                if (number > pq.top()) {
                    pq.pop();
                    pq.push(number);
                }
            }
        }
        
        return pq.top();
    }
};