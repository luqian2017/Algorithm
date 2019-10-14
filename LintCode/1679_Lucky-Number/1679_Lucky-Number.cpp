1679. Lucky Number
cat-only-icon
CAT Only
中文English
People usually think that a number that only contains 3 or 5 is a lucky number.

Now given an integer n, and you need to find the smallest lucky number that is not less than N and the number of occurrences of 3 in this lucky number is the same as the number of occurrences of 5.

Example
Example 1:

Input: n = "3500"
Output: "3535"
Explanation: 
  The smallest lucky number is 3533, but the number of occurrences of 3 is not equal to the number of occurrences of 5.
  The second smallest lucky number is 3535, and the number of occurrences of 3 is equal to the number of occurrences of 5.
Example 2:

Input: n = "1"
Output: "35"
Notice
1 ≤ n ≤ 10^100000

class Solution {
public:
    /**
     * @param n: the n
     * @return: the smallest lucky number  that is not less than n
     */
    string luckyNumber(string &n) {
        string strN;
        string result;
        int len = n.size();
        int origLen = len;
        
        bool foundIt = false;
        
        if (len & 0x1) len++; 
        
        for (int i = 0; i < (len >> 1); ++i) {
            strN = strN + '3';
        }
        
        for (int i = 0; i < (len >> 1); ++i) {
            strN = strN + '5';
        }
        
        if (origLen & 0x1) {
            return strN;
        }
        cout<<"len = "<<len<<endl;
        do {
            if (strN.compare(n) >= 0) {
                result = strN;
                foundIt = true;
                break;
            }
        } while(next_permutation(strN.begin(), strN.end()));
        
        if (!foundIt) {
            result = '3' + result + '5';    
        }

        return result;
    }
};