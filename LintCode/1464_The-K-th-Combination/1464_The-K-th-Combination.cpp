class Solution {
public:
    /**
     * @param n: The integer n
     * @param k: The integer k
     * @return: Return the combination
     */
    vector<int> getCombination(int n, int k) {
        vector<int> vol;
        helper(n, k, 1, vol);
        return res;
    }
private:
    vector<int> res;
    int cnt = 0;
    void helper(int n, int k, int pos, vector<int> &vol) {        
        if (!res.empty()) return;
        if (vol.size() == (n >> 1)) {    
            cnt++;
            if (cnt == k) {
                res = vol;
            }
            return;
        }
        for (int i = pos; i <= n; i++) {
            vol.push_back(i);
            helper(n, k, i + 1, vol); 
            vol.pop_back();
        }
        return;
    }
};