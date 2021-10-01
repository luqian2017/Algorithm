7 · Serialize and Deserialize Binary Tree

Algorithms

Medium

Accepted Rate33%



![img](https://js.lintcode.com/react/assets/ade1d8c6a840a106f80c427909c31dcc.svg)



Description

Solution

Notes

Discuss

Leaderboard

Description

Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit on how to serialize or deserialize a binary tree，you just need to ensure the binary tree can be serialized to a string，and the string can be deserialized to original binary tree.

There is no limit of how you deserialize or serialize a binary tree, LintCode will take your output of `serialize` as the input of `deserialize`, it won't check the result of serialize.

Example

**Example 1:**

Input:

```
tree = {3,9,20,#,#,15,7}
```

Output:

```
{3,9,20,#,#,15,7}
```

Explanation:

Binary tree {3,9,20,#,#,15,7}, denote the following structure:
3
/　＼
9　20
/　＼
15　　7
it will be serialized {3,9,20,#,#,15,7}

**Example 2:**

Input:

```
tree = {1,2,3}
```

Output:

```
{1,2,3}
```

Explanation:

Binary tree {1,2,3}, denote the following structure:
1
/　＼
2　3
it will be serialized {1,2,3}

Tags

Related Problems

1533

N-ary Tree Level Order Traversal

Easy

1235

Serialize and Deserialize BST

Medium

1195

Find Largest Value in Each Tree Row

Medium