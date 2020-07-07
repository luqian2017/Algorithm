class Solution {
public:
    /**
     * @param n: length of sequence
     * @param q: Operating frequency
     * @param a: the sequence
     * @param b: the standard of each operation
     * @return: How many numbers are subtracted by one after each operation
     */
 void build(vector<int> &sum,vector<int> &a,int left,int right,int root)
    {
        if (left == right)
        {
            sum[root] = a[left - 1];
            return;
        }
        int mid = (left + right) / 2;
        build(sum, a, left, mid, 2 * root);
        build(sum, a, mid + 1, right, 2 * root + 1);
    }

    void pushDown(vector<int> &sum,vector<int> &add, int root, int left_num, int right_num)
    {
        if (add[root])
        {
            add[2 * root] += add[root];
            add[2 * root + 1] += add[root];
            sum[2 * root] += add[root] * left_num;
            sum[2 * root + 1] += add[root] * right_num;
            add[root] = 0;
        }
    }

    void update(vector<int> &sum, vector<int> &add, int root_left, int root_right, int C, int query_left, int query_right, int root)
    {
        if (root_left <= query_left && query_right <= root_right)
        {
            sum[root] += C * (query_right - query_left + 1);
            add[root] += C;
            return;
        }
        int mid = (query_left + query_right) / 2;
        pushDown(sum, add, root, mid - query_left + 1, query_right - mid); //m - l + 1 and r - m are counts needs to add the delay tag
        if (root_left <= mid) update(sum, add, root_left, root_right, C, query_left, mid, 2 * root);
        if (root_right > mid) update(sum, add, root_left, root_right, C, mid + 1, query_right, 2 * root + 1);
    }
    
    int query(vector<int> &sum,vector<int> &add, int root_left, int root_right, int query_left, int query_right, int root)
    {
        if (root_left <= query_left && query_right <= root_right)
        {
            return sum[root];
        }
        int mid = (query_left + query_right) / 2;
        pushDown(sum, add, root, mid - query_left + 1, query_right - mid);
        int ans = 0;
        if (root_left <= mid) ans += query(sum, add, root_left, root_right, query_left, mid, 2 * root);
        if (root_right > mid) ans += query(sum, add, root_left, root_right, mid + 1, query_right, 2 * root + 1);
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
                int mid = (left + right) / 2;
                if (query(sum, add, mid, mid, 1, n, 1) >= b[i]){
                    right = mid;
                    pos = mid;
                } else {
                    left = mid;
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