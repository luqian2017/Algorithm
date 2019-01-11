class MinStack {
public:
    MinStack() : min_num(INT_MAX) {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        if (number < min_num) {
            min_num = number;
            mp[number] = 1;
        } else if (number == min_num) {
            mp[number]++;
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (!s.empty()) {
            int topNum = s.top();
            s.pop();
            if (topNum == min_num) {
                if (mp[topNum] == 1) {
                    mp.erase(topNum);
                    if (!mp.empty())
                        min_num = mp.begin()->first;
                    else
                        min_num = INT_MAX;
                } else {
                    mp[topNum]--;
                }
            }
            return topNum;
        }
    }

    /*
     * @return: An integer
     */
    int min() {
        return min_num;
    }

private:
    stack<int> s;
    int min_num;
    unordered_map<int, int> mp;  //num, freq
};