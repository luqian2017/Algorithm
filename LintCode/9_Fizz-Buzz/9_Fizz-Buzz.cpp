class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> result(n, "");
        for (int i = 1; i <= n; ++i) {
            int rem3 = i % 3, rem5 = i % 5;
            if (rem3 == 0 && rem5 == 0) result[i - 1] = "fizz buzz";
            else if (rem3 == 0) result[i - 1] = "fizz";
            else if (rem5 == 0) result[i - 1] = "buzz";
            else result[i - 1] = to_string(i);
        }
        return result;
    }
};