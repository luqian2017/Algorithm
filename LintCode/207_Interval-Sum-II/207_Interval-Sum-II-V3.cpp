class BinaryIndexTree {
public:
    vector<int> C;
    int len;
    BinaryIndexTree(vector<int> & nums) {
        len = nums.size();
        C.resize(len + 1);
        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }
    
    void add(int index, int value) {
        index++;
        for (int i = index; i <= len; i += lowbit(i)) {
            C[i] += value;
        }
    }
    
    long long presum(int index) {
        long long result = 0;
        index++;
        for (int i = index; i > 0; i -= lowbit(i)) {
            result += C[i];
        }
        return result;
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        pBit = new BinaryIndexTree(A);
        this->A = A;
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return pBit->presum(end) - pBit->presum(start - 1);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        pBit->add(index, value - A[index]);
        A[index] = value;
    }

private:
    BinaryIndexTree * pBit;
    vector<int> A;
};