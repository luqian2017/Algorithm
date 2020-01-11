662. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you if this number is greater or less than the number you guessed.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
-1 means this number is less than the number you guessed

1 means this number is greater than the number you guessed

0 means this number is equal to the number you guessed

Example
Example 1:

Input : n = 10, I pick 4 (but you don't know)
Output : 4