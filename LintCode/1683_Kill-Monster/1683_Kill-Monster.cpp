#include <list>

//struct Monster{
//    vector<int> vec;
//    bool isUsed;
//    Monster(const vector<int> &v, const bool & u) : vec(v), isUsed(u) {}
//};

class Solution {
public:
    /**
     * @param n: 
     * @param v: 
     * @return: nothing
     */
    int killMonster(int n, vector<vector<int>> &v) {
        int result = 0;
        list<vector<int>> monsterList;
        for (int i = 1; i < v.size(); ++i) {
            monsterList.push_back(v[i]);
        }
        bool okTokill = true;

        while(okTokill) {
            okTokill = false;
			auto iter = monsterList.begin();
            while (iter != monsterList.end()) {
                if (canKill(v[0], *iter)) {
                        add(v[0], *iter);
                        monsterList.erase(iter++);
					//	iter++;
                        okTokill = true;
                        result++;
                 } else {
                    iter++;
                }
            }
        }
        return result;
    }

private:
    bool canKill(vector<int> &altman, vector<int> &monster) {
        for (int i = 0; i < 5; ++i) {
            if (altman[i] < monster[i]) return false;
        }
        return true;
    }
    
    void add(vector<int> &altman, vector<int> &monster) {
        for (int i = 0; i < 5; ++i) {
            altman[i] += monster[i];
        }
    }
};