1683. Kill Monster
There are n monsters and an Altman. Both Altman and Monster have five attribute values. When Altman's five attributes are greater than or equal to the five attributes of a monster, Altman can kill the monster. When Altman kills a monster, the five properties of the monster are added to Altman. How many monsters can Altman kill at most?

Example
Example 1:

Input: n = 2, v = [[1,1,1,1,1],[1,1,1,1,1],[2,2,2,2,2]]
Output: 2
Explanation: Altman kills monster v[1] at first, and his attribute changes to [2,2,2,2,2]. Then Altman can kill monster v[2]
Example 2:

Input: n = 5, v = [[3,9,2,1,5],[0,9,6,5,9],[6,1,8,6,3],[3,7,0,4,4],[9,9,0,6,5],[5,6,5,6,7]]
Output: 0
Explanation: Altman can not kill any monster.
Notice
v[0][0]-v[0][4] means the 5 values of ALtman. v[1]-v[n] means n monsters' 5 value5。

