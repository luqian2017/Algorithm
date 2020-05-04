1408. Gas Station II

A car is driving on a straight road and it has original units of gasoline.
There are n gas stations on this straight road, and the distance between the i-th gas station and the starting position of the car is distance[i] unit distance, which can add apply[i] unit gasoline to the car.
The vehicle consumes 1 unit of gasoline for every 1 unit traveled, assuming that the car's fuel tank can hold an unlimited amount of gasoline.
The distance from the starting point of the car to the destination is target. Will the car arrive at the destination? If it can return the minimum number of refuelings, it will return -1.

Example
Example 1:

Given target = `25`, original = `10`, distance = `[10,14,20,21]`, apply = `[10,5,2,4]`, return `2`.
Input:
25
10
[10,14,20,21]
[10,5,2,4]
Output:
2

Explanation:
Refuel at the 1st and 2nd gas stations.
Example 2:

Given target = `25`, original = `10`, distance = `[10,14,20,21]`, apply = `[1,1,1,1]`, return `-1`.
Input:
25
10
[10,14,20,21]
[1,1,1,1]
Output:
-1

Explanation:
The car can't reach the destination.
Notice
1 <= n <= 10000
1 <= target, distance[i] <= 1000000
1 <= original, apply[i] <= 100

解法1：maxHeap + Greedy

这题感觉也挺难的，比LintCode 186 Gas Station要难一些，那题只用给出可不可行，而这里是要给出最优解。思路也是参考的网上。感觉跟加油站有关的问题都可以用贪婪法。

1) 用maxHeap存储当前已经经过的加油站的储油量。注意这里是已经经过的加油站，还没经过的加油站不要放进去。
2) 当车要去下一站station[i]油不够怎么办呢？就把之前经过的加油站的储油都列出来，找最多的那个，这就是为什么用maxHeap的原因。把maxHeap.top() pop出来之后将其值加到currGas里面去。
3) 不是所有的distance[i]都需要用上，我们只需要用到< target的那些distance值就可以了。我们把这些值放到stations里面。最后把target的值放进去。