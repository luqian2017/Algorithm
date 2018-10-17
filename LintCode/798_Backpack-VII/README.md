Multi-choice backpack problem (i.e., each item can be carried multiple times until its count).
Solution 1. Classical DP solution, based on 01 backpack problem.
Time complexity O(NW): N is the total amount of all items (note each item may have several count). W is the money.
Space complexity O(nW): n is the number of items (i.e., how many kinds of item). W is money.

For the input 
8  //n = money
[3,2] //prices
[300,160] //weight
[1,6] //amounts

The dp[][] is:
0 0 0 0 0 0 0 0 0 
0 0 0 300 300 300 300 300 300 
0 0 160 300 320 460 480 620 640 

Note:
1)
   dp[0..itemCount][0..n]
   weight[0..itemCount-1]
   prices[0..itemCount-1]
   amounts[0..itemCount-1]
   
   dp[i - 1][k - j * prices[i - 1]] + j * weight[i - 1];
   here the first "i - 1" means the first i - 1 items, the second and the third "i-1" actually means the ith item (as the array index starts from 0).
   
2) Fot the three-layer loop, it is wrong to right it as follows:
      
        for (int i = 1; i <= itemCount; ++i) { // i->item[i]
            for (int j = 0; j <= amounts[i - 1]; ++j) { //j-> amount[0]..amount[i-1]
                for (int k = 1; k <= n; k++) { //k->  1 .. n
                    dp[i][k] = dp[i - 1][k];
                    
                    if (k >= j * prices[i - 1]) {
                        dp[i][k] = max(dp[i][k], dp[i - 1][k - j * prices[i - 1]] + j * weight[i - 1]);
                    }
                }
            }
        }
		
	First, it wastes time as dp[i][k] = dp[i - 1][k]; as executed by the j loop which is unecessary.	
	Second, dp[i][k] is updated by loop j incorrectly, it should be independeng of j loop.

Solution 2:
Based on Solution 1, and add the one-dimension array optimization.
Time complexity O(NW).
Space complexiy O(W).

Note: 
1) The following code is wrong in Soolution 2!
        for (int i = 1; i <= itemCount; ++i) { // i->item[i]
            for (int j = 1; j <= amounts[i - 1]; ++j) { //j-> amount[0]..amount[i-1]
                for (int k = n; k >= j * prices[i - 1]; --k) { //k->  1 .. n
                    dp[k] = max(dp[k], dp[k - j*prices[i - 1]] + j*weight[i - 1]);
                }
            }
        }

The reason is because in Solution 2, k is updating from big to small. We need to find an optimal candidate for dp[k]. Obviously, it is dp[k-prices[i-1]]+weight[i-1] as it is larger than p[k - j*prices[i - 1]] + j*weight[i - 1] (for j>1).

2) In Solution 2, the j loop should start from 1, because the j loop is just used for counting the loop count. If starting from 0, then it count 1 more time.
In Solution 1, the j loop can start from 0 or 1. If it starts from 0, it just wastes time to do 
dp[i][k] = max(dp[i][k], dp[i - 1][k]);
one more time.          