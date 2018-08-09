
题目链接在 
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=655

这题要求最大值尽量小，最大值越小肯定越难，所以如果最大值可以是x1的话, 那么x2>x1肯定也可以，所以这里可以用binary search。

另外还要加greedy search，从最右边开始（因为题目规定S(1) 尽量小, 若S(1)一样则S(2)尽量小…），尽量把多的数放到一起(只要sum不大于目标值即可）
设所有n个元素的SUM和为M, 二分次数为logM，每次整个数组都扫一遍。所以复杂度为O(nlogM)。

这题要注意跟sum有关的变量都用long long，不然可能溢出。我在Uva上提交的结果是Presentation Error。应该是结果对，但输出不符合要求。不知道具体什么原因，以后再查，欢迎有知道原因的同学留言。也欢迎大家对我的代码提出改进意见。