/*
思路就是暴力深搜 - 每个格子来一次DFS深搜。 
注意： 
1) visited[]数组还是需要 
2) 注意剪枝：如果不是prefix，剪掉！ 如果出界或已经访问过，剪掉！ 
3) char -> string 不能直接用std里面的to_string()，因为char本来就是integer，to_string(char)会生成”100”,”103”这样的字符串。可以用string(1,c)来生成一个临时的内容为c，长度为1的字符串。 
4) 对于二维数组或vector，用if (board.size() < 1) 比if (board.empty()) 更好 
5) getPrefixSets()里面，下面一行 
if (prefixSets.find(prefix) == prefixSets.end()) 
很关键！因为有可能某个word刚好是之前某个prefix，这样可以避免该word被关联到false！
*/

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