class Solution {
public:
    /**
     * @param prices: a list of integer
     * @return: return the actual prices
     */
    vector<int> FinalDiscountedPrice(vector<int> &prices) {
       int n = prices.size();
       vector<int> result = prices;
       stack<int> s;
       
       for (int i = 0; i < n; ++i) {
           while(!s.empty() && prices[s.top()] >= prices[i]) {
               int prev = s.top(); s.pop();
               result[prev] = prices[prev] - prices[i];
           }
           s.push(i);
       }

       return result;
    }
};