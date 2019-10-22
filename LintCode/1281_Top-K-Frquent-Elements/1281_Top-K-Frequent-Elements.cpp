
class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @return: the k most frequent elements
     */
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> um;  //num, freq
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) um[nums[i]]++;
        
        //for (int i = 0; i < um.size(); ++i) {
        //    pq.push({um[i].second, um[i].first});
        //}
        for (auto m : um) {
            pq.push({m.second, m.first});
        }
        
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
     
        return result;   
    }
};