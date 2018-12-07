class Solution {
public:
    /**
     * @param a: the first list
     * @param b: the second list
     * @param x: the max sum
     * @return: the pairs whose sum are not exceed x
     */
    vector<vector<int>> getAns(vector<int> &a1, vector<int> &b1, int x) {
        set<int> sa(a1.begin(), a1.end());
        set<int> sb(b1.begin(), b1.end());
        a1.assign(sa.begin(), sa.end());
        b1.assign(sb.begin(), sb.end());
        
        vector<vector<int>> result;
        int maxSum = INT_MIN;
        bool targetFind = false;
        for (auto n : a1) {
            std::vector<int>::iterator lowIt = std::lower_bound(b1.begin(),  b1.end(), x - n);
            if ((lowIt!= b1.begin()) && ((n + *lowIt) > x)) lowIt--;   //as *lowIt >= (x-n)
            
            int m = *lowIt;
            int sum = n + m;
            if (sum > x) 
                continue;
            else if (sum == x) {
                if (maxSum < sum) {
                    result = {};
                    maxSum = sum;
                }
                targetFind = true;
                result.push_back({n, m});
            } else if (!targetFind) {
                if (sum > maxSum) {
                    result = {};
                    maxSum = sum;
                    result.push_back({n, m});
                }
            }
        }
        
        return result;
    }
};