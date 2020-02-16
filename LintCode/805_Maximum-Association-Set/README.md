805. Maximum Association Set
中文English
Amazon sells books, every book has books which are strongly associated with it. Given ListA and ListB,indicates that ListA [i] is associated with ListB [i] which represents the book and associated books. Output the largest set associated with each other(output in any sort). You can assume that there is only one of the largest set.

Example
Example 1:
	Input:  ListA = ["abc","abc","abc"], ListB = ["bcd","acd","def"]
	Output:  ["abc","acd","bcd","def"]
	Explanation:
	abc is associated with bcd, acd, dfe, so the largest set is the set of all books
	
Example 2:
	Input:  ListA = ["a","b","d","e","f"], ListB = ["b","c","e","g","g"]
	Output:  ["d","e","f","g"]
	Explanation:
	The current set are [a, b, c] and [d, e, g, f], then the largest set is [d, e, g, f]
Notice
The number of books does not exceed 5000.

解法1：并查集
首先把A和B中的每本书按globalId编号。
然后union find，最后查每本书的find(x)，找出某个祖宗其拥有最多本书。
注意：
1）并查集使用的关键之处就是搞清楚什么时候用father[x]，什么时候用find(x)。
find(x)的返回值就是x当前情况下的最高祖宗，在find(x)的过程中，最后father[x]也指向了其当前情况下的最高祖宗。
在merge()过程结束后，可能仍有某些书的father没有指向真正的最高祖宗。所以在接下来的循环中，
for (int i = 0; i < globalIdMax; ++i) {
            int fx = find(i); //not father[i]!
在find(x)中，father[x]已经指向其最高祖宗了。
所以在接下来的匹配maxId中，用father[i]而不是find(i)就可以了。         

        for (int i = 0; i < globalIdMax; ++i) {
            if (father[i] == maxId) {
                res.push_back(id2Book[i]);
            }
        }
