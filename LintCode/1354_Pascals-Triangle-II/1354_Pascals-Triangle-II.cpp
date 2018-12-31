class Solution {
public:
    /**
     * @param rowIndex: a non-negative index
     * @return: the kth index row of the Pascal's triangle
     */
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if (rowIndex == 0) {
            result = {1};
            return result;
        }
        
        if (rowIndex == 1) {
            result = {1,1};
            return result;
        }
        
        vector<int> formerResult = {1, 1};
        result.push_back(1);
        for (int i = 2; i < rowIndex + 1; ++i) {

            int len = formerResult.size() - 1;
            for (int j = 0; j < len; ++j) {
                result.push_back(formerResult[j] + formerResult[j + 1]);    
            }
            result.push_back(1);
            formerResult = result;
            if (i < rowIndex) result = {1};
        }

        return result;
    }
};