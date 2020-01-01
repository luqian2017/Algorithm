/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here
        map<char, char> Map;
        Map['0'] = '0';
        Map['1'] = '1';
        Map['6'] = '9';
        Map['8'] = '8';
        Map['9'] = '6';
        int i = 0;
        int j = num.size() - 1;
        while(i <= j) {
            if(Map.find(num[i]) == Map.end() || Map[num[i]] != num[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};