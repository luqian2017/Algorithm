class Solution {
public:
    /**
     * @param J: the types of stones that are jewels
     * @param S: representing the stones you have
     * @return: how many of the stones you have are also jewels
     */
    int numJewelsInStones(string &J, string &S) {
        // Write your code here
        int count=0;
        for(int i=0;i<S.length();i++)
        {
            if(J.find(S[i])!=string::npos)
            {
                count++;
            }
        }
        return count;
    }
};
