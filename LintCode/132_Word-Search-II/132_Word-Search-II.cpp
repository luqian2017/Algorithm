
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
    map<string, bool> prefixSets; //放所有的prefix，如果是word就对应true，否则对应false

    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        vector<string> result;

        if (board.size() < 1)  //比if (board.empty()) 更好？
            return result;

        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); ++i) 
            visited.push_back(vector<bool>(board[i].size(), false));

        getPrefixSets(words);

        set<string> wordSet;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i][j] = true;
                //char->string 不可以用to_string,否则就是 100->"100"
                helper(board, visited, i, j, string(1, board[i][j]), wordSet); //注意string(1,c)
                visited[i][j] = false;
            }
        }

        for (auto w : wordSet)
            result.push_back(w);

        return result;
    }

private:
    //generate the map
    void getPrefixSets(vector<string> &words) {
        for (auto w : words) {
            for (int i = 0; i < w.size() - 1; ++i) {  //不需要到w.size()，因为整个word下面会处理
                string prefix = w.substr(0, i + 1); //前i + 1个字符
                if (prefixSets.find(prefix) == prefixSets.end()) //关键！有可能某个word刚好是之前某个prefix，这样可以避免该word被关联到false！
                    prefixSets[prefix] = false;
            }
            prefixSets[w] = true;
        }
    }

    void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, string word, set<string> &wordSet) {
        if (prefixSets.find(word) == prefixSets.end())  //如果不是prefix, 剪枝
            return;

        if (prefixSets[word]) 
            wordSet.insert(word);

        for (int i = 0; i < 4; ++i) {
            int adjX = x + dx[i];
            int adjY = y + dy[i];

            if (!inside(board, adjX, adjY) || visited[adjX][adjY])  // 出界或已访问，剪枝
                continue;

            visited[adjX][adjY] = true;
            helper(board, visited, adjX, adjY, word + board[adjX][adjY], wordSet);
            visited[adjX][adjY] = false;
        }
    }

    bool inside(vector<vector<char>> &board, int x, int y) {
        return x >= 0 &&
               x < board.size() &&
               y >= 0 &&
               y < board[0].size();
    }        
};