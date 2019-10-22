
struct ResultType {
    int val;
    int freq;
    ResultType(int v = 0, int f = 0) : val(v), freq(f) {}
};

struct cmp {
    bool operator() (const ResultType & a, const ResultType & b) {
        if (a.freq > b.freq) {
            return true;
        } else if (a.freq == b.freq && a.val > b.val) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @return: the k most frequent elements
     */
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> um; //num, freq
        vector<int> result;
        priority_queue<ResultType, vector<ResultType>, cmp> pq;
        
        for (int i = 0; i < nums.size(); ++i) {
            um[nums[i]]++;
        }
        
        int count = 0;
        for (auto it : um) {
            pq.push(ResultType(it.first, it.second));
            if (count++ >= k) pq.pop();
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().val);
            pq.pop();
        }
        
        return result;
    }
};