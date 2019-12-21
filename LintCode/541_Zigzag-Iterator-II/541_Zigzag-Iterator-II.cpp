class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */
    ZigzagIterator2(vector<vector<int>>& vecs) {
        vecsSize = vecs.size();
        pollIndex = -1;
        iters.resize(vecsSize);
        iterEnds.resize(vecsSize);
        for (int i = 0; i < vecsSize; ++i) {
            iters[i] = vecs[i].begin();
            iterEnds[i] = vecs[i].end();
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        if (hasNext()) {

            for (int i = pollIndex + 1; i < vecsSize; ++i) {
                if (iters[i] != iterEnds[i]) {
                    pollIndex = i;
                    return *(iters[i]++);
                }
            }
            
            for (int i = 0; i <= pollIndex; ++i) {
                if (iters[i] != iterEnds[i]) {
                    pollIndex = i;            
                    return *(iters[i]++);
                }
            }
        }
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        for (int i = max(0, pollIndex); i < vecsSize; ++i) {
            if (iters[i] != iterEnds[i]) return true;
        }
        for (int i = 0; i <= pollIndex; ++i) {
            if (iters[i] != iterEnds[i]) return true;
        }
        return false;
    }
    
private:
    vector<vector<int>::iterator> iters, iterEnds;
    
    //vector<vector<int>>::iterator pollIter, pollIterEnd;
    int pollIndex, vecsSize;
};
/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */