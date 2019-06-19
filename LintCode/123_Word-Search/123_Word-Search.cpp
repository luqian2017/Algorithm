class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {

        if (board.size() * board[0].size() < word.size()) return false;
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, word, visited, 0, i, j)) return true;
            }
        }
        
        return false;
    }

private:
    bool helper(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, 
                int index, int x, int y) {
        if (word[index] == board[x][y]) {
            if (index == word.size() - 1) {
                return true;
            }
        } else {
            return false;
        }
        
        visited[x][y] = true;

        if (x + 1 < board.size() && !visited[x + 1][y]) {
            if (helper(board, word, visited, index + 1, x + 1, y)) return true; 
        }

        if (x > 0 && !visited[x - 1][y]) {
            if (helper(board, word, visited, index + 1, x - 1, y)) return true;
        }

        if (y + 1 < board[0].size() && !visited[x][y + 1]) {
            if (helper(board, word, visited, index + 1, x, y + 1)) return true;
        }

        if ((y > 0) && !visited[x][y - 1]) {
            if (helper(board, word, visited, index + 1, x, y - 1)) return true;
        }

        visited[x][y] = false;
        return false;
    }
};