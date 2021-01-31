class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, a1, b1;
        for (int i = 0, c; i < nums.size(); i++) {
            c = nums[i];
            a1 = (a & ~b & ~c) | (~a & b & c);
            b1 = (~a & b & ~c) | (~a & ~b & c);
           // cout<<"i="<<i<<" num="<<nums[i]<<" a="<<a<<" b="<<b<<" a1="<<a1<<" b1="<<b1<<endl;
            a = a1;
            b = b1;
        }
        return b;
    }
};


/*
Your input
[2,2,3,2]
stdout
i=0 num=2 a=0 b=0 a1=0 b1=2
i=1 num=2 a=0 b=2 a1=2 b1=0
i=2 num=3 a=2 b=0 a1=0 b1=1
i=3 num=2 a=0 b=1 a1=0 b1=3

Output
3
Expected
3
*/