281. Paint the Ceiling

You want to build yourself a house. The building company you hired can only build houses with sides from their specific set ss. That means they can build you a square house or a rectangular one but if and only if its length and width belong to the sets.

This month, they have a special promotion: they will paint the ceiling of a new house for free... but only if its area is not more than aa. You want them to do it for free but you also want to be sure that the house will be comfortable and not too small. How many possible house configurations can you create to have the ceiling painted for free given the side lengths offered?

There is a method to how the company decides what lengths of sides to produce. To determine nn lengths of wall segments to offer, they start with a seed value s​0, some variables k, b and m, and use the following equation to determine all other side lengths s_i:

s_i=((k × s_{i-1}+b) mod m+1+s_{i-1}) for 1≤i<n

Example
Example 1

Input:
s_0 = 2
n = 3
k = 3
b = 3
m = 2
a = 15
Output: 5
Explanation:
For example, you are given s_0=2 and they will produce n=3 total wall lengths. If k=3, b=3 and m=2 we have:

s	    i	 calculation	                result
[2]	    1	 ((3×2+3)%2)+1+2	             4
[2,4]	2	 ((3×4+3)%2)+1+4	             6
[2,4,6]			
Now that we have our set of lengths, we can brute force the solution using the following tests assuming a=15:

s=[2,4,6]
​​s1  s2 s1×s2 s1×s2≤a
2	2	4	True
2	4	8	True
2	6	12	True
4	2	8	True
4	4	16	False
4	6	24	False
6	2	12	True
6	4	24	False
6	6	36	False
There are 55 combinations that will result in a free paint job. Brute force will not meet the time constraints on large sets.

Notice
1 \leq n \leq 6 × 10^6​​ 
1 \leq s_i \leq 10^9​​ 
1 \leq k,b,m \leq 10^9​​ 
1 \leq a \leq 10^{18}
​​ 
