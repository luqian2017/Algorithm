532. Reverse Pairs
中文English
Reverse pair is a pair of numbers (A[i], A[j]) such that A[i] > A[j] and i < j. Given an array, return the number of reverse pairs in the array.

Example
Example1

Input:  A = [2, 4, 1, 3, 5]
Output: 3
Explanation:
(2, 1), (4, 1), (4, 3) are reverse pairs
Example2

Input:  A = [1, 2, 3, 4]
Output: 0
Explanation:
No reverse pair

解法1：
树状数组。
注意:

1. 该解法的C[x]里面的x表示的是x的实际值，而不是下标。
2. 离散化代码非常有用，可以将[3,2,100000]简化为[2,1,3]，并且不影响结果。注意最后要+1。
    for (int i = 0; i < A.size(); ++i) {
            A[i] = lower_bound(sortedA.begin(), sortedA.begin() + uniqLen, A[i]) - sortedA.begin() + 1;
    }
3. 注意去重，所以要用到unique()函数，非常有用。
4. A[i]都要从1开始，C[]的size比A[]多1。
5) 计算result的for循环里面的两行顺序可以互换。
        for (int i = 0; i < A.size(); ++i) {
            add(A[i], 1);
            result += sum(uniqLen) - sum(A[i]);
        }
6） 上面必须只能用1个循环，这样每次result刚好加上A[i]对应的逆序数。不可以用2个循环，即将add(A[i],1)全部遍历完后再用另外一个for循环累加result。

解法2：
类似解法1，但是用brutal force构建类似C[]。时间复杂度O(n^2)。
会超时。

解法3：
Merge Sort. 
