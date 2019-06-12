class Solution {
public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num) {
        vector<int> pos(10, -1);
        string number = to_string(num);
        int n = number.size();
        for (int i = 0; i < n; i++) {
            pos[number[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (char j = '9'; j > number[i]; j--) {
                if (pos[j - '0'] > i) {
                    swap(number[i], number[pos[j - '0']]);
                    return stoi(number);
                }
            }
        }
        
        return num;
    }
};