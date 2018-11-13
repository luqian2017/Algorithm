class Solution {
public:
    /**
     * @param s1: a string
     * @param s2: a string
     * @return: is s1 and s2 are equivalent
     */
    bool isEquivalentStrings(string &s1, string &s2) {
        
        if (s1.size() != s2.size()) 
            return false;
            
        if (s1 == s2)
            return true;
        
        int strSize=s1.size();
        
        if (strSize & 0x1)
            return false;
        
        string s1_1 = s1.substr(0, strSize/2);
        string s1_2 = s1.substr(strSize/2, strSize/2);
        string s2_1 = s2.substr(0, strSize/2);
        string s2_2 = s2.substr(strSize/2, strSize/2);
        //cout<<s1_1<<" "<<s1_2<<" "<<s2_1<<" "<<s2_2<<endl;
        
        return (isEquivalentStrings(s1_1, s2_1) && isEquivalentStrings(s1_2, s2_2)) ||
               (isEquivalentStrings(s1_1, s2_2) && isEquivalentStrings(s1_2, s2_1));
    }
    
    
};