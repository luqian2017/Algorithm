class Solution {
public:
    /**
     * @param array: An given array.
     * @return: Return the number of "universal" subarrays.
     */
    int subarrays(vector<int> &array) {
         int n = array.size();
         if (n <= 1) return 0;
         int result = 0;
         
         vector<int> freqs;
         int count = 1;
         
         for (int i = 1; i < n; ++i) {
             if (array[i] == array[i - 1]) {
                 count++;
             } else {
                 freqs.push_back(count);
                 count = 1;
             }
         }
         freqs.push_back(count);

         n = freqs.size() - 1;
         for (int i = 0; i < n; ++i) {
             result += min(freqs[i], freqs[i + 1]);
         }
         
         return result; 
    }
};