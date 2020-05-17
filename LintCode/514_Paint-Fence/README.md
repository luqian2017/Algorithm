514. Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Example
Example 1:

Input: n=3, k=2  
Output: 6
Explanation:
          post 1,   post 2, post 3
    way1    0         0       1 
    way2    0         1       0
    way3    0         1       1
    way4    1         0       0
    way5    1         0       1
    way6    1         1       0
Example 2:

Input: n=2, k=2  
Output: 4
Explanation:
          post 1,   post 2
    way1    0         0       
    way2    0         1            
    way3    1         0          
    way4    1         1       
Notice
n and k are non-negative integers.

解法1：
这题设计得不错，我是参考网上的思路。
i = 0时，result = 0; i = 1时，result = k。
我们从左往右看，每个post的可刷方案包括2类(result = diff+same)，diff就是跟前面post不同的颜色方案，same就是跟前面post相同颜色的方案。
从i=2开始，post i的diff很好算，就是post i-1的result * (k - 1)，即post i-1可以刷4种颜色，那么对于4种颜色里的每一种，post i可以有3种选择。
那么post i 的same怎么算呢? 因为post i跟post i-1颜色一样的话，那么post i-1和post i-2必须颜色不一样。也就是post i的same就是post i-1的diff。
