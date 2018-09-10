There are three solutions for this problem:
1) DFS + memorization 
2) DP 
3) Greedy 

Is possible to use BFS to solve this problem?

The link below is good

[https://blog.csdn.net/wrm_nancy/article/details/51296416](https://blog.csdn.net/wrm_nancy/article/details/51296416)

Solution 1: DFS + memorization
Note:

1) when s or p is empty, we cannot return false as it is possible that 
  s="" 
and
  p="*"
in this case it should return true。 

2) memorization includes visited and memo。So why do we need memo field? It is because * can also be use to represent empty chars。

For example, s="aab", p="a?*b":
vm[0][0].memo = true 

vm[1][1].memo = true

vm[2][2].memo = ? needs vm[2][3]
 
vm[2][3].memo = true // all are ’b’

**We can see that vm[2][2] uses the result of vm[2][3] in advance, thus, when we calculate vm[2][3] later, we don't need to calculate it again**.
