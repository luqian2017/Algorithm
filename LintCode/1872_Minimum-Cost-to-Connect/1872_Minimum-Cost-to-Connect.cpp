class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        int len = sticks.size();
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        
        while(minHeap.size() > 1) {
            int cost = 0;
            cost += minHeap.top(); minHeap.pop();
            cost += minHeap.top(); minHeap.pop();
            minHeap.push(cost);
            sum += cost;
        }
        
        return sum;
    }
};