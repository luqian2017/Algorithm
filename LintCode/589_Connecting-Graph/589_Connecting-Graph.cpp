class ConnectingGraph {
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        father.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            father[i] = i;
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
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        return find(a) == find(b);
    }
    
private:
    vector<int> father;
    int find(int x) {
        if (father[x] == x) return x;
        
        while(father[x] != x) {
            x = father[x];
        }
        
        return x;
    }
};