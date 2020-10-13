class Solution {
public:
    /**
     * @param invitations: the invitations
     * @param inquiry: the inquiey
     * @return: nothing
     */
    vector<string> findtheInvitationn(vector<vector<int>> &invitations, vector<int> &inquiry) {
        int len = invitations.size();
        vector<vector<int>> matrix(22, vector<int>());
        vector<string> path;
        for (int i = 0; i < len; ++i) {
            matrix[invitations[i][0]].push_back(invitations[i][1]);
            matrix[invitations[i][1]].push_back(-invitations[i][0]);
        }
        
        dfs(inquiry[0], inquiry[1], matrix, path);
        return path;
    }

private:
    bool dfs(int start, int end, vector<vector<int>> & matrix, vector<string> &path, int last = -100) {
        if (start == end) return true;
        for (int i = 0; i < matrix[start].size(); i++) {
            int next = abs(matrix[start][i]);
            if (next == last) continue;
            if (matrix[start][i] > 0) path.push_back(to_string(start) + " invites " + to_string(next));
            else path.push_back(to_string(start) + " is invited by " + to_string(next));
        
            if (dfs(next, end, matrix, path, start)) return true;
            path.pop_back();
        }
        
        return false;
    }
};