#include <limits>

struct Node {
    int sum;
    int count;
};

class Solution {
public:
    /**
     * @param fa: the father
     * @param val: the val
     * @return: the biggest node
     */
    int treeProblem(vector<int> &fa, vector<int> &val) {
        int len = fa.size();
        if (len == 0) return 0;

        map<int, Node> mp;  //id, sum_count
        
        mp[0].sum = val[0];
        mp[0].count = 1;
        
        for (int i = 1; i < len; ++i) {
            mp[i].sum = val[i];
            mp[i].count = 1;
        }
        
        //add the sum and count to the father node
        for (int i = len - 1; i > 0; --i) {  //do not consider fa[0]=-1
            mp[fa[i] - 1].sum += mp[i].sum;
            mp[fa[i] - 1].count += mp[i].count;
        }
 
        int maxId = -1;
        double maxAve = -1 * numeric_limits<double>::max();  //from <limits>

        for (int i = 0; i < len; ++i) {
            double ave = mp[i].sum / mp[i].count;
            if (ave > maxAve) {
                maxId = i;
                maxAve = ave;
            }
        }
        
        return maxId + 1;
    }
};