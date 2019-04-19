class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        int n = A.size();
        if (n == 0) return;
        
        quickSort(A, 0, n - 1);
    }
    
private:
    void quickSort(vector<int> &A, int start, int end) {
        if (start > end) return;
        int left = start, right = end;
        int pivot = A[left + (right - left) / 2];
        
        while(left <= right) {
            while(left <= right && A[left] < pivot) {
                left++;
            }    
            while(left <= right && A[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        }
        
        quickSort(A, start, right);
        quickSort(A, left, end);
    }
};