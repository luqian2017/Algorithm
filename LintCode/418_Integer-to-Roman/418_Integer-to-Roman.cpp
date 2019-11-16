class Solution {
public:
    /**
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        string result;
    	string Roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    	for (int i = 0; i < 13; ++i) {
    	    while (n >= value[i]) {
    	        result += Roman[i];
    	        n -= value[i];
    	    }
    	}
    	return result;
    }
};