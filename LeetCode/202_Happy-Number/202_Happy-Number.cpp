class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) return false;
        init();
        unordered_set<int> us;
        
        while (n != 1) {
            if (us.find(n) != us.end()) return false;
            us.insert(n);
            n = proc(n);            
        }
        return true;
    }
private:
    //vector<int> nums(10);
    vector<int> nums = vector<int>(10);
    void init() {
        for (int i = 0; i < 10; i++) {
            nums[i] = i * i;
        }
    }
    
    int proc(int n) {
        int res = 0;
        while (n) {
            res += nums[n % 10];
            n /= 10;
        }
        return res;
    }
    
};