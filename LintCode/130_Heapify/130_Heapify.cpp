class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        int n = A.size();
        for (int i = (n - 2) / 2; i >= 0; --i)
            min_heapify(A, i, n);
    }
    
private:
    void min_heapify(vector<int> &A, int i, int len) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        int smallest = i;
        if (left < len && A[left] < A[i]) smallest = left;
        if (right < len && A[right] < A[smallest]) smallest = right;
        
        if (smallest != i) {
            swap(A[i], A[smallest]);
            min_heapify(A, smallest, len);
        }
    }
};