class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int pA = 0, pB = 0;
        int carry = 0;
        string result;
        while(pA < a.size() && pB < b.size()) {
            int sum = a[pA] - '0' + b[pB] - '0';
            sum = sum + carry;
            carry = (sum >= 2) ? 1 : 0;
            sum = sum & 0x1;
            result = to_string(sum) + result;
            pA++;
            pB++;
        }
        
        while(pA < a.size()) {
            int sum = a[pA] - '0';
            sum = sum + carry;
            carry = (sum >= 2) ? 1 : 0;
            sum = sum & 0x1;
            result = to_string(sum) + result;
            pA++;
        }

        while(pB < b.size()) {
            int sum = b[pB] - '0';
            sum = sum + carry;
            carry = (sum >= 2) ? 1 : 0;
            sum = sum & 0x1;
            result = to_string(sum) + result;
            pB++;
        }

        if (carry == 1) result = '1' + result;
        return result;
    }
};