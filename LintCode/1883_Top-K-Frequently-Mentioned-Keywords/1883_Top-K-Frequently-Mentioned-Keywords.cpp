struct StrFreq {
    string str;
    int freq;
    bool operator< (const StrFreq &sf) {
        return (freq > sf.freq) || (freq == sf.freq && str < sf.str);
    }
};

class Solution {
public:
    /**
     * @param K: an integer
     * @param keywords: a list of string
     * @param reviews: a list of string
     * @return: return the top k keywords list
     */
    vector<string> TopkKeywords(int K, vector<string> &keywords, vector<string> &reviews) {
        int nkw = keywords.size();
        int nrv = reviews.size();
        for (int i = 0; i < nrv; i++) {
            transform(reviews[i].begin(), reviews[i].end(), reviews[i].begin(), ::tolower);
        }
        unordered_map<string, int> um;
        unordered_set<string> us_dict(keywords.begin(), keywords.end());
        for (int i = 0; i < nrv; i++) {
            stringstream ss(reviews[i]);
            string tmpWord, word;
            unordered_set<string> us_tmp;
            while (ss >> tmpWord) {
                if (tmpWord[tmpWord.size() - 1] < 'a' || tmpWord[tmpWord.size() - 1] > 'z') {
                    word = tmpWord.substr(0, tmpWord.size() - 1);
                } else {
                    word = tmpWord;
                }
                if (us_dict.find(word) != us_dict.end()) {
                    us_tmp.insert(word);
                }
            }
            for (auto u : us_tmp) {
                um[u]++;
            }
        }
        vector<StrFreq> pairs;
        for (auto a : um) {
            pairs.push_back({a.first, a.second});
        }
        sort(pairs.begin(), pairs.end());
        vector<string> res;
        int n = 0;
        for (auto p : pairs) {
            res.push_back(p.str);
            n++;
            if (n == K) break;
        }

        return res;
    }
};