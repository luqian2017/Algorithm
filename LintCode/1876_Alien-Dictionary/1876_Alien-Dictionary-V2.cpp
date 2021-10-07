unordered_map<char, int> dict;
struct Node {
    Node(string s) : str(s) {}
    bool operator < (const Node &node) {
        int nSize = min(str.size(), node.str.size());
        for (int i = 0; i < nSize; ++i) {
            if (dict[str[i]] < dict[node.str[i]]) return true;
            if (dict[str[i]] > dict[node.str[i]]) return false;
        }
        if (str.size() <= node.str.size()) return true;
        else return false;
    }
    string str;
};

class Solution {
public:
    /**
     * @param words: the array of string means the list of words
     * @param order: a string indicate the order of letters
     * @return: return true or false
     */
    bool isAlienSorted(vector<string> &words, string &order) {
        
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        vector<Node> nodes;
        for (int i = 0; i < words.size(); ++i) {
            nodes.push_back(Node(words[i]));
        }

        sort(nodes.begin(), nodes.end());
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] != nodes[i].str) return false;
        }
        return true;
    }

};