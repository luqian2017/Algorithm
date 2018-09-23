这题应该是Binary Search题里面最经典的一道了。 
注意它跟Rotated Sorted Array里面找minimum要复杂一些。找minimum的题没有target，只需要把A[mid]跟A[start]比较就可以知道是在第二象限还是第四象限，从而把数据分为OOOOXXXX两部分继续二分。

而这道题目需要把A[mid]和target两个值都跟A[start]比较。所以有很多种情况。 
case 1: A[mid]==target 直接返回mid即可。 
case 2: A[mid]>A[start] && target

注意： 
1）应该把A[mid]和target都跟A[start]比。把A[mid]跟A[start]比，然后A[mid]跟target比是不对的。比如说A[mid]>A[start] (第二象限)，A[mid]>target，但我们并不知道target是落在第二象限还是第四象限！ 
2) 我们一开头需要比较A[start]和A[end]是不是已经等于target。否则A[]={1,2,3},start=0, end=2, mid=1, 然后几个if又都不满足，陷入死循环。

---------------------

本文来自 青灯照壁夜读书 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/roufoo/article/details/80407970?utm_source=copy 