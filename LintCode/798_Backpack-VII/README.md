Solution 1. Classical DP solution, based on 01 backpack problem.

For the input 
8
[3,2]
[300,160]
[1,6]

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
	Second, dp[i][k] is updated incorrectly.