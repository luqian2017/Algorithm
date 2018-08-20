Stacks of Flapjacks的题目详见Uva 120。
解法类似与插入排序，每次找未排好序列中数字最大的煎饼并将其翻至锅顶，然后将全部未排序的序列翻转。这样就排好了一个数字。

因为STL vector 里面已经有 max_element() 和 reverse()，所以直接用STL会比较方便。
注意reverse里面的第二个元素是基于vector.end()，它是最后一个元素的后一个元素，所以如果第二个元素不是end()而是某个具体元素的指针的话，要加1。否则出错。

程序输出如下：
original flapjacks
2 5 7 6 4 8 11 4

n=0
 11 8 4 6 7 5 2 4  4 2 5 7 6 4 8 11
n=1
 8 4 6 7 5 2 4 11  4 2 5 7 6 4 8 11
n=2
 7 5 2 4 6 4 8 11  4 6 4 2 5 7 8 11
n=3
 6 4 4 2 5 7 8 11  5 2 4 4 6 7 8 11
n=4
 5 2 4 4 6 7 8 11  4 4 2 5 6 7 8 11
n=5
 4 4 2 5 6 7 8 11  2 4 4 5 6 7 8 11
n=6
 4 2 4 5 6 7 8 11  2 4 4 5 6 7 8 11
n=7
 2 4 4 5 6 7 8 11  2 4 4 5 6 7 8 11
after sorting
2 4 4 5 6 7 8 11
Process returned 0 (0x0)   execution time : 0.087 s
Press any key to continue.

看来用STL虽然方便，可是太慢了（可能是涉及到iterator的关系?)，直接用写函数max()和reverse()可能快些。