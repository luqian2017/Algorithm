class MinStack {
public:
    MinStack() {
        minElem = INT_MAX;
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        if (mp.find(number) == mp.end()) {
            mp[number] = 1;   
        } else {
            mp[number]++;
        }
        minElem = std::min(minElem, number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (!s.empty()) {
            int topElem = s.top();
            s.pop();
            
            if (mp[topElem] == 1) {
                mp.erase(topElem);
                if (mp.empty()) {
                    minElem = INT_MAX;
                } else {
                    minElem = mp.begin()->first;
                }
            } else {
                mp[topElem]--;
            }

            return topElem;
        }
    }

    /*
     * @return: An integer
     */
    int min() {
        return minElem;
    }
private:
    stack<int> s;
    map<int, int> mp;  //number, count
    int minElem;
};