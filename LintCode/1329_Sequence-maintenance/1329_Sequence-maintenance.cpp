class Solution {
public:
    /**
     * @param n: length of sequence
     * @param q: Operating frequency
     * @param a: the sequence
     * @param b: the standard of each operation
     * @return: How many numbers are subtracted by one after each operation
     */
 void build(vector<int> &sum,vector<int> &a,int l,int r,int rt)
    {
        if(l == r)
        {
            sum[rt] = a[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(sum, a, l, m, 2 * rt);
        build(sum, a, m + 1, r, 2 * rt + 1);
    }

    void pushDown(vector<int> &sum,vector<int> &add, int rt, int left_num, int right_num)
    {
        if(add[rt])
        {
            add[2 * rt] += add[rt];
            add[2 * rt + 1] += add[rt];
            sum[2 * rt] += add[rt] * left_num;
            sum[2 * rt + 1] += add[rt] * right_num;
            add[rt] = 0;
        }
    }

    void update(vector<int> &sum, vector<int> &add, int root_left, int root_right, int C, int query_left, int query_right, int rt)
    {
        if(root_left <= query_left && query_right <= root_right)
        {
            sum[rt] += C * (query_right - query_left + 1);
            add[rt] += C;
            return;
        }
        int m = (query_left + query_right) / 2;
        pushDown(sum, add, rt, m - query_left + 1, query_right - m); //m - l + 1 and r - m are counts needs to add the delay tag
        if(root_left <= m) update(sum, add, root_left, root_right, C, query_left, m, 2 * rt);
        if(root_right > m) update(sum, add, root_left, root_right, C, m + 1, query_right, 2 * rt + 1);
    }
    
    int query(vector<int> &sum,vector<int> &add, int root_left, int root_right, int query_left, int query_right, int rt)
    {
        if(root_left <= query_left && query_right <= root_right)
        {
            return sum[rt];
        }
        int m = (query_left + query_right) / 2;
        pushDown(sum, add, rt, m - query_left + 1, query_right - m);
        int ans = 0;
        if(root_left <= m) ans += query(sum, add, root_left, root_right, query_left, m, 2 * rt);
        if(root_right > m) ans += query(sum, add, root_left, root_right, m + 1, query_right, 2 * rt + 1);
        return ans;
    }

    vector<int> sequenceMaintenance(int n, int q, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        vector<int> sum, add, ans;
        sum.assign(4 * n, 0);
        add.assign(4 * n, 0);
        
        build(sum, a, 1, n, 1);
        
        for (int i = 0; i < q; i++){
            int left = 1, right = n, pos = -1;
            
            while (left + 1 < right){
                int m = (left + right) / 2;
                if (query(sum, add, m, m, 1, n, 1) >= b[i]){
                    right = m;
                    pos = m;
                } else {
                    left = m;
                }
            }
            
            if (query(sum, add, right, right, 1, n, 1) >= b[i]){
                pos = right;
            }
            
            if (query(sum, add, left, left, 1, n, 1) >= b[i]){
                pos = left;
            }

            if (pos == -1) {
                ans.push_back(0);
            }
            else {
                ans.push_back( n - pos + 1);
                update(sum, add, pos, n, -1, 1, n, 1);
            }
        }

        return ans;
    }
};