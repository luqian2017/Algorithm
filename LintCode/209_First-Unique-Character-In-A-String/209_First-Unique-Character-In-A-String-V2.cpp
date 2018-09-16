class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        map<char, int> hashmap; //<char, count>
        int strSize = str.size();

        for (int i = 0; i < strSize; ++i) {
            if (hashmap.find(str[i]) == hashmap.end()) {
                hashmap[str[i]] = 1;

            } else {
                hashmap[str[i]]++;
            }
        }

        for (int i = 0; i < strSize; ++i) {
            if (hashmap[str[i]] == 1) return str[i];
        }
    }
};