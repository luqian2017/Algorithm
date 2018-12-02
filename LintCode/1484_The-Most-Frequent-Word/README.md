1484. The Most Frequent word
Give a string s witch represents the content of the novel, and then give a list indicating that the words do not participate in statistics, find the most frequent word(return the one with the smallest lexicographic order if there are more than one word)

Example
Input: s = "Jimmy has an apple, it is on the table, he like it"
excludeWords = ["a","an","the"]
Output:"it"

Solution：See the .cpp file.
Note:
1) string.find(substring, pos) will return -1 (string::npos) if substring is not found.
2) Needs to skip the ' ', ',' and '.'.