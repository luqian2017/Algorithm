class Solution {
public:
    /**
     * @param prices: a list of integer
     * @return: return the actual prices
     */
    vector<int> FinalDiscountedPrice(vector<int> &prices) {
        int n = prices.size();
        vector<int> result(n);
        
        stack<int> s;
        for(int i = 0; i < n; ++i) result[i] = prices[i];
        
        for (int i = 0; i < n; ++i) {
            while(!s.empty() && prices[i] <= prices[s.top()]) {
                int top_index = s.top();
                s.pop();
                result[top_index] = prices[top_index] - prices[i];
            }
            
            s.push(i);
        }
        
        return result;
    }
};