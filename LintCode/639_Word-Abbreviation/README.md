639. Word Abbreviation
中文English
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
Example
Example 1:

Input:
["like","god","internal","me","internet","interval","intension","face","intrusion"]
Output:
["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Example 2:

Input:
["where","there","is","beautiful","way"]
Output:
["w3e","t3e","is","b7l","way"]
Notice
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.

注意：
1）当遇到有duplidate时，就再往下进行一个字符，直到没有冲突为止。
2）abbreviate() 应该是round + 2 >= word.size()就不用往下进行了。因为word会不断跟着round改变。如果仅仅用if (n <= 3)是不对的，因为interval和internal最后都是interv1l就不对了。
3)abbrMap里面的旧result[i]不用删掉，其实vector()也不好删，也没有必要删。