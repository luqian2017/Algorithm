struct cmp {
    bool operator() (int & a, int & b) {
        string str_a = to_string(a), str_b = to_string(b);
        int M = str_a.size(), N = str_b.size();
        
        if (M == N) return a > b;
        int minNum = min(M, N);
        
        for (int i = 0; i < minNum; ++i) {
            if (str_a[i] > str_b[i]) return true;
            else if (str_a[i] < str_b[i]) return false;
        }
        
        if (M == minNum) {
            return str_b[minNum] < str_a[0];
        } else {
            return str_a[minNum] > str_b[0];
        }
        
    }
} compare;

class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        int N = nums.size();
        if (N == 0) return "";
        
        string result = "";
        sort(nums.begin(), nums.end(), compare);
        
        for (auto n : nums) {
            result = result + to_string(n);
        }

        int count0 = 0;
        for (int i = 0; i < N; ++i) {
            if (result[0] == '0') count0++;
        }
        
        if (count0 == N) return "0";
        if (count0 == 0) return result;
        return result.substr(count0);
    }
};