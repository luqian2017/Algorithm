class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) nums1 = nums2;
        int len_1 = nums1.size();
        if (n == 0) return;
        int pos_1 = m - 1, pos_2 = n - 1;
        int pos = len_1 - 1;
        while(pos_1 >= 0 && pos_2 >= 0) {
            if (nums1[pos_1] > nums2[pos_2]) {
                nums1[pos] = nums1[pos_1];
                pos_1--;
            } else {
                nums1[pos] = nums2[pos_2];
                pos_2--;
            } 
            pos--;    
        }
        if (pos_1 < 0) {
            for (int i = 0; i <= pos_2; i++) nums1[i] = nums2[i];
        }
        
        return;
    }
};