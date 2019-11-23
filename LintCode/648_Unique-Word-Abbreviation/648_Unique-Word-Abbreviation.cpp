class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */
    ValidWordAbbr(vector<string> dictionary) {
        int n = dictionary.size();
        for (int i = 0; i < n; ++i) {
            
            string tmpStr = dictionary[i];
            wordMap[tmpStr]++;
            if (tmpStr.size() < 3) 
                abrMap[tmpStr]++;
            else {
                abrMap[tmpStr[0] + to_string(tmpStr.size() - 2) + tmpStr[tmpStr.size() - 1]]++;
            }
        }

    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        string updatedWord;
        if (word.size() < 3) 
            updatedWord = word;
        else 
            updatedWord = word[0] + to_string(word.size() - 2) + word[word.size() - 1];
        
        if (abrMap.find(updatedWord) == abrMap.end()) return false;
        if (abrMap[updatedWord] == wordMap[word]) return true;
        return false;
    }
private:
    unordered_map<string, int> abrMap;
    unordered_map<string, int> wordMap;
    
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */