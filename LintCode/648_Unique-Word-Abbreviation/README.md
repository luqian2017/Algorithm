648. Unique Word Abbreviation
中文English
An abbreviation of a word follows the form<first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example
Example1

Input:
[ "deer", "door", "cake", "card" ]
isUnique("dear")
isUnique("cart")
Output:
false
true
Explanation:
Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
"dear" 's abbreviation is "d2r" , in dictionary.
"cart" 's abbreviation is "c2t" , not in dictionary.
Example2

Input:
[ "deer", "door", "cake", "card" ]
isUnique("cane")
isUnique("make")
Output:
false
true
Explanation:
Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
"cane" 's abbreviation is "c2e" , in dictionary.
"make" 's abbreviation is "m2e" , not in dictionary.
