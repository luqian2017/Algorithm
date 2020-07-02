1528. number schemes

You are given a strictly increasing array positionposition two integer mm and distancedistance.
Define a sub array A with mm elements that for any 1 \leq i \leq m-11≤i≤m−1 (A[i] - A[i-1]) \leq distance(A[i]−A[i−1])≤distance is guaranteed.
Your task is to find the number of different compositions of A.

Example
input:[1,2,3,4]
3
3
output:4
explation: you can choose (1,2,3), (1,2,4),(1,3,4),(2,3,4) four different compositions of A.

Notice
Two compositions are considered different if they have at least one different element.
Since the answer may be large, print it modulo 99997867.
2 \leq position.length \leq 50002≤position.length≤5000
2 \leq m \leq 1002≤m≤100
1 \leq distance \leq 10^71≤distance≤10
​7
​​ 
1 \leq position[i] \leq 10^71≤position[i]≤10
​7
​​ 

