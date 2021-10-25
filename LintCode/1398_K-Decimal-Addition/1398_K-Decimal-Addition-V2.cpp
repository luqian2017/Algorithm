class Solution {
public:
    /**
     * @param k: The k
     * @param a: The A
     * @param b: The B
     * @return: The answer
     */
    string addition(int k, string &a, string &b) {
        string res = "";
        int posa = a.size() - 1, posb = b.size() - 1, carry = 0;
        int starta = 0, startb = 0;

        for (int i = 0; i < posa; i++) {
            if (a[i] != '0') {
                starta = i;
                break;
            }
        }
        for (int i = 0; i < posb; i++) {
            if (b[i] != '0') {
                startb = i;
                break;
            }
        }

        while (posa >= starta || posb >= startb) {
            int numa = posa >= 0 ? a[posa] - '0' : 0;
            int numb = posb >= 0 ? b[posb] - '0' : 0;
            int num = numa + numb + carry;
            if (num >= k) {
                carry = 1;
                num = num - k;
            } else {
                carry = 0;
            }
            res = to_string(num) + res; // res = (char)(num + '0') + res; is also OK
            posa--;
            posb--;
        }
        
        if (carry > 0) res = '1' + res;
       
        return res;
    }
};