class Solution {
public:
  int subarrays(vector<int> &array) {
     int n = array.size();
     if (n <= 1) return 0;
     
     for (int i = 0; i < n; ++i) {
         if (array[i] == 2) array[i] = -1;
         else array[i] = 1;
     }
     
     vector<long long> presums(n + 1);
     
     for (int i = 1; i <= n; ++i) {
         presums[i] = presums[i - 1] + array[i - 1];
     }

     int result = 0;
     for (int i = 1; i < n; ++i) {
         for (int j = i + 1; j <= n; ++j) {
             if (((j - i) & 0x1) && presums[j] - presums[i - 1] == 0) {
                int mid = (i + j) / 2;
                long long firstHalfSum = presums[mid] - presums[i - 1];

                  if (abs(firstHalfSum * 2) == j - i + 1) {
                    result++;
                }
             }
         }
     }
  }
};