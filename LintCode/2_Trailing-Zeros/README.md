2. Trailing Zeros
Write an algorithm which computes the number of trailing zeros in n factorial.

Example
11! = 39916800, so the out should be 2

Challenge
O(log N) time

这题挺有意思。因为阶乘里面的0都是由2*5得来的，所以看有多少个(2,5)构成的pair就可以了。而我们知道2的数目远远多于5的数目，所以只看5的数目就可以了。

比如说105的 阶乘，里面有多少个5呢? 首先5,10,15,20,…105这里面每个都至少有1个5，而且有些有2个，3个， 甚至更多。我们用个循环把它们都加起来就可以了。
