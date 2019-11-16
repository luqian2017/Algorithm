class Solution {
public:
    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        int result = 0;
    	string Roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	map<string, int> dict;
    	for (int i = 0; i < 13; ++i) {
    	    dict[Roman[i]] = value[i];
    	}
    	
    	int pos = 0;
        do {
            string substring = s.substr(pos, 2);
            if (dict.find(substring) != dict.end()) {
    	        result += dict[substring];
    	        pos += 2;
    	    } else {
    	        substring = s.substr(pos, 1);
    	        if (dict.find(substring) != dict.end()) {
    	            result += dict[substring];
    	            pos += 1;
    	        }
    	    }
        } while( pos < s.size());      

    	return result;
    }
};