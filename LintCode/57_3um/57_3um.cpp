class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        int n = numbers.size();
        if (n < 3) return {{}};
        sort(numbers.begin(), numbers.end());
        int p1 = 0, p2 = 0, p3 = 2;
        set<vector<int>> s;
        vector<vector<int>> result;
        while(p3 < n) {
            p1 = 0; p2 = p3 - 1;
            int target = -numbers[p3];
            while(p1 < p2) {
                int sum = numbers[p1] + numbers[p2];
                if (sum == target) {
                    s.insert({numbers[p1], numbers[p2], numbers[p3]});
                    p1++; p2--;
                } else if (sum > target) {
                    p2--;
                } else {
                    p1++;
                }
            }
            p3++;
        }
        
        result.assign(s.begin(), s.end());
        return result;
    }
};