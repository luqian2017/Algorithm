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
为什么求最小K个数是用最大堆呢？ 最开始k个数构成一个最大堆。第k+1个数push进去后，如果比top大，就会替代top，这时堆的元素总个数为（k+1)，然后紧接着又把top给pop出来，这样堆里面就是最开始k+1个数里面最小的k个数了。我们按同样的步骤走完n个元素后，堆里面剩下的就是n个元素里面最小的k个数。
2） C++的priority_queue默认是最大堆(1个参数就可以了）。如果要用最小堆必须声明3个参数如下:
priority_queue<int, vector<int>, greater<int> > pq;
不过这种写法好像不能用于自定义的数据结构。 如果要把自定义的数据结构用于最大堆或最小堆，有两个方法：
方法1：重载operator <。
比如说最大堆，
bool operator < (const Point &a, const Point &b) {
      long long dist_a = distance(a, g_origin);
      long long dist_b = distance(b, g_origin);
      if (dist_a == dist_b) {
          if (a.x == b.x) return a.y < b.y;
          return a.x < b.x;
      } 
      return dist_a < dist_b;
}
定义priority_queue如下即可：
        priority_queue<Point> pq;
		
如果是最小堆，应该也是重载operator <，但具体实现的时候把<变>即可。定义priority_queue跟上面一下。(下次确认一下)。


方法2： 定义compare类。
class compare {
public:
  bool operator() (const Point &a, const Point &b) const {
      long long dist_a = distance(a, g_origin);
      long long dist_b = distance(b, g_origin);
      if (dist_a == dist_b) {
          if (a.x == b.x) return a.y < b.y;
          return a.x < b.x;
      } 
      return dist_a < dist_b;
  }
};

注意，定义了compare类后，不管是最大堆还是最小堆，定义priority_queue都是如下：
priority_queue<Node, vector<Node>, cmp> q;

3)时间复杂度为O(nlogk)。
