class Solution {
public:
    /**
     * @param machines: an integer array representing the number of dresses in each washing machine from left to right on the line
     * @return: the minimum number of moves to make all the washing machines have the same number of dresses
     */
    int findMinMoves(vector<int> &machines) {
        int len = machines.size();
        vector<int> sums(len, 0);
        
        int averageNum = 0;
        
        sums[0] = machines[0];
        
        for (int i = 1; i < len; ++i) {
            sums[i] = sums[i - 1] + machines[i];
        }
    
        averageNum = sums[len - 1] / len;
        if (sums[len - 1] != averageNum * len) return -1;

        int optSteps = INT_MIN;
        for (int i = 0; i < len; ++i) {
            
            int gainL, gainR;
            
            gainL = (i == 0) ? 0 : sums[i - 1] - averageNum * i;
            gainR = (i == len - 1) ? 0 : sums[len - 1] - sums[i] - averageNum * (len - 1 - i); 
            
            if (gainL > 0 && gainR > 0) {
                //machine i needs to input clothes from both left side and right side, choose max as both sides can do in parallel 
                optSteps = max(optSteps, max(gainL, gainR)); 
            } else if (gainL < 0 && gainR < 0) {
                //machine  i needs to output clothes to both left side and right side. It cannot be done in parallel, so use the sum
                optSteps = max(optSteps, -gainL - gainR);
            } else {
                //machine i's one siide needs to transfer clothes to the other side, so use minus
                optSteps = max(optSteps, max(abs(gainL), abs(gainR)));
            }
        }
     
        return optSteps;
    }
};