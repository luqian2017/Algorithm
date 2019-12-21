class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iter1 = v1.begin();
        v1End = v1.end();
        iter2 = v2.begin();
        v2End = v2.end();
        iter = v1.end();
    }

    /*
     * @return: An integer
     */
    int next() {
        if (hasNext()) {
            if (iter1 != v1End && iter2 != v2End) {
                if (iter == v1End) { //initial state
                    iter = iter1++;
                } else if (iter == iter1 - 1) {
                    iter = iter2++;
                } else {
                    iter = iter1++;
                }
            } else if (iter1 != v1End) {
                iter = iter1++;
            } else { // if (iter2 != v2End) {
                iter = iter2++;
            }
        }
        return *iter;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return !(iter1 == v1End && iter2 == v2End);
    }

private:
    vector<int>::iterator iter, iter1, iter2, v1End, v2End;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */