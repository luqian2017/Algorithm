class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for(int i = 1; i <= n; i++){
            res.push_back(curr);
            int currtimes10 = curr * 10;
            if (currtimes10 <= n) {
                curr = currtimes10;
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++;
            } else {
                //if it has more than one 9 in the end
                while ((curr / 10) % 10 == 9) { //100099=>10009
                    curr /= 10;
                }
                
                //as long as the last digit is 9 (and it * 10 > n)
                curr = curr / 10 + 1;  //finally, (100099=>1001) //10009=>1001 
            }
        }
        return res;
    }
    
};