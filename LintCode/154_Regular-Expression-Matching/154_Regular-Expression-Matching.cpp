
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
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        if (s.empty() || p.empty()) return false;
        
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

        // if s reaches the end first
        // for example, s = "abb", p = "a**?*?*..." or p = "a*"
        if (sIndex == s.size()) {
            for (int i = pIndex; i < p.size(); i += 2) {  //note i+=2 as it can be abbz*x*y*...
                if (((i + 1) >= p.size()) || (p[i + 1] != '*')) return false;
            }
            return true;
        }

        if (vm[sIndex][pIndex].visited) return vm[sIndex][pIndex].memo;

        vm[sIndex][pIndex].visited = true;
        
        if ((pIndex + 1 < p.size()) && (p[pIndex + 1] == '*')) {
            if ((s[sIndex] == p[pIndex]) || (p[pIndex] == '.')) 
                // * presents one or more preceding element
                vm[sIndex][pIndex].memo = helper(s, sIndex + 1, p, pIndex, vm);
            
            //for example: s = "abc", p = "a*abc"
            //s[1] and p[0..1] match fail, but we have second chance.
            if (!vm[sIndex][pIndex].memo) 
                // * represents zero preceding element
                vm[sIndex][pIndex].memo = helper(s, sIndex, p, pIndex + 2, vm);
        #if 0
            if (helper(s, sIndex, p, pIndex + 2, vm)) 
                vm[sIndex][pIndex].memo = true;
            else {
                if ((s[sIndex] == p[pIndex]) || (p[pIndex] == '.')) 
                    vm[sIndex][pIndex].memo = helper(s, sIndex + 1, p, pIndex, vm);
                else
                    vm[sIndex][pIndex].memo = false;
            }
        #endif    
        } else {
            if ((s[sIndex] == p[pIndex]) || (p[pIndex] == '.'))
                vm[sIndex][pIndex].memo = helper(s, sIndex + 1, p, pIndex + 1, vm);
            else
                vm[sIndex][pIndex].memo = false;
        }

        return vm[sIndex][pIndex].memo;
    }
};

