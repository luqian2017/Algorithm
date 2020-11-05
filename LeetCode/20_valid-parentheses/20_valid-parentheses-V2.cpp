class Solution {
public:
    bool isValid(string s) {
        int i = 0, len = s.size();
        bool flag = true;
        while(i < len && flag) {
            flag &= judgeOne(s, &i, 0);
          //  cout<<"i="<<i<<" flag="<<flag<<endl;
        }
        return flag;
    }
private:
    bool judgeOne(string s, int *i, int d) {
        bool flag = true;
        int j = d;
       // printf("in %d\n", *i);
        while (s[*i] && flag) {
            switch(s[*i]) {
                case '(':
                    ++(*i);
                    flag = judgeOne(s, i, d + 1);
                    if (s[*i] == ')') {++(*i); flag &= true;} 
                    else if (s[*i] == ']' || s[*i] == '}' || s[*i] == '\0') flag = false;
                    break;
                case '[':
                    ++(*i);
                    flag = judgeOne(s, i, d + 1);
                    if (s[*i] == ']') {++(*i); flag &= true;} 
                    else if (s[*i] == ')' || s[*i] == '}' || s[*i] == '\0') flag = false;
                    break;
                case '{':
                    ++(*i);
                    flag = judgeOne(s, i, d + 1);
                    if (s[*i] == '}') {++(*i); flag &= true;} 
                    else if (s[*i] == ')' || s[*i] == ']' || s[*i] == '\0') flag = false;
                    break;
                case ')':
                case ']':
                case '}':
                    return j == 0 ? false : true && flag;
                default:
                    return false;

            }
        }
        return flag;
       }

};