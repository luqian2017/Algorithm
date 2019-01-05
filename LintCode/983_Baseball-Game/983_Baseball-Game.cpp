class Solution {
public:
    /**
     * @param ops: the list of operations
     * @return:  the sum of the points you could get in all the rounds
     */
    int calPoints(vector<string> &ops) {
        
        int len = ops.size();
        if (len == 0) return 0;
        
        int sum = 0;
        stack<string> s;
        
        for (int i = 0; i < len; ++i) {
            if ((ops[i][0] >= '0' && ops[i][0] <= '9') || (ops[i][0] == '-')) {    //it is number   
                s.push(ops[i]);
                sum += stoi(ops[i]);
            } else if (ops[i][0] == 'C') {
                if (!s.empty()) {
                    int topNum = stoi(s.top());
                    s.pop();
                    sum -= topNum;
                }
            } else if (ops[i][0] == 'D') {
                if (!s.empty()) {
                    int num = stoi(s.top()) << 1;
                    s.push(to_string(num));
                    sum += num;
                }
            } else if (ops[i][0] == '+') {
                if (!s.empty()) {
                    int topNum = stoi(s.top());
                    s.pop();
                    if (!s.empty()) {
                        int addNum = stoi(s.top()) + topNum;
                        s.push(to_string(topNum));
                        s.push(to_string(addNum));
                        sum += addNum;
                    }
                }
            }  
        }
        
        return sum;
    }
};