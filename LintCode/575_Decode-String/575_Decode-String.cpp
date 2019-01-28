class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        stack<int> stackNum;
        stack<string> stackStr;
        
        string result;
        string str;
        int num = 0;
        
        int len = s.size();

        for (int i = 0; i < len; ++i) {
            if ((s[i] >= '0') && (s[i] <= '9')) {
                num = num * 10 + s[i] - '0';
                
            } else if (s[i] == ']') {
                int count = stackNum.top();
                stackNum.pop();
  
                for (int i = 0; i < count; ++i) {
                    stackStr.top() += str;     
                }
                 
                str = stackStr.top();
                stackStr.pop();
                
            } else if (s[i] == '[') {  //new str starts
                stackNum.push(num);
                stackStr.push(str);
                num = 0;
                str.clear();
                
            } else {
                str = str + s[i];  //read the letters into str
            }
          
        }

        return str;
    }
};