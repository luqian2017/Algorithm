class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        buf.resize(A.size(), 0);
        return mergeSort(A, buf, 0, A.size() - 1);
    }
   

private:
    long long mergeSort(vector<int> & A, vector<int> & buf, int start, int end) {
        
        if (start >= end) return 0;
        
        int result = 0;
        int mid = start + (end - start) / 2;
        
        result += mergeSort(A, buf, start, mid);
        result += mergeSort(A, buf, mid + 1, end);
        result += merge(A, buf, start, end);
        
        return result;
    }
    
    long long merge(vector<int> & A, vector<int> & buf, int start, int end) {
        int result = 0;
        int mid = start + (end - start) / 2;
        int left = start, right = mid + 1, index = start;
        
        while(left <= mid && right <= end) {
            if (A[left] <= A[right]) {
                buf[index++] = A[left++];
            } else {
                buf[index++] = A[right++];
                result += mid - left + 1;
            }
        }
        
        while(left <= mid) {
            buf[index++] = A[left++];
        }
        
        while(right <= end) {
            buf[index++] = A[right++];
        }
        
        for (index = start; index <= end; index++) {
            A[index] = buf[index];
        }
        
        return result;
    }
    
    vector<int> buf;
};