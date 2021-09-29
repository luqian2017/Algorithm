class StockSpanner {
public:
    StockSpanner() {
        
    }
    /**
     * @param price: 
     * @return: int
     */
    int next(int price) {
        int res = 0;
        v.push_back(price);
        while (!s.empty() && v[s.top()] <= price) {
            s.pop();
        }
        if (!s.empty()) {
            res = v.size() - s.top() - 1;
        }
        else {
            res = v.size();
        }
        
        s.push(v.size() - 1);
        return res;
    }
private:
    stack<int> s;
    vector<int> v;
};