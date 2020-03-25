struct Node {
    int x;
    int y;
    Node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator < (const Node & a) {
        if (x == a.x) return y > a.y;   //note: y < a.y is wrong
        else return x < a.x;
    }
};

//return the first node that has y >= target, just like lower_bound
//int binarySearch(vector<Node> & nodes, int target) {
int binarySearch(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    int start = 0, end = nums.size() - 1;
    while(start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (nums[start] >= target) return start;
    return end;
}

class Solution {
public:
    /**
     * @param boxes: 
     * @return: the number of boxes
     */
    int maxBoxes(vector<vector<int>> &boxes) {
        int n = boxes.size();
        if (n == 0) return 0;
        vector<Node> nodes(n);
        
        for (int i = 0; i < n; ++i) {
            if (boxes[i][0] > boxes[i][1]) {
                swap(boxes[i][0], boxes[i][1]);
            }
            nodes[i] = Node(boxes[i][0], boxes[i][1]);
        }
        sort(nodes.begin(), nodes.end()); 

        vector<int> monoIncSeqs(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            int k = binarySearch(monoIncSeqs, nodes[i].y);
            //int k = lower_bound(monoIncSeqs.begin(), monoIncSeqs.end(), nodes[i].y) - monoIncSeqs.begin();
            monoIncSeqs[k] = nodes[i].y;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (monoIncSeqs[i] != INT_MAX) return i + 1;
        }

        return 0;
    }
};