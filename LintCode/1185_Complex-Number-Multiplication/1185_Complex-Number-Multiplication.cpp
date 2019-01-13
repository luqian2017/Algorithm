class Solution {
public:
    /**
     * @param a: a string
     * @param b: a string
     * @return: a string representing their multiplication
     */
    string complexNumberMultiply(string &a, string &b) {
        string aR, bR;
        string aV, bV;
        size_t pos;
        
        pos = a.find_first_of('+');
        aR = a.substr(0, pos);
        aV = a.substr(pos + 1);
        aV.pop_back();     //remove 'i', the same as aV = aV.sub_str(0, aV.size() - 1);
    
        pos = b.find_first_of('+');
        bR = b.substr(0, pos);
        bV = b.substr(pos + 1);
        bV.pop_back();
        
        int aR_int = stoi(aR);
        int aV_int = stoi(aV);
        int bR_int = stoi(bR);
        int bV_int = stoi(bV);
        
        return to_string(aR_int * bR_int - aV_int * bV_int) + 
                 "+" + 
                 to_string(aR_int * bV_int + aV_int * bR_int) +
                 "i";
    }
};