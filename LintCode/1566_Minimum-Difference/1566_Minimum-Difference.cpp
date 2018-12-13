
struct Node {
    int val;
    int rowIndex;
    int colIndex;
    Node(int v = 0, int r = 0, int c = 0) : val(v), rowIndex(r), colIndex(c) {} 
    friend bool operator > (const Node &a, const Node &b);
    friend bool operator < (const Node &a, const Node &b);
    friend bool operator == (const Node &a, const Node &b);
};
    
inline bool operator > (const Node &a, const Node &b) {
    return a.val > b.val;
}
    
inline bool operator < (const Node &a, const Node &b) {
    return a.val < b.val;
}
    
inline bool operator == (const Node &a, const Node &b) {
    return a.val == b.val;
}


class Solution {
public:
    /**
     * @param array: a 2D array
     * @return: the minimum difference
     */
 
    int minimumDifference(vector<vector<int>> &array) {
        int rLen = array.size();
        if (rLen == 0) return 0;
        
        int cLen = array[0].size();
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;  //min-Heap

        int minV = INT_MAX;
        int maxV = INT_MIN;
        int minDiff = INT_MAX;
        const int totalCount = rLen * cLen;
        
        for (int r = 0; r < rLen; ++r) {
            pq.push(Node(array[r][0], r, 0));
            maxV = max(maxV, array[r][0]);
        }
        minDiff = min(minDiff, abs(maxV - pq.top().val));
        int count = rLen;
        vector<int> pointers(rLen, 1);
        
        while(count <= totalCount) { 
            int rowIndex = pq.top().rowIndex;
            if (pointers[rowIndex] < cLen - 1) pointers[rowIndex]++;
            Node candidate = Node(array[rowIndex][pointers[rowIndex]], 
                                   rowIndex, 
                                   pointers[rowIndex]);
            
            maxV = max(maxV, candidate.val);
            pq.pop();
            pq.push(candidate);
            int newDiff = abs(maxV - pq.top().val);
            minDiff = min(minDiff, newDiff);
            count++;
        }   
        
        return minDiff;
    }
};