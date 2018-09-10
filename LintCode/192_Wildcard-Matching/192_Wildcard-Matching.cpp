
class visitedMemo {
public:
    bool visited;
    bool memo;
    visitedMemo(bool v = false, bool m = false) : visited(v), memo(m) {}
};


class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        //if (s.empty() || p.empty()) return false;
        //define vm[s.size()][p.size()]
        vector<vector<visitedMemo>> vm;
        vm.resize(s.size(), vector<visitedMemo>(p.size()));   

        return helper(s, 0, p, 0, vm); 
    }

    bool helper(string const &s, int sIndex, string const &p, int pIndex, vector<vector<visitedMemo>> &vm) {

        // if p reachees the end (pos is the last char + 1) first, s should also reaches the end
        if (pIndex  == p.size()) {
            return (sIndex == s.size());    
        }

        // if s reaches the end first, then p[pIndex..end] should be all *, 
        // for example, s = "ab", p = "a****"
        if (sIndex == s.size()) {
            for (int i = pIndex; i < p.size(); ++i) {
                if (p[i] != '*') return false;
            }
            return true;
        }

        if (vm[sIndex][pIndex].visited) return vm[sIndex][pIndex].memo;

        vm[sIndex][pIndex].visited = true;
        if (p[pIndex] == '*') {
            vm[sIndex][pIndex].memo = helper(s, sIndex + 1, p, pIndex, vm) ||
                                      helper(s, sIndex, p, pIndex + 1, vm);
        } else {
            if ((s[sIndex] == p[pIndex]) || (p[pIndex] == '?'))
                vm[sIndex][pIndex].memo = helper(s, sIndex + 1, p, pIndex + 1, vm);
            else
                vm[sIndex][pIndex].memo = false;
        }

        return vm[sIndex][pIndex].memo;
    }
};