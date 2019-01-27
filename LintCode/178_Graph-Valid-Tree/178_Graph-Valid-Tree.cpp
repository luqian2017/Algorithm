class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        
        int m = edges.size();
        if (n != m + 1) return false;
        
        count = n;
        father.resize(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
        
        for (int i = 0; i < m; ++i) {
            collect(edges[i][0], edges[i][1]);
        }
        
        return count == 1;
    }
    
private:
   vector<int> father;
   int count;
   int find(int k) {
       if (father[k] == k) return k;
       //path compression
       return father[k] = find(father[k]);
   }
   
   void collect(int a, int b) {
       int fatherA = find(a);
       int fatherB = find(b);
       if (fatherA != fatherB) {
           father[fatherA] = fatherB;
           count--;
       }
   }
    
};