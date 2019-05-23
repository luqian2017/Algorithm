class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int N = A.size();
        
        int p1 = 0, p2 = N - 1;
        int result = 0;
        
        while(p1 < p2) {
            while (A[p1] != elem && p1 < p2) {
                p1++;
            }
            if (p1 >= p2) return N - result;
            result++;
        
            while (A[p2] == elem && p1 < p2) {
                result++;
                p2--;
            }
            if (p1 >= p2) return N - result;
            
            swap(A[p1], A[p2]);
            p1++; p2--;
        }
        
        return N - result;
    }
};