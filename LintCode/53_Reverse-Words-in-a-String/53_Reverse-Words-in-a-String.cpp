class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        
        vector<string> words;
        string result;
        
        int len = s.size();
        int pos = -1;
        
        for (int i = 1; i < len; ++i) {
            if ((s[i] == ' ') && (s[i - 1] != ' ')) {
                words.push_back(' ' + s.substr(pos + 1, i - pos - 1));
                pos = i;
            } else if ((s[i] == ' ') && (s[i - 1] == ' ')) {
                pos = i;
            }
        }
        
        words.push_back(' ' + s.substr(pos + 1, len - pos - 1));
        
        //reverse(words.begin(), words.end());
        int index = words.size() - 1; // find the last word
        //remove the leading ' '
        if (words[index][0] == ' ') words[index] = words[index].substr(1, words[index].size() - 1);
        
        for (auto w : words)
            result = w + result;
            
        return result;    
    }
};