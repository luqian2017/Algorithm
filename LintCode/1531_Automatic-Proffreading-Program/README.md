1531. Automatic Proofreading Program

There are some words spelt wrong. Please write a program to proofread the spell, and return the right spell.
The rules is listed below:

If three same charactors connected together, it's a wrong spell, delete one of the charators, e.g, ooops -> oopsooops−>oops.
If two pairs of same charactors (AABB) connected together, it's a wrong spell, delete one charactor of the second pair, e.g. helloo -> hellohelloo−>hello.
The rules follow the priority from left to right, e.g. the aabbaabb and bbccbbcc are both wrong spell in aabbccaabbcc, you should fix aabbaabb firstly, so the final result is aabccaabcc.
Example
Sample Input 1:
str = "helloo"

Sample Output 1:
“hello”

"lloo" is a wrong spell, delete 'o'.

Sample Input 2:
str = ”woooow“

Sample Output 2:
“woow”

"oooo" is a wrong spell, delete an 'o' firstly, "ooo" is still wrong, delete an 'o'.
Notice
The length of input string is nn, 1 <= n <= 10^51<=n<=10
​5
​​ .
字符串均由小写字符组成。

