// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand10() {
        int a, b, sum;
        do
        {
            a = rand7() - 1;
            b = rand7();
            sum = a * 7 + b;
        } while(sum > 40);

        return (sum - 1) / 4 + 1;
    }
};

