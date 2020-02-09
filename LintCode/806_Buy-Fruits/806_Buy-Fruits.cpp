class Solution {
public:
    /**
     * @param codeList: The codeList
     * @param shoppingCart: The shoppingCart
     * @return: The answer
     */
    int buyFruits(vector<vector<string>> &codeList, vector<string> &shoppingCart) {
          int m = codeList.size();
          vector<string> singleList;
       
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < codeList[i].size(); ++j) {
                  singleList.push_back(codeList[i][j]);
              }
          }
          
          if (singleList.size() > shoppingCart.size()) return 0;
          for (int i = 0; i + singleList.size() <= shoppingCart.size(); ++i) {
              for (int j = 0; j < singleList.size(); ++j) {
                  if (singleList[j] != shoppingCart[i + j] && singleList[j] != "anything") break;
                  if (j == singleList.size() - 1) return 1;
              }
          }
          return 0;
    }
};