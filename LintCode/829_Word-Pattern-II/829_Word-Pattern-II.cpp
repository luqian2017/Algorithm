
class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        map<char, string> m;
        set<string> s;
        return helper(pattern, str, m, s);
    }


private:
    bool beginWith(string const &str, string const &subStr) {
        if (subStr.size() > str.size()) 
            return false;

        if (subStr == str.substr(0, subStr.size())) 
            return true;

        return false;
    }

    bool helper(string pat, string str, map<char, string> &m, set<string> &s) {
        if (pat.size() == 0)
            return str.size() == 0;

        char c = pat[0];

        if (m.find(c) != m.end()) { //如果c已经存在，则看str是不是以c对应字符串开头
            if (beginWith(str, m[c])) {
                return helper(pat.substr(1), str.substr(m[c].size()), m, s);
            }
            return false;
        }

        //如果pat[0]是一个新的char, 则要试探性的把str[0], str[0..1], ..., str[0..n]跟pat[0]匹配
        //这里要用到set，表示这个str[]已经被用
        for (int i = 0; i < str.size(); ++i) {
            string subWord = str.substr(0, i + 1);
            if (s.find(subWord) == s.end()) { //如果subWord是新的
                s.insert(subWord);
                m[c] = subWord; //也可以m.insert(make_pair(c, subWord));

                //注意：这里不能简单return，因为如果helper()是false, 其他solution仍然可能对
                //return helper(pat.substr(1), str.substr(i + 1), m, s);
                if (helper(pat.substr(1), str.substr(i + 1), m, s))
                    return true;

                s.erase(subWord);     //set和map没有pop_back()操作！！！
                m.erase(c);
            }    
        }

        return false;
      }
};