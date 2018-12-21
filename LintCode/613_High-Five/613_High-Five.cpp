/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        int len = results.size();
        
        map<int, priority_queue<int, vector<int>, greater<int>> > mp; //id, min-heap
        map<int, double> result;
        for (int i = 0; i < len; ++i) {
            int studentId = results[i].id;
            int studentScore = results[i].score;
            mp[studentId].push(studentScore);
            if (mp[studentId].size() > 5)
                mp[studentId].pop();
        }
        
        for (auto m : mp) {
            double sum = 0;
            while(m.second.size() > 0) {
                sum += m.second.top();
                m.second.pop();
            }
            result[m.first] = sum / 5;
        }
        
        return result;
    }
};