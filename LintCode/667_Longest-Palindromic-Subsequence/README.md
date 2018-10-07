Typical DP solution.

We need to return dp[0][len - 1], so i needs to move from len - 1 to 0, and j needs to move from i + 1 to len -1. 

For input "bbbab", the dp[][] is:

1 2 3 3 4 
0 1 2 2 3 
0 0 1 1 3 
0 0 0 1 1 
0 0 0 0 1 

The correct two for loop should be:
        for (int i = len - 1; i >= 0; --i) {
            cout<<"i="<<i<<endl;
            for (int j = i + 1; j < len; ++j) {

Note the following two cases are incorrect:
1)
   for (int i = 0; i < len - 1; ++i) {
     for (int j = i + 1; j < len; ++j) {

It is wrong as dp[0][len - 1] should be the final result.

2)
   for (int i = 0; i < len - 1; ++i) {
      for (int j = 0; j < len; ++j) {
It is wrong as dp[i+1][j] will exceed the boundary.


