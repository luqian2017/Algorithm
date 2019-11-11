// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        int celebrity = 0;
        for (int i = 1; i < n; ++i) {
         //   if (knows(celebrity, i)) {  //it is also OK
            if (!knows(i, celebrity)) {
                celebrity = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!knows(i, celebrity)) return -1;
            if (i != celebrity && knows(celebrity, i)) return -1;
        }
        
        return celebrity;
    }
};