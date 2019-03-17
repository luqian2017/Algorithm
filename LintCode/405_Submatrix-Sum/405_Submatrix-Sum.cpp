class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> rowSums(m, vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            rowSums[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSums[i][j] = rowSums[i - 1][j] + matrix[i][j];
            }
        }
        
        vector<int> tempList(n, 0);
        vector<vector<int>> result(2, vector<int>(2, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                vector<int> tempResult = subArraySum(rowSums[j]);
                if (tempResult.size() != 0) {
                        result[0][0] = 0;
                        result[0][1] = tempResult[0];
                        result[1][0] = j;
                        result[1][1] = tempResult[1];
                        return result;
                }
                
                for (int k = 0; k < n; ++k) {
                    if (j == i) {
                        tempList[k] = rowSums[j][k];
                    } else {
                        tempList[k] = rowSums[j][k] - rowSums[i][k];    
                    }
                }
                tempResult = subArraySum(tempList);
                if (tempResult.size() != 0) {
                    if (j == i)
                        result[0][0] = i;
                    else
                        result[0][0] = i + 1;
                    result[0][1] = tempResult[0];
                    result[1][0] = j;
                    result[1][1] = tempResult[1];
                    return result;
                }
                       
            }
        }
        return vector<vector<int>>(2, vector<int>(2));
    }
    
private:
    vector<int> subArraySum(vector<int> &list) {
        int n = list.size();
        vector<int> result;
        if (n == 0) return vector<int>();
        long long sum = 0;
        
        unordered_map<long long, int> preSums; //presum, index
        for (int i = 0; i < n; ++i) {
            sum += list[i];
            if (sum == 0) return vector<int>{0, i};
            if (preSums.find(sum) != preSums.end()) {
                result.push_back(preSums[sum] + 1);
                result.push_back(i);
                break;
            }
            preSums[sum] = i;
        }
        return result;
    } 
};