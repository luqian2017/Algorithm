class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if(words.size() == 0)
            return ans;
        
        int i = 0, j = 0, k;
        while(i < words.size()) {
            //minWidth为当前行最少所需长度，包括单词和空格
            int minWidth = words[i].size();
            for (j = i + 1; j < words.size(); j++){
                if (minWidth + 1 + words[j].size() > maxWidth) {
                    break;
                }
                minWidth += 1 + words[j].size();
            }
            int space = 0, extra = 0;
            string res;
            
            if (j == i + 1) {  //该行只有1个单词
                res = words[i];
                space =  maxWidth - minWidth;   
                res.append(space, ' ');
            } else if (j == words.size()) { //处理到最后一个单词
                res = words[i];
                for (k = i + 1; k < j; k++) {
                    res = res + " " + words[k];
                }
                space =  maxWidth - minWidth;   
                res.append(space, ' ');
            } else {
                int spaceSlot = j - i - 1;
                space = (maxWidth - minWidth) / spaceSlot + 1;
                extra = (maxWidth - minWidth) % spaceSlot;
                
                for(k = i; k < j - 1; k++) {
                    res += words[k];
                    res.append(space, ' ');
                    if (extra > 0) {
                        res += ' ';
                        extra --;
                    }
                }
                res += words[k];
            }
            i = j; 
            cout<<"i="<<i<<" j="<<j<<" res="<<res<<endl;
            ans.push_back(res);
        }
        return ans;
    }
};