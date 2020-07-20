
class Solution {
public:
 
    /**
     * @param n: length of sequence
     * @param q: Operating frequency
     * @param a: the sequence
     * @param b: the standard of each operation
     * @return: How many numbers are subtracted by one after each operation
     */
     vector<int> sequenceMaintenance(int n, int q, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        N = a.size(), M = b.size();
        C1.resize(N + 1, 0);
        C2.resize(N + 1, 0);
        vector<int> ans;

        //initialize C1 and C2
        add(1, a[0]);
        for (int i = 2; i <= N; ++i) {
            add(i, a[i - 1] - a[i - 2]);
        }

        for (int i = 1; i <= M; ++i) {
            int pos = binarySearch(1, N, b[i - 1]);
			
            if (pos == -1) {
                ans.push_back(0);
            } else {
                ans.push_back(N - pos + 1);
                add_range(pos, N, -1);
        //        int range_sum = query_range(pos, N);
            }
        }

        return ans;
    }

private:
    int N, M;

    vector<long long> C1,C2; //分别记录 delta[i] 和 delta[i] * i
    
    int lowbit(int x) {
        return x & (-x);
    }

    void add(int pos, int val)
    {
        for(int i = pos; i <= N; i += lowbit(i)) {
            C1[i] += val;
            C2[i] += val * pos;
        }
    }
    
    //区间[l,r]加上x
    void add_range(int l, int r, int x) {
        add(l, x);
        add(r + 1,-x);
    }
    
    long long query(int pos) {
        long long ret = 0;
        for(int i = pos; i > 0; i -= lowbit(i)) {
            ret += (pos + 1) * C1[i] - C2[i];
        }
        return ret;
    }
    
    //查询区间[l,r]的和
    long long query_range(int l,int r) {
        long long result = query(r) - query(l - 1);
        return result;
    }
    
    int binarySearch(int start, int end, int target) {
        while (start + 1 < end){
              int mid = (start + end) / 2;
            if (query_range(mid, mid) >= target){
                end = mid;
            } else {
                start = mid;
            }
        }
        if (query_range(start, start) >= target) return start;
        if (query_range(end, end) >= target) return end;
        return -1;
    }
};