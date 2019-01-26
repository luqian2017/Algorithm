struct TrieNode {
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false) {
        for (int i = 0; i < 26; ++i) children[i] = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        TrieNode * cur = root;
        int len = word.size();
        
        for (int i = 0; i < len; ++i) {
            int index = word[i] - 'a';
            if (!cur->children[index]) cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        
        cur->isWord = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        int n = word.size();
        return helper(word, n, 0, root);
    }

private:
    TrieNode * root;
    
    bool helper(string & word, int n, int pos, TrieNode * cur) {
        if (!cur) return false;
        
        if (pos == n) return cur->isWord;
        
        if (word[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (helper(word, n, pos + 1, cur->children[i])) return true;
            }
        } else {
            int index = word[pos] - 'a';
            if (cur->children[index]) {
                if (helper(word, n, pos + 1, cur->children[index])) return true;
            }
        }
        
        return false;
    }
    
};
