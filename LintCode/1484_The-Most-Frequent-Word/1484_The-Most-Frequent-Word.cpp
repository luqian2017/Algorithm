class Solution {
public:
    /**
     * @param s: a string
     * @param excludewords: a dict
     * @return: the most frequent word
     */
    string frequentWord(string &s, unordered_set<string> &excludewords) {
        map<string, int> m; //word vs count
        
        int len = s.size();
        int maxCount = 0;
        string maxCountWord = "";
        int i = 0, j = 0;
        string word;

        while (i < len) {
            if (s[i] == ' ') while(s[i++] == ' ');

            j = s.find(' ', i);
            if (j != string::npos) {   //if found the ' '
                if ((s[j - 1] == ',') || (s[j - 1] == '.')) word = s.substr(i, j - i - 1);
                else word = s.substr(i, j - i);
            } else { //it should be the last word
                if ((s[len - 1] == ',') || (s[len - 1] == '.')) word = s.substr(i, len - i - 1);
                else word = s.substr(i, len - i);
            }
            
            if (excludewords.find(word) == excludewords.end()) {
                if (m.find(word) == m.end()) {
                    m[word] = 1;
                } else {
                    m[word]++;
                }

                if (maxCountWord.size() == 0) {
                    maxCount = m[word];
                    maxCountWord = word;
                } else if ((m[word] > maxCount)) {
                    maxCount = m[word];
                    maxCountWord = word;
                } else if (m[word] == maxCount) {
                    if (word < maxCountWord)
                        maxCountWord = word;
                }
            }
            
            if (j == string::npos) return maxCountWord;   //j = -1, reach the end of the string
            if (j > 0) i = j + 1;
            else i++;
        }
        
        return maxCountWord;
    }
};