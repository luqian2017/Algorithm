class Solution {
public:
    /**
     * @param tagList: The tag list.
     * @param allTags: All the tags.
     * @return: Return the answer
     */
    int getMinimumStringArray(vector<string> &tagList, vector<string> &allTags) {
        int m = tagList.size();
        int n = allTags.size();
        if (m > n) return -1;
        
        int p1 = 0, p2 = 0;
        map<string, int> mp;
        for (int i = 0; i < m; ++i) mp[tagList[i]] = 0;
        int matchWordCount = 0;
        int minLen = INT_MAX;

        //move p2
        while(p2 < n) {
            if (mp.find(allTags[p2]) != mp.end()) {
                mp[allTags[p2]]++;
                if (mp[allTags[p2]] == 1) matchWordCount++;
                if (matchWordCount == m) {
                    minLen = min(minLen, p2 - p1 + 1);   
                    //move p1 to right
                    while(p1 < p2) {
                        if (mp.find(allTags[p1]) != mp.end()) {
                             mp[allTags[p1]]--;
                             if (mp[allTags[p1]] == 0) {
                                 matchWordCount--;
                                 p1++;
                                 break;
                             }
                        }
                        p1++;
                        minLen = min(minLen, p2 - p1 + 1);
                    }
                } 
            }
            p2++;
        }
      
        return minLen == INT_MAX ? -1 : minLen;
    }
};