struct DataType {
    int sum;
    int index;
    DataType(int s = 0, int id = 0) : sum(s), index(id) {}
};

struct cmp{
    bool operator()(DataType &a, DataType & b) {
        if (a.sum < b.sum) return true;
        else return false;
    }
} compare;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return vector<int>();
        vector<DataType> data(n);
        data[0].sum = nums[0];
        data[0].index = 0;
        for (int i = 1; i < n; ++i) {
            data[i].sum += data[i - 1].sum + nums[i];
            data[i].index = i;
        }
        
        sort(data.begin(), data.end(), compare);
        
        int minDiff = INT_MAX;
        int minStartIndex = 0, minEndIndex = 0;
        
        for (int i = 1; i < n; ++i) {
            int diff = data[i].sum - data[i - 1].sum;
            if (abs(minDiff) > abs(diff)) {
                minDiff = diff;
                minStartIndex = min(data[i - 1].index, data[i].index) + 1;
                minEndIndex = max(data[i - 1].index, data[i].index);
            }
        }
        
        return vector<int>{minStartIndex, minEndIndex};
    }
};