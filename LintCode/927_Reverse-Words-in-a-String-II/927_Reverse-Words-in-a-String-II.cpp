class Solution {
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    string reverseWords(string &str) {
        string result;
        int startPos = -1, endPos = 0;
        size_t len = str.size();
        
        while (endPos < len) {
  
            endPos = str.find(' ', endPos + 1);
            if (startPos >= 0)
                result = str.substr(startPos + 1, endPos - startPos - 1) + ' ' + result;
            else 
                result = str.substr(startPos + 1, endPos);

            startPos = endPos;
        }
        return result;
    }
};