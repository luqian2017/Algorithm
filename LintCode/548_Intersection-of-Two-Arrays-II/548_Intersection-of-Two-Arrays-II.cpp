class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int M = nums1.size();
        int N = nums2.size();
        
        if (M == 0 || N == 0) return vector<int>();
        
        vector<int> & large = (M >= N) ? nums1 : nums2;
        vector<int> & small = (M < N) ? nums1 : nums2;
    
        unordered_map<int, int> umLarge; //(number, freq)
        
        for (int i = 0; i < large.size(); ++i) {
            if (umLarge.find(large[i]) == umLarge.end()) {
                umLarge[large[i]] = 1;
            } else {
                umLarge[large[i]]++;
            }
        }

        vector<int> result;
        
        for (int i = 0; i < small.size(); ++i) {
            if (umLarge.find(small[i]) != umLarge.end() &&
                umLarge[small[i]] > 0) {
                    result.push_back(small[i]);
                    umLarge[small[i]]--;
                }   
        }
        
        return result;    
    }

};