class Solution {
public:
    /**
     * @param s: the pearl sequences.
     * @param k: every k same pearls together will be removed.
     * @return: return the pearls after the game.
     */
    string zumaGaming(string &s, int k) {
        stack<pair<char, int>> st; //<char, repetitive count>
        string result = "";
        int len = s.size();
        st.push({s[0], 1});

        for (int i = 1; i < len; ++i) {
            if (!st.empty() && st.top().first == s[i]) {
                int new_same_count = st.top().second + 1;
                st.push({s[i], new_same_count});

                if (new_same_count == k) {
                    while (new_same_count > 0) {
                        st.pop();
                        new_same_count--;
                    }
                }
            } else {
                st.push({s[i], 1});
            }
        }

        while(!st.empty()) {
            result = st.top().first + result;
            st.pop();
        }
        
        return result;
    }
};