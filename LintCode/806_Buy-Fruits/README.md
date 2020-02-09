806. Buy Fruits

Xiao Ming is going to help companies buy fruit. Give a codeList, which is loaded with the fruit he bought. Give a shoppingCart, which is loaded with target fruit. We need to check if the order in the codeList matches the order in the shoppingCart. Note that only the sum of the items in all linked lists in the codeList add up to less than or equal to the sum of items in the shoppingcart may return 1. In addition, the item in codeList may be "anything", which can match with any fruit.

Example
Example 1:

Input:  codeList = [["apple", "apple"],["orange", "banana", "orange"]], shoppingCart = ["orange", "apple", "apple", "orange", "banana", "orange"]
Output:  1	
Explanation: Because the order in the codeList matches the fruit in the shoppingCart except for the first orange.
Example 2:

Input:  codeList = [["orange", "banana", "orange"],["apple", "apple"]], shoppingCart = ["orange", "apple", "apple", "orange", "banana", "orange"]
Output:  0	
Explanation: Because the order in the codeList doesn't match the shoppingCart.
Example 3:

Input:  codeList = [["apple", "apple"],["orange", "anything", "orange"]], shoppingCart = ["orange", "apple", "apple", "orange", "mango", "orange"]
Output:  1	
Explanation: anything matches mango, so codeList can match the fruit of shoppingCart.
Notice
The number of fruits in codeList and the number of fruits in shppingCart are both less than 2000.
