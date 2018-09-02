解法1： 
我用的数据结构是map< long long, multiset < Point > >，利用了map和set内部元素自动按key排序的特性。 
注意： 
1）这里同样的distance可能有多个点，都放在multiset里面。 
2）另外，同一个点可能出现多次，都要输出而不是只输出一个。 
3）distance不用开根号，因为反正是比较大小。开了根号反而不能用dist做key了，因为dist是double型。

解法2：
用最大堆。 priority_queue。
注意:
1)求n个数中的最小k个数用最大堆。求n个数中的最大k个数用最小堆。
为什么求最小K个数是用最大堆呢？ 最开始k个数构成一个最大堆。第k+1个数push进去后，如果比top大，就会替代top，这时堆的元素总个数为（k+1)，然后紧接着又把top给pop出来，这样堆里面就是最开始k+1个数里面最小的k个数了。
2） C++的priority_queue默认是最大堆(1个参数就可以了）。如果要用最小堆必须声明3个参数如下:
priority_queue<int, vector<int>, greater<int> > pq;
不过这种写法好像不能用于自定义的数据结构。 如果要把自定义的数据结构用于最大堆或最小堆，必须定义compare类。
我们这里是用的最大堆，但是point是自定义数据结构，所以必须定义compare类。
3)时间复杂度为O(nlogk)。
