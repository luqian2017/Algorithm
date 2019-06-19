class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        int n = s.size();
        if (n == 0) return "";
        
        string result;
        
        int beginPos = 0, endPos = n - 1;
        //while(!isalnum(s[beginPos])) beginPos++;
        while(s[beginPos] == ' ') beginPos++;
        //while(!isalnum(s[endPos])) endPos--;
        while(s[endPos] == ' ') endPos--;
        
        s = s.substr(beginPos, endPos - beginPos + 1);
        n = s.size();

        
        beginPos = 0, endPos = 1;
        while (endPos < n) {
            while(s[endPos] != ' ' && endPos < n) endPos++;
            
            if (result.size() == 0)
                result = s.substr(beginPos, endPos - beginPos);
            else
                result = s.substr(beginPos, endPos - beginPos) + ' ' + result;

            while(s[endPos] == ' ' && endPos < n) endPos++;
            beginPos = endPos;
        }

        return result;
    }

    
};