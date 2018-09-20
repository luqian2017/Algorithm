class TwoSum {
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        nums.push_back(number);
        int i=0, pos=0;
        int len=nums.size();
        //similar to insertion sort
        for (i=0; i<len-1; ++i) {
            if (number<=nums[i]) {
                break;
            }
        }
        pos=i;
        for (i=len-1; i>pos; --i) {
            nums[i]=nums[i-1];
        }
        nums[pos]=number;
    }

    /*
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        int p1=0, p2=nums.size()-1;
        while(p1<p2) {
            int sum=nums[p1]+nums[p2];
            if (sum==value) {
                return true;
            } else if (sum>value) {
                p2--;
            } else {
                p1++;
            }
       }
        return false;
    }

    private:
        vector<int> nums;     
};