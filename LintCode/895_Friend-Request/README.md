895. Friend Request

Given an array Ages of length n, where the first i elements represent the age of the individual i. Find total number of friend requests sent by this n person. There are some requirements:

if Age(B) <= (1/2)Age(A) + 7, A will not send a request to B.
if Age(B) > Age(A), A will not send a request to B.
if Age(B) < 100 and Age(A) > 100, A will not send a request to B.
If it does not satisfy 1,2,3, then A will send a request to B
Example
Example1

Input: Ages = [10,39,50]
Output: 1
Explanation:
Only people of age 50 will send friend requests to people of age 39.
Example2

Input: Ages = [101,79,102]
Output: 1
Explanation:
Only people of age 102 will send friend requests to people of age 101.
Notice
Ages.length <= 1000。
Everyone's age is greater than 0, no larger than 150。

解法1：

这个题目的意思就是一大堆人互相选朋友，每个人都只选比自己小或一样年纪的，但是不能选太小的(底线是要> i / 2 + 7)。另外，101岁或以上的老人只跟100岁或以上的人交朋友，当然对方也要比自己小。

我的解法是先把每个年龄的个数存到distribution数组里面。然后我们可以看出1..100岁和101..150岁的情况不一样，应该分开处理。这样，时间复杂度就优化到O(150*150)以内了。

需要注意的几点：
1) 同一个年龄段彼此也要交朋狗友，reqCount += distribution[i] * (distribution[i] - 1);
2) 每个年龄段的每一个人的交朋友数addCount就是比他小的那些人的数目总和。而该年龄段每个人的情况都一样，所以addCount还要乘以distribution[i]。
3) 最容易忽视的一个地方就是非常小的小孩彼此之间不能交朋友，因为对方的年纪不满足>i/2+7。

解法2：解法1用presums数组优化到O(150)。

解法3：下面这个是标准解法。不过时间复杂度是O(n*n)。如果n很大会比较慢。