class Solution {
public:
    /**
     * @param words: a list of words
     * @param word1: a string
     * @param word2: a string
     * @return: the shortest distance between word1 and word2 in the list
     */
    int shortestWordDistance(vector<string> &words, string &word1, string &word2) {
            int n = words.size();
            if (n == 0) return INT_MAX;
            
            int p1 = -1, old_p1 = -1, p2 = -1, distance = INT_MAX;

            for (int i = 0; i < n; ++i) {
                                      
                if (words[i] == word1) {
                    old_p1 = p1;
                    p1 = i;
                }
                
                if (words[i] == word2) {
                    p2 = i;   
                }
                
                if (p1 != -1 && p2 != -1) {
                    if (word1 == word2 && old_p1 != -1 && old_p1 != p1) {
                        distance = min(distance, abs(p1 - old_p1));    
                    } else if (p1 != p2) {
                        distance = min(distance, abs(p2 - p1));
                    }
                }
            }
            
            return distance;
    }
};