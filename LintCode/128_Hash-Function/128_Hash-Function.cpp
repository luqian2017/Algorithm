class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        const int HASH_CONST = 33;
        
        int N = key.size();
        if (N == 0) return 0;
        
        int result = 0;
        
        for (int i = 0; i < N; ++i) {
            result = ((long long)result * HASH_CONST + key[i]) % HASH_SIZE;
        }
        
        return result;
    }
};