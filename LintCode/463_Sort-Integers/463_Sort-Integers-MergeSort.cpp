class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        int n = A.size();
        if (n == 0) return;
        vector<int> temp(n, 0);
        mergeSort(A, 0, n - 1, temp);
    }
    
private:
    void mergeSort(vector<int> &A, int start, int end, vector<int> &buf) {
        if (start >= end) return;//???
        int mid = start + (end - start) / 2;
        mergeSort(A, start, mid, buf);
        mergeSort(A, mid + 1, end, buf);
        merge(A, start, end, buf);
    }
    
    void merge(vector<int> &A, int start, int end, vector<int> &buf) {
        int mid = start + (end - start) / 2;
        int left = start;
        int right = mid + 1;
        int index = left;
        
        while(left <= mid && right <= end) {
            if (A[left] <= A[right]) {
                buf[index++] = A[left++];
            } else {
                buf[index++] = A[right++];
            }
        }
        
        while(left <= mid) {
            buf[index++] = A[left++];
        }
        
        while(right <= end) {
            buf[index++] = A[right++];
        }
        
        //remember to copy buf back to A
        //cannot directly use A = buf!
        for (int i = start; i <= end; ++i) {
            A[i] = buf[i];
        }
    }
};