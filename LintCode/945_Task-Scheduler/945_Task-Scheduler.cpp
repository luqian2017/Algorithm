class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        int taskSize = tasks.size();
        
        vector<int> data(26, 0);
        for (int i = 0; i < taskSize; ++i) {
            data[tasks[i] - 'A']++;
        }
        
        sort(data.begin(), data.end());
        
        int numOfMaxTasks = 1;
        for (int i = 24; i >= 0; --i) {
            if (data[i] == data[25]) numOfMaxTasks++;
            else break;
        }
        
        return max(taskSize, (data[25] - 1) * (n + 1) + numOfMaxTasks);
    }
};