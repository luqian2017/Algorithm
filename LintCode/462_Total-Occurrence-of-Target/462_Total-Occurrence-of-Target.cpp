class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return 0;
        
        int firstPos = findFirstPos(A, target);
        if (firstPos == -1) return 0;
        int lastPos = findLastPos(A, target);
        if (lastPos == -1) return 0;
        return lastPos - firstPos + 1;
    }

int findFirstPos(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return -1;
        
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            }         
        }
        
        if (A[start] == target) return start;
        if (A[end] == target) return end;
        return -1;
}


int findLastPos(vector<int> &A, int target) {
        int n = A.size();
        if (n == 0) return -1;
        
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] > target) {
                end = mid;
            } else if (A[mid] <= target) {
                start = mid;
            }         
        }
        
        if (A[end] == target) return end;
        if (A[start] == target) return start;
        return -1;
}

};