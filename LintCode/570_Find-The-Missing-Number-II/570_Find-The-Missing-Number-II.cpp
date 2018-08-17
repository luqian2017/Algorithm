class Solution {
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    bool findIt = false; 
    int g_missingNum;

    int findMissing2(int n, string &str) {
        vector<int> visited(n+1, 0);
        helper(n, str, 0, visited);
        return g_missingNum;
    }

    void helper(int n, string &str, int index, vector<int>& visited) {
        if (index == str.size()) {
            if (findIt) return;

            int missingCount = 0;
            int missingNum;
            for (int i = 1; i <= n; ++i) {
                if (!visited[i]) {
                    missingCount++;
                    missingNum = i; 
                }
            }

            if (missingCount == 1) {
                findIt = true;
                g_missingNum = missingNum;
            }
            return;
        }

        for (int i = 1; i <= 2; ++i) {
            if (index + i <= str.size()) {
                int candidateNum = stoi(str.substr(index, i));

                if ((candidateNum <= 0) || (candidateNum > n) || 
                     visited[candidateNum] ||    //no duplicate numbers
                     (str.substr(index, i)[0] == '0')     //do not consider '0' or '09'
                    ) continue;  //剪枝 

                visited[candidateNum] = 1;
                helper(n, str, index + i, visited);
                visited[candidateNum] = 0;
            }
        }
    }
};