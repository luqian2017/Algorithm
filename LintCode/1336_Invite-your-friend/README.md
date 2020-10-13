1336. Invite your friend

There are nn friends coming to the party. Given their invitation relationship, please inquire about the invitation relationship between the two.

Example
Example 1

Input:
[[1,2],[2,3],[3,4],[1,5]]
[4,5]
Output:
["4 is invited by 3","3 is invited by 2","2 is invited by 1","1 invites 5"]
Explanation:
1 invites 2 and 5.
2 invites 3.
3 invites 4.
Example 2

Input:
[[1,2],[2,3],[3,4],[1,5]]
[5,4]
Output:
["5 is invited by 1","1 invites 2","2 invites 3","3 invites 4"]
Explanation:
1 invites 2 and 5.
2 invites 3.
3 invites 4.
Notice
n≤20,len(invitations)=n−1
len(inquiry)=2
It is guarantee that the inquired two have relationship.
