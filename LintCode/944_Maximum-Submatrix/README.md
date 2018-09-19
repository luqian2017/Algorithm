One O(n^3) solution is to preprocess the matrix, that is, using another matrix to store the sum of row[0] to row[i]

For example,

[1 3 -1]

[2 3 -2]

[-1 -2 -3]

is preprocessed as 

[0 0 0]

[1 3 -1]

[3 6 -3]

[2 4 -6]

Based on the new matrix, we can use the O(n) strategy in Maximum Subarray by going through the rows (for i = 0..n, j=i..n), and each time we get a diff array. Using the algorithm in Maximum Subarray we can get the maximum result of diff array in O(n) time. Thus, the overall time complexity is O(n^3).

Not sure if there exists an O(n^2logn) algorithm. 


