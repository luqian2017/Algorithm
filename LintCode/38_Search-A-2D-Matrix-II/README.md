Start from the right-top point.
If the point is larger than the target, colIndex--;
If the point is smaller than the target, rowIndex++;
else colIndex--; rowIndex++; count++;


It can also start fromt the left-bottom point, and the algorithm is similar.

Time complexity O(m+n).
Space complexity O(1).