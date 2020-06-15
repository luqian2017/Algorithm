class Solution {
public:
    /**
     * @param s: string
     * @return: sort string in lexicographical order
     */
    string sorting(string &s) {
        int n = s.size();
        stringstream ss(s);
        string buf;
        vector<string> words;
        while(getline(ss, buf, ',')) {
            words.push_back(buf);
        }

        string result;
        for (auto w : words)
            result = result + w + ',';
        result.pop_back();
        
        return result;
    }
};