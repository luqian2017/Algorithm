1186. Encode and Decode TinyURL
TinyURL is a URL shortening service where you enter a URL such as https://lintcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Example
Example 1:

Input："https://lintcode.com/problems/design-tinyurl"
Output：http://tinyurl.com/4e9iAk
Explanation：encode and decode by your own algorithm.
Example 2:

Input："https://lintcode.com/problems/solution"
Output：http://tinyurl.com/5d7fiu
Explanation：encode and decode by your own algorithm.


解法1：Base62
1) 全局自增id。
2) 用两个map, longUrl2id和id2longUrl，存放id和longUrl的对应关系。
3) shortKey仅仅是对tinyURL的主体部分而言。注意shortKey2Id()和id2ShortKey()必须能够互相编码和解码，不然就对不上了。id2L
4) encode(longUrl)时，先看longUrl是不是在longUrl2Id里面已经有对应id了，如果有id了，直接调用id2ShortKey(id)就可以了，否则id++，并保存longUrl2Id和id2longUrl的关系，然后调用id2ShortKey(id)把shortKey算出来。
5) decode(shortUrl)时，先把shortUrl的主题部分shortKey找出来，然后用shortKey2Id(shortKey)算出id，然后通过id2longUrl把longUrl找出来。