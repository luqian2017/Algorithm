
class Solution {
public:
    /*
     * @param board: a list of lists of character
     * @param words: a list of string
     * @return: an integer
     */
    int boggleGame(vector<vector<char>> &board, vector<string> &words) {
        vector<string> matchStrings;
        
        if (board.size() == 0) return 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        getPrefixSets(words);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, visited, 0);
            }
        }
        
        return g_maxCount;
    }
    
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    map<string, bool> prefixSets;
    int g_maxCount = 0;
    
    void getPrefixSets(vector<string> & words) {
        for (auto w : words) {
            for (int i = 0; i < w.size(); ++i) {
                string prefix = w.substr(0, i + 1);
                if (prefixSets.find(prefix) == prefixSets.end())
                    prefixSets[prefix] = false;
                    
            }
            
            prefixSets[w] = true;
        }
    }
    
    
    void dfs(vector<vector<char> > &board, int x, int y, 
             vector<vector<bool>>& visited, int count) {
                 
        int m = board.size();
        int n = board[0].size();
        for (int i = x; i < m; ++i) {
            for (int j = y; j < n; ++j) {
                vector<vector<int>> paths;
                vector<int> path;
                findNextWord(board, i, j, visited, string(1, board[i][j]), path, paths, count);
                for (auto p : paths) {
                    for (int pos : p) {
                        visited[pos / n][pos % n] = true;
                    }
                    
                    dfs(board, i, j, visited, count + 1);
                    
                    for (int pos : p)
                    {
                        visited[pos / n][pos % n] = false;
                    }
                }
            }
            y = 0;
        }
    }
    
    void findNextWord(vector<vector<char>> &board, int i, int j,
                      vector<vector<bool>>& visited,
                      string word,
                      vector<int>& path,
                      vector<vector<int>>& paths, int count) {
        char c = board[i][j];
        if (visited[i][j] || (prefixSets.find(word) == prefixSets.end())) {
            return;
        }
        
        int m = board.size();
        int n = board[i].size();
        path.push_back(i * n + j);
        if (prefixSets[word]) {
            paths.push_back(path);
            g_maxCount = max(g_maxCount, count + 1);
        } else {
             visited[i][j] = true;
            if (i > 0) {
                findNextWord(board, i - 1, j, visited, word + board[i - 1][j], path, paths, count);
            }
            if (i < board.size() - 1) {
                findNextWord(board, i + 1, j, visited, word + board[i + 1][j], path, paths, count);
            }
            if (j > 0) {
                findNextWord(board, i, j - 1, visited, word + board[i][j - 1], path, paths, count);
            }
            if (j < board[i].size() - 1) {
                findNextWord(board, i, j + 1, visited, word + board[i][j + 1], path, paths, count);
            }
            visited[i][j] = false;
        }
        path.pop_back();
    }    
};