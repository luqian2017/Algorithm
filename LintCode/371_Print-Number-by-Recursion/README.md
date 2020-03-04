371. Print Numbers by Recursion

Print numbers from 1 to the largest number with N digits by recursion.

Example
Example 1:

Input : N = 1 
Output :[1,2,3,4,5,6,7,8,9]
Example 2:

Input : N = 2 
Output :[[1,2,3,4,5,6,7,8,9,10,11,12,...,99]
Challenge
Do it in recursion, not for-loop.

Notice
It's pretty easy to do recursion like:

recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}
however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?

