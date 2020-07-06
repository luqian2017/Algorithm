class Solution {
public:
    /**
     * @param score: Each student's grades
     * @param ask: A series of inquiries
     * @return: Find the percentage of each question asked
     */
    vector<int> englishSoftware(vector<int> &score, vector<int> &ask) {
        int score_len = score.size();
        int ask_len = ask.size();
        
        vector<int> counting(101, 0), prefix_sum(101, 0);
        for (int i = 0; i < score_len; ++i) {
            counting[score[i]]++;
        }
        
        prefix_sum[0] = counting[0];
        for (int i = 1; i <= 100; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + counting[i];
        }

        vector<int> result;
        for (int i = 0; i < ask_len; ++i) {
            result.push_back((prefix_sum[score[ask[i] - 1]] - 1) * 100 / score_len);
        }
        
        return result;
    }
};