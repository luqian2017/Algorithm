class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;   // <number, index>
        vector<int> result;
        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
            if (m.find(target - numbers[i]) != m.end()) {
                if (i > m[target - numbers[i]]) {
                   result.push_back(m[target - numbers[i]]);
                   result.push_back(i);
                }
                else {
                   result.push_back(i);
                   result.push_back(m[target - numbers[i]]);
                }
                
                return result;        
            }
            
            m[numbers[i]] = i;
        }
        
        return result;
    }
    
};