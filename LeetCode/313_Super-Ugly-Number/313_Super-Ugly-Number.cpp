class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int num = primes.size();
        vector<int> indexes(num, 1); 
        vector<int> uglys(n + 1);
        uglys[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int candidate = uglys[indexes[0]] * primes[0];
           // int candidate_index = 0;
            for (int j = 1; j < num; ++j) {
                int temp = uglys[indexes[j]] * primes[j];
                if (candidate > temp) {
                    candidate = temp;
                    //candidate_index = j;
                }
            }
           
            for (int j = 0; j < num; ++j) {
                if (candidate == (uglys[indexes[j]] * primes[j])) {
                   indexes[j]++;                    
                }
            }
            uglys[i] = candidate;

        }
        return uglys[n];
    }
};