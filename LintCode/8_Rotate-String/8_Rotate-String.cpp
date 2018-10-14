class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        //string str1 = str.substr(0, str.size() - offset);
        //string str2 = str.substr(str.size() - offset);
        if (str.size() == 0) return;
        offset = offset % str.size();
        reverse(str, str.size() - offset, str.size() - 1);
        reverse(str, 0, str.size() - offset - 1);
        reverse(str, 0, str.size() - 1);
    }
    
private:
    void reverse(string &str, int start, int end) {
        
		while(start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
};