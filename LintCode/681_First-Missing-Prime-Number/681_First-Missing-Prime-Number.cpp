       
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @return: the first missing prime number
     */
    int firstMissingPrime(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 2;
        int max_elem = 2 * nums.back();
        primes.resize(20000, 0);

        int count = 0;
        for (int i = 2; i < max_elem; ++i) {
            if (!primes[i]) {
                if ((count >= len) || (i != nums[count])) return i;
                primes[count++] = i;
            }
            for (int j = 0; j < count; ++j) {
                int prod = primes[j] * i;
                if (prod > max_elem) break;
                primes[prod] = -1;
                if (i % primes[j] == 0) break;
            }
        }
    }
private:
    vector<int> primes;
};