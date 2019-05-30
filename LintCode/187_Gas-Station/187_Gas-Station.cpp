class Solution {
public:
    /**
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();

        if (N == 0) return -1;
        int gasSum = 0;
        int candidate = 0;
        int totalSum = 0;

        for (int i = 0; i < N; ++i) {
            gasSum += gas[i];

            if (gasSum < cost[i]) {
                gasSum = 0;
                candidate = (i == N) ? 0 : i + 1;
            } else {
                gasSum -= cost[i];
            }

            totalSum += gas[i] - cost[i];
        }
        candidate = candidate % N;
        if (totalSum < 0) return -1;
        return candidate;
    }
};