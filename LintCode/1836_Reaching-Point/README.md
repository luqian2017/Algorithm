1836. Reaching Point

There is a bot located at a pair of integer coordinates, (x, y). It must be moved to a location with another set of coordinates. Though the bot can move any number of times, it can only make the following two types of moves:

From location (x, y) to location (x + y, y)
From location (x, y) to location (x, x + y)
Given starting and target ending coordinates, if the bot can reach the ending coordinates given the the rule of movement. you should return True, otherwise return False.
Example
Example 1:
Input:
start = [1, 1]
target = [5, 2]
Output: True
Explanation: (1, 1) -> (1, 2) -> (3, 2) -> (5, 2), so you should return True
Example 2:
Input:
start = [1, 2]
target = [3, 4]
Output: False
Explanation: [1, 2] can not reach [3, 4] by move rule. so you should return false.
Example 3
Input:
start = [2, 1]
target = [4, 1]
Output: True
Explanation: (2, 1) -> (3, 1) -> (4, 1), you should return True
Notice
x and y are within range: [1, 100000]
the number of move contain zero.
