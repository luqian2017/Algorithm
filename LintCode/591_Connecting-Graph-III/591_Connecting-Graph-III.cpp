class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    ConnectingGraph3(int n) {
        father.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
        count = n; //total # of connected components
    }
     
    void connect(int a, int b) {
        int fatherA = find(a);
        int fatherB = find(b);
        if (fatherA != fatherB) {
            father[fatherA] = fatherB;    //not father[a] = father[b], not father[a] = fatherB
            count--;
        }
    }

    /**
     * @return: An integer
     */
    int query() {
        return count;
    }

private:
    vector<int> father;
    int count;
    int find(int x) {
        if (father[x] == x) return x;
        int x2 = x;
                
        while(x != father[x]) {
            x = father[x];
        }
        
        //path compression!!!
        while(x2 != x) {    
            int temp = father[x2];
            father[x2] = x;
            x2 = temp;
        }
        
        return x;
    }
    
};