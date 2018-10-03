class cmp {
public:
    // to ensure a min-heap, otherwise it is max-heap by default
    bool operator() (tuple<int, int, int> &a, tuple<int, int, int> &b) {
        return get<2>(a) > get<2>(b);  
    }
};


class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        
        tuple<int, int,  int>  tp;   //tuple<i,j,k> => k = arrays[i][j]
        priority_queue<tuple<int, int, int>, vector<tuple<int, int ,int>>, cmp> pq;
        vector<int> result;
        
        int arrayLen = arrays.size();
        for (int i  = 0; i < arrayLen; ++i) {
            if (arrays[i].size() != 0) {
                pq.push(make_tuple(i, 0, arrays[i][0]));
            }
        }
        
        while(!pq.empty()) {
            tuple<int, int, int> elem = pq.top();
            pq.pop();
            result.push_back(get<2>(elem));
            get<1>(elem)++;
            if (get<1>(elem) < arrays[get<0>(elem)].size()) {
                pq.push(make_tuple(get<0>(elem),
                                   get<1>(elem),
                                   arrays[get<0>(elem)][get<1>(elem)]));
            }
            
        }
        
        return result;
    }
};