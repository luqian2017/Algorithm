Uva11093里面，汽车每个加油站先加油x1，然后消耗掉x2，净剩x1-x2。该题里面每个加油站一进一出，只需计算净剩值(注意跟Uva11054不一样)，而不是绝对值之和。

注意: 
1) 该题有环，可以用i=(i+1)%n，也可以将一个环扩展成两个环，从而像链表一样操作。

方法1：一环变两环。(参考了https://menyifan.com/2015/10/18/uva11093/)

注意while()的条件。这里必须用fuel>=0，而不能用sum<=n。否则中途fuel<0时while()仍然会继续，从而使得某个不合格的站点混水摸鱼。 
例如: 
input p[] = {1,3,1,4,2,1,2,3,2} 
input q[] = {2,2,1,3,1,3,1,1,1} 
当start = 0时，debug如下 
start=0 finish=0 fuel=0 
start=0 finish=1 fuel=-1 //这里while()仍会继续 
start=0 finish=2 fuel=0 
start=0 finish=3 fuel=0 
start=0 finish=4 fuel=1 
start=0 finish=5 fuel=2 
start=0 finish=6 fuel=0 
start=0 finish=7 fuel=1 
start=0 finish=8 fuel=3 
find! start=0 finish=9 
Case 1: Possible from station 1

方法2：还是用经典的i = (i+1)%n。这也是紫书的解法。注意当输出的ans大于起始站点时说明已经wrap，也即无解。 
注意以上两种方法复杂度都是O(n)。因为虽然有两个循环嵌套，但每个站点都只算了一次。