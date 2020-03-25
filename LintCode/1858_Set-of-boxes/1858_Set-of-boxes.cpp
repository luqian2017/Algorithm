struct Node {
    int x;
    int y;
    Node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator < (const Node & a) {
        if (x < a.x) return true;
        else if (x == a.x) return y < a.y;
        return false;
    }
};


class Solution {
public:
    /**
     * @param boxes: 
     * @return: the number of boxes
     */
    int maxBoxes(vector<vector<int>> &boxes) {
        int n = boxes.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            if (boxes[i][1] > boxes[i][0]) {
                swap(boxes[i][0], boxes[i][1]);
            }
            nodes[i] = Node(boxes[i][0], boxes[i][1]);
        }
        sort(nodes.begin(), nodes.end()); 
        
        int maxLayers = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nodes[i].x > nodes[j].x && nodes[i].y > nodes[j].y) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLayers = max(maxLayers, dp[i]);
        }
        return maxLayers;
    }
};