struct ResultType {
    int value;
    int index;
    ResultType(int v = 0, int i = 0) : value(v), index(i) {}
};

struct cmp {
    bool operator() (ResultType & a, ResultType & b) {
        if (a.value < b.value) return true;
        if (a.value == b.value) return a.index < b.index;
        return false;
    }  
} compare;

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return vector<int>();
        vector<ResultType> nums2;
        for (int i = 0; i < n; ++i) {
            nums2.push_back(ResultType(nums[i], i));
        }
        sort(nums2.begin(), nums2.end(), compare);
        int p1 = 0, p2 = 1;
        if (target < 0) target = -target;
        
        while(p2 < n) {
            int diff = nums2[p2].value - nums2[p1].value;
            if (diff == target) {
                return vector<int>{min(nums2[p1].index, nums2[p2].index) + 1, max(nums2[p1].index, nums2[p2].index) + 1};
            } else if (diff < target) {
                p2++;
            } else {
                p1++;
                if (p1 == p2) p2++;
            }
        }
        return vector<int>();
    }
};