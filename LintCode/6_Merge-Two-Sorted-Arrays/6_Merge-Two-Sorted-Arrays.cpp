class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<int> result;
        vector<int>::iterator p1 = A.begin(), p2 = B.begin();
        while(p1 != A.end() && p2 != B.end()) {
            if (*p1 < *p2) {
                result.push_back(*p1);
                p1++;
            } else {
                result.push_back(*p2);
                p2++;
            }
        }
        if (p1 < A.end()) {
            result.insert(result.end(), p1, A.end());
        } else {
            result.insert(result.end(), p2, B.end());
        }
        return result;
    }
};