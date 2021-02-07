class Solution {
public:
    int fa[100005];
    int ans = 0;
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
        //return fa[x] = {x == fa[x] ? x : get(fa[x])};
    }
    
    void merge(int a, int b) {
        int fatherA = find(a);
        int fatherB = find(b);
        if (fatherA != fatherB) {
            fa[fatherA] = fatherB;
            ans--;
        }
        //if (fa[get(a)] == fa[get(b)]) return ;
        //fa[get(a)] = fa[get(b)];
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int l = connections.size();
        if (l < n - 1) return -1;
        ans = n - 1;
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < l; i++) {
            merge(connections[i][0], connections[i][1]);
        }
        return ans;
    }
};