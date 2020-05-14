class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        //return to_string(stoi(num1) + stoi(num2));
        int n1 = num1.size();
        int p1 = n1 - 1;
        int n2 = num2.size();
        int p2 = n2 - 1;
        int sum = 0, carry = 0;
        string result = "";
        
        while(p1 >= 0 && p2 >= 0) {
            sum = num1[p1] - '0' + num2[p2] - '0' + carry;
            carry = sum / 10;
            result = to_string(sum % 10) + result;
            p1--; p2--;
        }

        int p = -1; string num;
        if (p1 >= 0) {
            p = p1; num = num1;
        } else if (p2 >= 0) {
            p = p2; num = num2;
        }
        
        if (p < 0) return carry > 0 ? '1' + result : result;
         
        while (p >= 0) {
            sum = num[p] - '0' + carry;
            carry = sum / 10;
            result = to_string(sum % 10) + result;
            p--;
        }

        return carry > 0 ? '1' + result : result;
    }
};