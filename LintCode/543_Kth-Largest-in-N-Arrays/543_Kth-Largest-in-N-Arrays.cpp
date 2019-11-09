struct Node {
    int value;
    int fromArray;
    int index;
    Node (int v = 0, int f = 0, int i = 0) : value(v), fromArray(f), index(i) {}
};

struct cmp {
    bool operator() (const Node &a, const Node &b) {
        return a.value < b.value;  //maxHeap
    }
};

class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        int n = arrays.size();
        
        priority_queue<Node, vector<Node>, cmp> maxHeap;
        for (int i = 0; i < n; ++i) {
            if (arrays[i].size() > 0) {
                sort(arrays[i].begin(), arrays[i].end(), greater<int>());
                maxHeap.push(Node(arrays[i][0], i));
            }
        }
        int count = 0;
        while(maxHeap.size() > 0) {
            Node topNode = maxHeap.top();
            count++;
            if (count == k) return topNode.value;
            
            maxHeap.pop();
            if (topNode.index < arrays[topNode.fromArray].size() - 1) {
                maxHeap.push(Node(arrays[topNode.fromArray][topNode.index + 1], topNode.fromArray, topNode.index + 1));
            }
            
        }
        
        
    }
};