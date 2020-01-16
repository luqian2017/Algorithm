//from jiuzhang
//考点:
//Two pointers + HashSet
//题解：
//使用Two pointers，右指针不断向右移，直到包含所有字符串，
//使用HashSet维护Two pointers中都有哪些字符串出现，左指针一次移动一下并更新
//Two pointers中都有哪些字符串出现。时间复杂度O(n)。

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    /**
     * @param tagList: The tag list.
     * @param allTags: All the tags.
     * @return: Return the index pair of string array
     */
    int getMinimumStringArray(vector<string> &tagList, vector<string> &allTags) {
        // Write your code here
        unordered_map<string, int> tagMap;
        for (auto &str : tagList) {
            tagMap[str] = 0;
        }
        int tagSize = tagMap.size();
        int left = 0, right = 0, num = 0, ans = allTags.size() + 1, idxL = -1, idxR = -1;
        while (left < allTags.size()) {
            while (right < allTags.size() && num < tagSize) {
                string &strRight = allTags[right];
                if (tagMap.find(strRight) != tagMap.end()) {
                    if (!tagMap[strRight]) {
                        num++;
                    }
                    tagMap[strRight]++;
                }
                right++;
            }
            if (num == tagSize && (right - left) < ans) {
                idxL = left;
                idxR = right - 1;
                ans = right - left;
            }
            string &strLeft = allTags[left];
            if (tagMap.find(strLeft) != tagMap.end()) {
                tagMap[strLeft]--;
                if (!tagMap[strLeft]) {
                    num--;
                }   
            }
            left++;
        }
        if(idxR == -1 && idxL == -1) {
            return -1;
        }
        return idxR - idxL + 1;
    }
};