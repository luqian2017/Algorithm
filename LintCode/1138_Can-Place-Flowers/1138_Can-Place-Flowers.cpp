class Solution {
public:
    /**
     * @param flowerbed: an array
     * @param n: an Integer
     * @return: if n new flowers can be planted in it without violating the no-adjacent-flowers rule
     */
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = flowerbed.size();
        if ((len == 0) || (len < n)) return false;
        
        int p1 = -1, p2 = 0;  //p2 is ahead of p1
        while (p2 < len) {

            while(flowerbed[p2] == 0) p2++;
            if (p2 > 0) {
                int gap = p2 - p1 - 1; //gap is the available slots between 1s, such as 1---1
                n -= (gap + 1) / 2 - 1;
                p1 = p2;
                
            }
            p2++;
        }
        
        if (n == 0) return true;
        else return false;
    }
};