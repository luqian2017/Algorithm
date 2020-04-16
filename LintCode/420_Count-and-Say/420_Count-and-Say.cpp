class Solution {
public:
    /**
     * @param n: the nth
     * @return: the nth sequence
     */
    string countAndSay(int n) {
        if (n <= 0) return "";
        string result = "1";
        for (int i = 2; i <= n; ++i) {
            int len = result.size();
            char curChar = result[0];
            int curPos = 0;
            int count = 0;
            string newResult = "";

            while(curPos < len) {
                while (curPos < len && result[curPos] == curChar) {
                    curPos++;
                    count++;
                }

                newResult += to_string(count);
                newResult += curChar;
                
                if (curPos < len) {
                    curChar = result[curPos];
                    count = 0;
                }
            }
            result = newResult;
        }
        return result;
    }
};