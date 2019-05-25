class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        int N = numbers.size();
        if (N < 3) return 0;
        
        sort(numbers.begin(), numbers.end());
        
        int p1 = 0, p2 = 0, p3 = 0;
        int result = numbers[0] + numbers[1] + numbers[2];
        
        for (int p3 = 3; p3 < N; ++p3) {
            int newTarget = target - numbers[p3];
            p1 = 0, p2 = p3 - 1;
            while(p1 < p2) {
                int twoSum = numbers[p1] + numbers[p2];
                int threeSum = twoSum + numbers[p3];
                
                if (abs(result - target) > abs(threeSum - target)) {
                    result = threeSum;
                } 
                
                if (twoSum < newTarget) {
                    p1++;
                } else if (twoSum > newTarget) {
                    p2--;
                } else {
                    break;
                }
            }
        }
        
        return result;
    }
};