class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int len = pages.size();
        
        int maxPage = 0, sum = 0;
        
        for (int i = 0; i < len; ++i) {
            maxPage = max(maxPage, pages[i]);
            sum += pages[i];
        }
        
        int left = maxPage, right = sum;
        
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (checkValid(pages, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        if (checkValid(pages, left, k)) return left;
        return right;
    }
    
    bool checkValid(vector<int> &pages, int limit, int k) {
        int count = 1;
        int sum = 0;
        int len = pages.size();
        for (int i = 0; i < len; ++i) {
            if (pages[i] > limit) return false;
            if (pages[i] + sum > limit) {
                count++;
                sum = pages[i];
            } else {
                sum += pages[i];
            }
        }
        
        return count <= k;
    }
    
    
    
};