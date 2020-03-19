struct Node {
      int x;
      int y;
      Node() : x(0), y(0) {}
      Node(int a, int b) : x(a), y(b) {}
  };
 

class Solution {
public:
    /**
     * @param start: a point [x, y]
     * @param target: a point [x, y]
     * @return: return True or False
     */
    bool ReachingPoints(vector<int> &start, vector<int> &target) {
        int targetX = target[0], targetY = target[1];
        set<pair<int,int>> s;
        queue<Node> q;
        q.push(Node(start[0], start[1]));
        s.insert({start[0], start[1]});
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            if ((node.x == targetX && node.y == targetY)) return true;
            if ((node.x > targetX && node.y > targetY)) return false;
            int newV = node.x + node.y;
            if (newV <= targetX) {
                if (s.find({newV, node.y}) == s.end())
                    q.push(Node(newV, node.y));
            }
            if (newV <= targetY) {
                if (s.find({node.x, newV}) == s.end())
                    q.push(Node(node.x, newV));
            }
            
        }
        
        return false;
    }
};