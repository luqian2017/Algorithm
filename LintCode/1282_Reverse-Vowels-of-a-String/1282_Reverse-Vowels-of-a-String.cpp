class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    string reverseVowels(string &s) {
        int n = s.size();
        if (n == 0) return "";
        
        int left = 0, right = n -1; 
        
        while(left < right) {
            while(!isVowel(s[left]) && (left < right)) left++;
            while(!isVowel(s[right]) && (left < right)) right--;
            if (left < right) {
                swap(s[left], s[right]);
                left++; right--;
            } else {
                return s;
            }
        }
        
        return s;
    }
    
private:
    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};