class Solution {
public:
    /**
     * @param ListA: The relation between ListB's books
     * @param ListB: The relation between ListA's books
     * @return: The answer
     */
    vector<string> maximumAssociationSet(vector<string> &ListA, vector<string> &ListB) {
        int n = ListA.size();
        
        for (int i = 0; i < n; ++i) {
            if (book2Id.find(ListA[i]) == book2Id.end()) {
                book2Id[ListA[i]] = globalId;
                id2Book[globalId] = ListA[i]; 
                globalId++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (book2Id.find(ListB[i]) == book2Id.end()) {
                book2Id[ListB[i]] = globalId;
                id2Book[globalId] = ListB[i]; 
                globalId++;
            }
        }

        int globalIdMax = globalId;
        father.resize(globalIdMax);
        for (int i = 0; i < globalIdMax; ++i) {
            father[i] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            int bookAId = book2Id[ListA[i]];
            int bookBId = book2Id[ListB[i]];
            merge(bookAId, bookBId);
        }
        
        vector<int> sums(globalIdMax, 0);
        int maxId = 0, maxValue = 0;
        for (int i = 0; i < globalIdMax; ++i) {
            int fx = find(i); //not father[i]!
            sums[fx]++;
            if (sums[fx] > maxValue) {
                maxId = fx;
                maxValue = sums[fx];
            }
        }
        
        vector<string> res;
        for (int i = 0; i < globalIdMax; ++i) {
            if (father[i] == maxId) {
                res.push_back(id2Book[i]);
            }
        }
        
        return res;
    }

private:
    vector<int> father;
    map<string, int> book2Id;
    map<int, string> id2Book;
    
    int globalId = 0;
    int find(int x) {
        if (father[x] == x) return x;
        father[x] = find(father[x]);
        return father[x];
    }
    
    void merge(int x, int y) {
        int fx = find(x);   //note it is not father[x]
        int fy = find(y);   //note it is not father[y]
        if (fx != fy) {
            father[fx] = fy; //not father[x] = fy;
        }
    }
};