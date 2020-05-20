class Solution {
public:
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
    int countArrangement(int N) {
        vector<bool> visited(N + 1, false);
        int res = 0;
        helper(visited, 1, res);
        return res;
    }
private:
    void helper(vector<bool> & visited, int pos, int &res) {
        int N = visited.size() - 1;
        if (pos > N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue;
            if (i % pos == 0 || pos % i == 0) {
                visited[i] = true;
                helper(visited, pos + 1, res);
                visited[i] = false;
            }
        }
    }
};