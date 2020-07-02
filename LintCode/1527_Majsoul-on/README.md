1527. Majsoul on !

According to a mahjong game called bird soul, simplified the rules of the game, as follows:

There are 36 cards in total, and each card is 1-9.And each number has four cards.

If 14 cards are taken out and the following conditions are satisfied, that is to win in mahjong:

Two of the 14 cards have the same number of cards, known as the Sparrow head.
Remove the above 2 cards, the remaining 12 cards can form 4 shunzi or kezi.
Note: shunzi means an increasing number of three consecutive characters (e.g. 234,567), and an kezi means three characters of the same number (e.g. 111,777).

You draw 13 cards out of 36 cards, and then you take another card out of the remaining 23 cards, and what kind of number cards can you draw with?

Example
Example 1:

Input: 
[1, 1, 1, 2, 2, 2, 5, 5, 5, 6, 6, 6, 9]
Output: 
[9]
Explanation：
It can be made up of four kezi of 1,2,5,6 and a head of a sparrow of 9.
Example 2:

Input: 
[1, 1, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9]
Output: 
[4, 7]
Explanation：
It can be made up of (123), (123), (567) and (456) or (789), and a head of a sparrow of 1.
Notice
If there are multiple cards that satisfied the conditions, please return them in the order from smallest to largest. If no card satisfied return 0.

解法1：枚举+DFS

这题我觉得并不容易。主要是对没玩过麻将的同学比较难，那些术语可能不熟悉。

思路：枚举1到9，每个数字加到cards里面后排序，看是否能胡。
而判断是否能胡这个过程是用DFS。DFS里面有个参数是has_sparrow，表示是否已有雀头。如果has_sparrow=TRUE，则DFS就只用判断
顺子和刻子，否则先判断是否有雀子，再判断是否有顺子和刻子。

注意：
1) 如果有雀头或刻子，都是直接从nums开头裁掉相应数字，然后继续递归(按有没有雀头)。但如果是顺子，则只能裁开头第1个数字，并将其后面(不一定直接相连)的顺子数字从vector中去掉。比如[1,1,1,2,2,2,3,3,3,5,7,7,9]，顺子为1,2,3，而2和3并不予1相连。
2) 也可以不采用has_sparrow这个参数。网上有答案直接用nums.size()%3。因为没有雀头时，比如说14，11, 8等(每个由14减去若干个3，因为刻子和顺子都是3个) 都不能被3整除，去掉雀头后变成12，9，6等都可以被3整除。但是不是很直观。

————————————————
版权声明：本文为CSDN博主「纸上得来终觉浅 绝知此事要躬行」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/roufoo/article/details/107082812