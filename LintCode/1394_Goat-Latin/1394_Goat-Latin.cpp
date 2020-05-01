class Solution {
public:
    /**
     * @param S: 
     * @return: nothing
     */
    string  toGoatLatin(string &S) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stringstream ss(S);
        string result;
        string word;
        int wordIndex = 0;
        while(ss >> word) {
            result += " " + (vowel.find(word[0]) != vowel.end() ? word : word.substr(1) + word[0]) + "ma";
            wordIndex++;
            for (int i = 0; i < wordIndex; ++i) result += "a";
        }
        
        return result.substr(1);
    }
};