class Solution {
public:
    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        string beginStr = getStr(init_state);
        string endStr = getStr(final_state);
        if (beginStr == endStr) return 0;
        
        unordered_set<string> visited;
        queue<pair<string, int>> q; //string, pos
        //pair<string, int> node = make_pair(beginStr, getZeroPos(init_state));
        //pair<string, int> node(beginStr, getZeroPos(init_state));
         pair<string, int> node = {beginStr, getZeroPos(init_state)};
        q.push(node);
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int step = 1;
        
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                node = q.front();
                string frontStr = node.first;
                q.pop();
                int x = node.second / 3;
                int y = node.second % 3;
                
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                        int newPos = newX * 3 + newY;
                        swap(frontStr[node.second], frontStr[newPos]);
                        if (visited.find(frontStr) == visited.end()) {
                            if (frontStr == endStr) {
                                return step;
                            } else {
                                visited.insert(frontStr);
                                q.push({frontStr, newPos});
                            }
                        }
                        frontStr = node.first;
                    }
                }
            }
            step++;
        }
        return -1;
    }

private:
   string getStr(vector<vector<int>> &vv) {
       string str = "";
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 3; ++j) {
               str.push_back('0' + vv[i][j]);
           }
       }
       return str;
   }
   
   int getZeroPos(vector<vector<int>> &vv) {
       int pos = 0;
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 3; ++j) {
               if (vv[i][j] == 0) {
                   return i * 3 + j;
               }
           }
       }
       return -1;
   }
   
};