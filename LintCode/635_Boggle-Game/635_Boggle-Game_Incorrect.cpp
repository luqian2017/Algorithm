class Solution {
public:
    /*
     * @param board: a list of lists of character
     * @param words: a list of string
     * @return: an integer
     */
    int boggleGame(vector<vector<char>> &board, vector<string> &words) {
        int nRow = board.size();
        if (nRow == 0) return 0;
        if (words.size() == 0) return 0;
        maxWordSize = 0;
        
        for (auto w : words) {
            wordSet.insert(w);
            for (int i = 1; i <= w.size(); ++i) {
                prefixSet.insert(w.substr(0, i));
            }
            maxWordSize = max(maxWordSize, (int)w.size());
        }
        
        int nCol = board[0].size();
        visited.resize(nRow, vector<int>(nCol, 0));
        string curStr;
        
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (!visited[i][j]) {
                    
                    curStr = board[i][j];
                    dfs(board, curStr, i, j, words);
                }
            }
        }
        
        return foundWords.size();
    }

private:
    bool dfs(vector<vector<char>> &board, string &curStr, int x, int y, vector<string> &words) {
     //   cout<<": x="<<x<<" y="<<y<<" curStr="<<curStr<<" "<<visited[1][6]<<endl;
        if (visited[x][y] || prefixSet.find(curStr) == prefixSet.end()) {
             curStr.resize(curStr.size() - 1);
             return false;   
        }
        
        visited[x][y] = 1;
        
        if (wordSet.find(curStr) != wordSet.end()) {
            cout<<"-   x="<<x<<" y="<<y<<" curStr="<<curStr<<" "<<visited[1][6]<<endl;
            foundWords.insert(curStr);
            return true;
        }

        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        bool result;
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (inBoard(board, newX, newY) &&  !visited[newX][newY]) {
                if (curStr.size() == maxWordSize) continue;
                
                curStr = curStr + board[newX][newY];
             //   occupied[newX][newY] = 1;
                result = dfs(board, curStr, newX, newY, words);
                
                if (result) {
                    break;
                }
            }
        }
        
       // visited[x][y] = 0;
        if (!result) visited[x][y] = 0;
        return result;
    }
    
    bool inBoard(vector<vector<char>> &board, int x, int y) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    
    vector<vector<int>> visited;
    multiset<string> foundWords;
    set<string> wordSet;
    set<string> prefixSet;
    int maxWordSize;
};