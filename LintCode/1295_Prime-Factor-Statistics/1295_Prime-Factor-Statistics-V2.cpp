class Solution {
public:
    /**
     * @param N: a number
     * @return: the number of prime numbers.
     */
    int Count_PrimeNum(int N) {
        int result = 0;
        vector<int> nums(N + 1, -1);
    
        for (int i = 2; i <= N; ++i) {
            result += Pollard_Rho(i);
        } 
        return result;
    }
    
private:
    int Pollard_Rho(int n) {
        int count = 0;
        //vector<int> result;
        int sqrtn = sqrt(n);
        for (int i = 2; i <= sqrtn;) {
            while (n % i == 0) {
                count++;
             //   result.push_back(i);
                n /= i;
            }
            
            if (i == 2) i += 1;
            else i += 2;
        }
      //  if (count == 0) count = 1;  // if n is non-2 prime
        if (n > 1) count++;
        return count;
    }
};