54 · String to Integer (atoi)

Algorithms

Hard

Description

Implement function `atoi` to convert a string to an integer.

If no valid conversion could be performed, a *zero* value is returned.

If the correct value is out of the range of representable values, *INT_MAX* (2147483647) or *INT_MIN* (-2147483648) is returned.

Example

**Example 1:**

Input:

```
string = "10"
```

Output:

```
10
```

Explanation:

Convert a string to an integer.

**Example 2:**

Input:

```
string = "1"
```

Output:

```
1
```

Explanation:

Convert a string to an integer.

**Example 3:**

Input:

```
string = "123123123123123"
```

Output:

```
2147483647
```

Explanation:

123123123123123 > INT_MAX, so we return INT_MAX

**Example 4:**

Input:

```
string = "1.0"
```

Output:

```
1
```

Explanation:

We just need to change the first vaild number.

Tags

Related Problems

241

String to Integer