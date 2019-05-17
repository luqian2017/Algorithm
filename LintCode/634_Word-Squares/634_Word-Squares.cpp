class Solution {
public:
  /**
   * @param words a set of words without duplicates
   * @return all word squares
   */
  
  void initPrefix(vector<string> & words) {
      int n = words.size();
      prefix[""] = words;
      for (int i = 0; i < n; ++i) {
          int m = words[i].size();
          for (int j = 0; j < m; ++j) {
              prefix[words[i].substr(0, j + 1)].push_back(words[i]);
          }
      }
  }
  
  bool checkPrefix(int index, string nextWord) {
     for (int i = index + 1; i < wordLen; ++i) {
         string pre;
         for (int j = 0; j < index; ++j) {
             pre += squares[j][i];
         }
         pre += nextWord[i];
     
         if (prefix.find(pre) == prefix.end()) {
             return false;
         }
     }
     
     return true;
  }
  
  void dfs(int index) {
    if (index == wordLen) {
        results.push_back(squares);
        return;
    }
    
    string pre;
    for (int i = 0; i < index; ++i) {
        pre += squares[i][index];
    }
    
    vector<string> matchedWords = prefix[pre];
    int m = matchedWords.size();
    for (int i = 0; i < m; ++i) {
        if (!checkPrefix(index, matchedWords[i])) {
            continue;
        }
        squares.push_back(matchedWords[i]);
        dfs(index + 1);
        squares.pop_back();
    }
  }
  
  vector<vector<string>> wordSquares(vector<string>& words) {
      if (words.size() == 0) return results;
      initPrefix(words);
      wordLen = words[0].size();
      dfs(0);
      return results;
  }
  
private:
    int wordLen;
    unordered_map<string, vector<string>> prefix;
    vector<string> squares;
    vector<vector<string>> results;
};
