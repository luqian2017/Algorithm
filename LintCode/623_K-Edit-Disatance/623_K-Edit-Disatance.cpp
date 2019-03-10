struct TrieNode {
public:    
    TrieNode() : hasWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
    
    void addWord(string & word) {
        int len = word.size();
        TrieNode *p = this;
        for (int i = 0; i < len; ++i) {
            if (!p->children[word[i] - 'a']) {
                p->children[word[i] - 'a'] = new TrieNode();
            }
            p = p->children[word[i] - 'a'];
        }
        p->hasWord = true;
        p->word = word;
    }
    
    TrieNode * children[26];
    bool hasWord;
    string word;
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        int wordCount = words.size();
        vector<string> result;
        if (wordCount == 0) return vector<string>();
        
        TrieNode * trieRoot = new TrieNode();
        for (int i = 0; i < wordCount; ++i) {
            trieRoot->addWord(words[i]);
        }
        
        int n = target.size();
        vector<int> prev(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            prev[i] = i;
        }
        
        find(trieRoot, result, k, target, prev);
        return result;
    }
    
private:
    void find(TrieNode *root, vector<string> &result, int k, string &target, vector<int> &prev) {
        int n = target.size();
        if (root->hasWord && prev[n] <= k) {
            result.push_back(root->word);
        }
        
        vector<int> next(n + 1, 0);
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                next[0] = prev[0] + 1;  //???
                for (int j = 1; j <= n; ++j) {
                    if (target[j - 1] - 'a' == i) {
                        next[j] = prev[j - 1];
                    } else {
                        next[j] = min(min(prev[j - 1], next[j - 1]), prev[j]) + 1;
                    }
                }
                find(root->children[i], result, k, target, next);
            }
        }
    }
};