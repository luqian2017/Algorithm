266. Expect Distance

Little K is trapped in a cave (cave A).
From cave A, there is two paths, in one path, it takes xx kilometers to go back cave A; the other one takes 22 kilometers to go to cave B.
From cave B, there is two paths, in one path, it takes yy kilometers to go to cave A; the other one takes zz kilometers to go to the exit C.
Little K always forget paths he walked, everytime he is in a cave, he will choose the path in equally probability.
Please calculate the expect distance to go out of the cave.

Example
Input:
x = 1
y = 2
z = 1
Output:
9
Notice
x, y, zx,y,z are all integeral, 1 <= x, y, z <= 10^8.

解法1：
这是一道数学题。一开始没思路，请教了高手才明白。
设从A点走到出口的数学期望为EA, 从B点走到出口的数学期望为EB。可得
EA = (EA + x) / 2 + (EB + 2) / 2
EB = (EA + y) / 2 + Z / 2
通过上面2个方程可得
EA = 2 * x + y + z + 4
EB = x + y + z + 2
注意两个转移方程都是以A或B点的转出状态为准，不考虑转入状态，不然就搞糊涂了。

解法2：
已经有人贴了二元方程解期望的方法。这里另外给一个比较繁琐但比较严谨的数学分析方法。

将这张地图表示成这样：（其中为了不失一般性，我们令A->B的距离为w，本题中w=2）

     x      y
    --> <----
    |  |    |
    <- A ---> B  ---> C
          w      z
每次从A出发，可以分类为三种结果：
a.1/2的概率A->A （循环）
b.1/4的概率A->B->A （循环）
c.1/4的概率离开山洞
也就是说，有总共3/4的概率是回到起始点，开始一个新的循环；另外1/4的概率就是结束循环。

那么从起点A开始，再回到起点A，一次循环的距离期望Ex是什么呢？很显然，Ex = (1/2*(x) + 1/4*(w+y)) / (1/2+1/4)，也就是说要如果从A走回循环点A的话，所需走路的平均距离就是Ex。

我们再考察走出山洞结束循环的本质是什么。归纳起来，本质就是走了若干次循环（就是从A走回A，甭管是从哪条路回来的）后，再走A->B->C。仅此一种模式。
所以我们分情况考虑走了0次循环、1次循环、2次循环。。。这几种情况。
从A出发，经过0次循环，离开山洞的距离期望是：(1 * 1/4) * ABC (where ABC = w+z)
从A出发，经过1次循环，离开山洞的距离期望是：(3/4 * 1/4) * (Ex + ABC)
从A出发，经过2次循环，离开山洞的距离期望是：((3/4)^2 * 1/4) * (2 * Ex + ABC)
从A出发，经过3次循环，离开山洞的距离期望是：((3/4)^3 * 1/4) * (3 * Ex + ABC)
...
从A出发，经过k次循环，离开山洞的距离期望是：((3/4)^k * 1/4) * (k * Ex + ABC)

说明：(3/4)^k表示在A点走了k次循环的概率，1/4表示从A点直接走出山洞的概率。所以走出山洞的距离总期望就是上面全部加起来，其中k取到无限大。

ans = ((3/4)^0 * 1/4) * (0*Ex + ABC) + ((3/4)^1 * 1/4) * (1*Ex + ABC) + ((3/4)^2 * 1/4) * (2*Ex + ABC) + ... + ((3/4)^k * 1/4) * (k*Ex + ABC)
    = 1/4 * sum( (3/4)^k * (k*Ex + ABC) ) , k=0,1,2,...
    = 1/4 * { [sum((3/4)^k * k*Ex)] + [sum((3/4)^k) * ABC ] }
    = 1/4 * {S + 4 * ABC}
    = 1/4 *S + ABC
其中无穷等比数列sum((3/4)^k)的和是4（套一下等比求和公式即可）。另外令 q = 3/4 ，则S=sum((3/4)^k * k*Ex)就是一个“等差等比数列”，怎么解可以参见高一数学课本。

 S = q^0 * 0Ex + q^1 * 1Ex + q^2 * 2Ex + ... + q^k * kEx            
两边乘以q

qS = q^1 * 0Ex + q^2 * 1Ex + ... + q^k * (k-1)Ex + q^(k+1) * kEx
相减

(1-q)S = Ex * (q^1 + q^2 + q^3 +...+q^k) - q^(k+1) * k*Ex

     S = Ex * 1/(1-q) * q/(1-q)
       = Ex * 4 * 3
       = Ex * 12
       = 8 x + 4 w+ 4 y
最终：

ans = 1/4 * S + ABC
    = (2 x + w + y) + (w + z) = 2 x + 2 w + y +z