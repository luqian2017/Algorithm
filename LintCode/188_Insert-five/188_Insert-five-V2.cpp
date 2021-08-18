class Solution {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
    int InsertFive(int a) {
        bool positive = true;
        int ret = 0;
        if (a < 0) {
            positive = false;
            a = -a;
        }
        string str = to_string(a);
        if (positive) {
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] < '5') {
                    string res = str.substr(0, i) + '5' + str.substr(i);
                    ret = atoi(res.c_str());
                    return ret;
                }
            }
            return a * 10 + 5;
        } else {
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] > '5') {
                    string res = str.substr(0, i) + '5' + str.substr(i);
                    ret = atoi(res.c_str());
                    return -ret;
                }
            }
            ret = a * 10 + 5;
            return -ret;
        }
        
    }
};