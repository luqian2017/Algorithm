// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand10() {
        int sum1 = 0, sum2 = 0;
        sum1 = rand7();
        while ((sum2 = rand7()) > 4) continue;
        return sum1 + sum2 - 1;
    }
};