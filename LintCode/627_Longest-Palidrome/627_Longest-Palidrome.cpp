int longestPalindrome(string &s) {
    if (s.size()==0) return 0;
    int sumLen=0;
    int oddNum=0;

    unordered_map<char, int> hashmap;
    for (int i=0; i<s.size(); ++i) {
        if (hashmap.find(s[i])!=hashmap.end()) {
            hashmap[s[i]]++;    
        } else {
            hashmap[s[i]]=1;
        }
    }

    for (auto h : hashmap) {
        if (h.second & 0x1) {
            oddNum++;
            sumLen += h.second-1;
        } 

        if (!(h.second & 0x1)) {
            sumLen += h.second;
        } 
    }

    return oddNum? sumLen+1 : sumLen;
}
