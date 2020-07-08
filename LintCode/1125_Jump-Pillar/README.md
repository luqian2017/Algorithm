1125. Jump Pillar

Xiao Yi has n pillars, the height of the i-th pillar is h_i​ , and Xiao Yi stands on the first pillar at the opening. Xiaoyi can jump from i to the j pillar if and only if h_j≤h_i and 1≤j−i≤k, where k is a specified number. In addition, Xiao Yi has an opportunity to release the super power. This super power can jump from column i to any pillar with a full 1≤j−i≤k regardless of the height of the pillar.
Now Xiao Yi wonders if he can reach the n-th pillar.

Example
Example 1:

Input:h=[3,2,7,4],k=2
Output:true
Explanation:You can use super power to jump from the first pillar to the third pillar. Then according to the rules, jump from the third pillar to the fourth pillar
Example 2:

Input:h=[3,4,5,6],k=2
Output:false
Notice
2≤n,k≤1000
1≤h[i]≤10^​9
​​ 

