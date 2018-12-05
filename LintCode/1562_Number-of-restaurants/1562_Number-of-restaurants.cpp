struct Node {
    int x;
    int y;
    Node(int vx = 0, int vy = 0) : x(vx), y(vy) {}
    long long distance(const Node & a, const Node & b) const {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    bool operator < (const Node &n) const {
        return distance(const_cast<Node &>(*this), Node(0,0)) < distance(n, Node(0,0));
    }
    
    bool operator == (const Node &n) const {
        return distance(const_cast<Node &>(*this), Node(0,0)) == distance(n, Node(0,0));
    }
};

class Solution {
public:


    /**
     * @param restaurant:
     * @param n:
     * @return: nothing
     */
    vector<vector<int> > nearestRestaurant(vector<vector<int> > &restaurant, int n) {
        int nRow = restaurant.size();
        vector<vector<int> > result;
        if ((nRow < n) || (n == 0)) return result;
        Node x;

        for (int i = 0; i < nRow; ++i) {
            if (i < n) {
                maxHeap.push(Node(restaurant[i][0], restaurant[i][1]));
            } else {
                x = maxHeap.top();
                if (Node(restaurant[i][0], restaurant[i][1]) < x) {
                    maxHeap.pop();
                    maxHeap.push(Node(restaurant[i][0], restaurant[i][1]));
                }
            }
        }

        Node topn = maxHeap.top();
        for (int i = 0; i < nRow; ++i) {
            if ((Node(restaurant[i][0], restaurant[i][1]) < topn) ||
                (Node(restaurant[i][0], restaurant[i][1]) == topn)) {
                vector<int> temp;
                temp.push_back(restaurant[i][0]);
                temp.push_back(restaurant[i][1]);
                result.push_back(temp);
            }
        }

        return result;
    }

private:
   // priority_queue<Node, vector<Node>, greater<Node> > minHeap;
    priority_queue<Node> maxHeap;
};