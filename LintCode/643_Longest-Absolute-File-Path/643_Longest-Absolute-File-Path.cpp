class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, n = input.size(), level = 0;
        unordered_map<int, int> m {{0, 0}};
        int pos = 0;
        string temp;
        
        while(pos < n) {
            int start = pos;
            while (pos < n && input[pos] != '\\') ++pos;
            if (input[pos] == '\\') ++pos;
            if (pos >= n || input[pos] == 'n') {
                if (start > 0 && input[start - 1] == '\\' && input[start] == 't') start++;
                while(input[start + 1] == ' ') start++;
                
                if (pos < n - 1) {
                    temp = input.substr(start, pos - start - 1);
                } else { //最后一个字符不用-1
                    temp = input.substr(start, pos - start);
                }

                if (temp.find('.') != string::npos) {
                    //文件名
                    res = max(res, m[level] + (int)temp.size());
                } else {
                    //文件夹
                    ++level;
                    m[level] = m[level - 1] + (int)temp.size() + 1;
                }
                level = 0;
            } else {
                ++level;  //根据/t/t/t来得到当前level
            }
        }
        return res;
    }
};