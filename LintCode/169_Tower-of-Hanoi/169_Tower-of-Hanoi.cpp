class Solution {
public:
    /**
     * @param n: the number of disks
     * @return: the order of moves
     */
    vector<string> towerOfHanoi(int n) {
        vector<string> result;
        hanoi(n, 'A', 'B', 'C', result);
        return result;
    }
private:
    void hanoi(int n, char c1, char c2, char c3, vector<string> & result) {
        if (n == 0) return;
        if (n == 1) {
            result.push_back(move(c1, c3));
            return;
        }
        hanoi(n - 1, c1, c3, c2, result);
        result.push_back(move(c1, c3));
        hanoi(n - 1, c2, c1, c3, result);
    }
    
    string move(char from, char to) {
        return "from " + string()+ from + " to " + string() + to;
    }
};