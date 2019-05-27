class Solution {
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
        
        int strSize = n.size();
        
        if (strSize == 0) return "";
        
        int ptPos = n.find_first_of('.');
        
        int intV = 0;
        double fracV = 0.0;
        
        if (ptPos != string::npos) {
            intV = atoi(n.substr(0, ptPos).c_str());
            fracV = atof(n.substr(ptPos).c_str());
        } else {
            intV = atoi(n.c_str());
        }

        string intBinStr = "";
        while(intV) {
            if (intV & 0x1) { 
                intBinStr = '1' + intBinStr;
            } else {
                intBinStr = '0' + intBinStr;
            }
            intV >>= 1;
        }
        
        //don't forget.
        if (intBinStr == "") intBinStr = "0";
        
        if (fracV == 0) return intBinStr;
        
        string fracBinStr = "";
        while (fracV) {
            if (fracBinStr.size() > 32) return "ERROR";
            
            fracV *= 2;
            if (fracV >= 1) {
                fracBinStr += '1';
                fracV -= 1;
            } else {
                fracBinStr += '0';
            }
        }
        
        return intBinStr + '.' + fracBinStr;
    }
};