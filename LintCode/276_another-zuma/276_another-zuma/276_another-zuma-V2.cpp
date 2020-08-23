class Solution
{
public:
    /**
     * @param s: the pearl sequences.
     * @param k: every k same pearls together will be removed.
     * @return: return the pearls after the game.
     */
    string zumaGaming(string &s, int k)
    {
        if (s.size() < k || k <= 0)
        {
            return s;
        }
        bool del = true;
        while(del)
        {
            del = false;
            int start = 0;
            int count = 1;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] == s[start])
                {
                    count++;
                    if (count == k)
                    {
                        s.erase(start, k);
                        del = true;
                    }
                }
                else
                {
                    start = i;
                    count = 1;
                }
            }
        }
        return s;
    }
};