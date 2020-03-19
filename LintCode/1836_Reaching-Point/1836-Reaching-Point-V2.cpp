class Solution {
public:
    /**
     * @param start: a point [x, y]
     * @param target: a point [x, y]
     * @return: return True or False
     */
    bool ReachingPoints(vector<int> &start, vector<int> &target) {
        //(5,2)->(3,2)->(1,2)->(1,1)
        
        while(target[0] >= start[0] && target[1] >= start[1]) {
            if (target[0] == start[0] && target[1] == start[1]) return true;
            
            if (target[0] > target[1]) target[0] -= target[1];
            else target[1] -= target[0];
        }
        
        return false;
    }
};