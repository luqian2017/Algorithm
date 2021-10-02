1883 · Top K Frequently Mentioned Keywords

Algorithms

Medium

Accepted Rate33%

Description

Solution

Notes

Discuss

Leaderboard

Description

Given a list of **reviews**, a list of **keywords** and an integer **k** .
Find out the top k keywords that appear most frequently in different comments, and the K keywords are sorted according to the number of times.
The comparison of strings is case-insensitive. If the mentioned times of keywords are the same in different reviews, list the keywords in alphabetical order.

If K is greater than the length of the list keywords, then output keywords directlythe length of keywords within range: [1, 100]the length of reviews within range: [1, 1000]keywords [i] consists of lowercase lettersreviews [i] consists of uppercase and lowercase letters and punctuation: [ "[", "\", "!", "?", ",", ";" , ".", "]", " "]

Example

```
Example 1:
Input:
k = 2
keywords = ["anacell", "cetracular", "betacellular"]
reviews = [
  "Anacell provides the best services in the city",
  "betacellular has awesome services",
  "Best services provided by anacell, everyone should use anacell",
]
Output:
["anacell", "betacellular"]
Explanation:
"anacell" is occuring in 2 different reviews and "betacellular" is only occuring in 1 review.
Example 2:
Input:
k = 2
keywords = ["anacell", "betacellular", "cetracular", "deltacellular", "eurocell"]
reviews = [
  "I love anacell Best services; Best services provided by anacell",
  "betacellular has great services",
  "deltacellular provides much better services than betacellular",
  "cetracular is worse than anacell",
  "Betacellular is better than deltacellular.",
]
Output:
["betacellular", "anacell"]
Explanation:
"betacellular" is occuring in 3 different reviews. "anacell" and "deltacellular" are occuring in 2 reviews, but "anacell" is lexicographically smaller.
```

Tags

Related Problems

550

Top K Frequent Words II

Hard

471

Top K Frequent Words

Medium