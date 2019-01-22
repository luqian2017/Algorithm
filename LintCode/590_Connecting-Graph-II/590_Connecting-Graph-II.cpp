class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        father.resize(n + 1);
        nodeNum.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
            nodeNum[i] = 1;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            father[rootA] = rootB;
            nodeNum[rootB] += nodeNum[rootA];
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
    //    return nodeNum[father[a]];    //wrong!!!
        return nodeNum[find(a)];
    }
    
private:
    vector<int> father;
    vector<int> nodeNum;
    
    //find the root of x
    int find(int x) {
        int x2 = x;
        
        if (father[x] == x) return x;
        
        while(father[x] != x) {
            x = father[x];
        }
        
        //path compression
        while (x2 != x) {
            int temp = father[x2];
            father[x2] = x;
            x2 = temp;
        }
        
        return x;
    }
};