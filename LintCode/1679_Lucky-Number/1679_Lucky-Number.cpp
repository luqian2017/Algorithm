class Solution {
public:
    /**
     * @param n: the n
     * @return: the smallest lucky number  that is not less than n
     */
    string luckyNumber(string &n) {
        string strN, minStr, maxStr, minStr2, minStr3;
        string result;
        int len = n.size();
        int origLen = len;
        
        bool foundIt = false;
        
        if (len & 0x1) len++; 
        
        for (int i = 0; i < (len >> 1); ++i) {
            minStr = minStr + '3';
            maxStr = maxStr + '5';
        }
        
        for (int i = (len >> 1); i < len; ++i) {
            minStr = minStr + '5';
            maxStr = maxStr + '3';
        }

        if (origLen & 0x1) {
            return minStr;
        }

        if (n[0] == '3') {
            minStr2 = string(len, '3');  //or string midStr(len, '3');
            for (int i = 0; i < len; ++i) {
                if (i & 0x1) minStr2[i] = '5';
            }
            if (n.compare(minStr) > 0 && n.compare(minStr2) < 0) minStr = minStr2;
        }
        
        if (n[0] == '5') {
            minStr2 = string(len, '5');  //or string midStr(len, '5');
            for (int i = 0; i < len; ++i) {
                if (i & 0x1) minStr2[i] = '3';
            }
            minStr3 = string(len, '3');
            minStr3[0] = '5';
            for (int i = (len >> 1) + 1; i < len; ++i) minStr3[i] = '5';
            if (n.compare(minStr) > 0 && n.compare(minStr3) < 0) minStr = minStr3;
            if (n.compare(minStr3) > 0 && n.compare(minStr2) < 0) minStr = minStr2;
        }
        
        
        strN = minStr;
        do {
            if (strN.compare(maxStr) > 0) {
                foundIt = false;
                break;
            }
            
            if (strN.compare(n) >= 0) {
                result = strN;
                foundIt = true;
                break;
            }
        } while(next_permutation(strN.begin(), strN.end()));
        
        if (!foundIt) {
            result = '3' + strN + '5';    
        }   

        return result;
    }
};
