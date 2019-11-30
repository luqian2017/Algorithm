367. Expression Tree Build
中文English
The structure of Expression Tree is a binary tree to evaluate certain expressions.
All leaves of the Expression Tree have an number string value. All non-leaves of the Expression Tree have an operator string value.

Now, given an expression array, build the expression tree of this expression, return the root of this expression tree.

Example
Example 1:

Input: ["2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"]
Output: {[-],[*],[/],[2],[6],[+],[+],#,#,#,#,[23],[7],[1],[2]}
Explanation:
The expression tree will be like

	                 [ - ]
	             /          \
	        [ * ]              [ / ]
	      /     \           /         \
	    [ 2 ]  [ 6 ]      [ + ]        [ + ]
	                     /    \       /      \
	                   [ 23 ][ 7 ] [ 1 ]   [ 2 ] .

After building the tree, you just need to return root node `[-]`. 
Example 2:

Input: ["10","+","(","3","-","5",")","+","7","*","7","-","2"]
Output: {[-],[+],[2],[+],[*],#,#,[10],[-],[7],[7],#,#,[3],[5]} 
Explanation:
The expression tree will be like
 	                       [ - ]
	                   /          \
	               [ + ]          [ 2 ]
	           /          \      
	       [ + ]          [ * ]
              /     \         /     \
	  [ 10 ]  [ - ]    [ 7 ]   [ 7 ]
	          /    \ 
                [3]    [5]
After building the tree, you just need to return root node `[-]`.
Clarification
See wiki:
Expression Tree

