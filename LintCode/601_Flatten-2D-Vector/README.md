601. Flatten 2D Vector
中文English
Implement an iterator to flatten a 2d vector.

Example
Example 1:

Input:[[1,2],[3],[4,5,6]]
Output:[1,2,3,4,5,6]
Example 2:

Input:[[7,9],[5]]
Output:[7,9,5]



注意这题不能用一个2D vector的copy，不然空间不满足要求。
解法1：利用C++的iterator
这题学到了很多iterator的知识。
1) 一维和二维vector都有iterator，一维vector的iterator就好比指向每个元素的指针，二维vector的iterator就好比指向其中每个一维vector的指针。
2) 空的一维和二维vector的begin()和end()相等。
3) \*(iter++)先返回\*iter，然后iter++。
跟\*(i++)一回事。
4) iter像指针，但不能与指针比较。一个未初始化的iter不能与NULL比较。如果非要初始化，可将其初始化为对应container的end()。
即vector<int> a = {1,2,3,4,5};
vector<int>::iterator iter = a.end();
