vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > solution;
        vector<int> singleSol;
        int numSize=nums.size();
        int totalNum=pow(2,numSize)-1;
        solution.push_back(singleSol);
        
        for (int i=1; i<=totalNum; ++i) {
            singleSol.clear();
            for(int j=0; j<numSize; ++j) {
                int bitNum = (i>>j)&0x1;
                if (bitNum==1) {
                    singleSol.push_back(nums[j]);
                }
                sort(singleSol.begin(), singleSol.end());
            }

            solution.push_back(singleSol);
        }
        return solution;
    }