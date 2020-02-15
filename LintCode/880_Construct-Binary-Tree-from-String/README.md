880. Construct Binary Tree from String

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example
Example 1:

Input: "-4(2(3)(1))(6(5))"
Output: {-4,2,6,3,1,5}
Explanation:
The output is look like this:
      -4
     /  \
    2    6
   / \   / 
  3   1 5   
Example 2:

Input: "1(-1)"
Output: {1,-1}
Explanation:
The output is look like this:
     1
    /
  -1
Notice
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".

解法1：递归。
每次把string分成root, leftStr, rightStr 3 部分。分界线就是当“(“和”)“匹配的那个地方。
注意：
1）startPos是第一个数字结束时后的下一个位置，即”(“的位置。pos会再往后移一个位置，即leftStr开始的第一个数字。然后开始找bracket Count=0的地方，此时pos指向”)"。所以leftStr开始于startPos + 1，终止于pos - 1，所以substr的长度为(pos - 1)-(startPos+1)+1=pos-startPos-1。
而rightStr的开始位置为pos+2，即下一个数字的位置。rightStr的终止位置为n - 2，即倒数第2个")"。所以rightStr的长度为(n-2)-(pos+2)+1=n-pos-3。
2) 以input="-4(2(3)(1))(6(5)(7))"为例，
第一轮：root = -4, leftStr=2(3)(1), rightStr=6(5)(7)
第二轮：root = 2, leftStr = 3, rightStr = 1
root = 6, leftStr = 5, rightStr = 7
3) str2tree的入口参数为string &s，注意这里有个引用，所以不能直接用rootNode->left = s.substr(…)，因为s.substr()返回一个const。解决办法有两个：
方法1：如下面代码所示，定义临时变量leftStr, rightStr
方法2：定义一个helper(stinrg &s, int start, int end)，这样string s永远不变，通过返回开始和终点位置来达到substr的效果。
方法3：用const_cast<>消掉const属性? 但不知道怎么操作。TBD。
