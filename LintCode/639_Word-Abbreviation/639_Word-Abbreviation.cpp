class Solution {
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        int n = dict.size();
        int round = 1;
        vector<string> result(n);
        
        for (int i = 0; i < n; ++i) {
            result[i] = abbreviate(dict[i], round);
            abbrMap[result[i]].push_back(i);
        }
        
        while(1) {
            bool duplicate = false;
            round++;
            for (int i = 0; i < n; ++i) {
                if (abbrMap[result[i]].size() > 1) {
                    duplicate = true;
                    //abbrMap[result[i]]--;
                    result[i] = abbreviate(dict[i], round);
                    
                    abbrMap[result[i]].push_back(i);
                }
            }

            if (!duplicate) break;
        }
        
        return result;
    }

private:
    map<string, vector<int>> abbrMap;  //abbr, vector of index of original words

    string abbreviate(string word, int round) {
        int n = word.size();
        //if (n <= 3) return word;
        if (round + 2 >= word.size()) return word;
        return word.substr(0, round) + to_string(n - round - 1) + word[n - 1];
    }
};