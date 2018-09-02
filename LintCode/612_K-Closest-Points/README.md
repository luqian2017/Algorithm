解法1： 
我用的数据结构是map< long long, multiset < Point > >，利用了map和set内部元素自动按key排序的特性。 
注意： 
1）这里同样的distance可能有多个点，都放在multiset里面。 
2）另外，同一个点可能出现多次，都要输出而不是只输出一个。 
3）distance不用开根号，因为反正是比较大小。开了根号反而不能用dist做key了，因为dist是double型。

解法2：
用最大堆。 priority_queue。