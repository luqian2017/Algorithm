class Solution {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
    int InsertFive(int a) {
        string a_str = to_string(a);

        bool occured = false;
        int n = a_str.size();
        if (a >= 0) {
            for (int i = 0; i < n; ++i) {
                if (a_str[i] == '+') continue;
                if (a_str[i] - '0' < 5) {
                    a_str.insert(i, "5");
                    occured = true;
                    break;
                }
            }
            if (!occured) a_str = a_str + '5';
        } else {
            for (int i = 0; i < n; ++i) {
                if (a_str[i] == '-') continue;
                if (a_str[i] - '0' > 5) {
                    a_str.insert(i, "5");
                    occured = true;
                    break;
                }
            }
            if (!occured) {
                a_str = a_str + '5';
            }
        }
        return atoi(a_str.c_str());
    }
};