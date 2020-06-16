class Solution {
public:
    /**
     * @param k: The k
     * @param a: The A
     * @param b: The B
     * @return: The answer
     */
    string addition(int k, string &a, string &b) {
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;
        int non_zero_pos_a = 0;
        int non_zero_pos_b = 0;
        
        while(a[non_zero_pos_a] == '0') non_zero_pos_a++;
        while(b[non_zero_pos_b] == '0') non_zero_pos_b++;
        
        a = a.substr(non_zero_pos_a);
        b = b.substr(non_zero_pos_b);
        int len_a = a.size();
        int len_b = b.size();
        
        int min_len = min(len_a, len_b);
        int carry = 0;
        string result;
        for (int i = 0; i < min_len; ++i) {
            int v_a = a[len_a - 1 - i] - '0';
            int v_b = b[len_b - 1 - i] - '0';
            int v = v_a + v_b + carry;
            carry = v / k;
            v %= k;            
            result = to_string(v) + result;
        }
        len_a -= min_len; len_b -= min_len;

        if (len_a == len_b) {
            if (carry == 0)  return result;
            return '1' + result;
        }
        
        string c = (len_a > 0) ? a.substr(0, len_a) : b.substr(0, len_b);
        int len_c = (len_a > 0) ? len_a : len_b;
        for (int i = len_c - 1; i >= 0; --i) {
            int v_c = c[i] - '0';
            int v = v_c + carry;
            carry = v / k;
            v %= k;
            result = to_string(v) + result;
            len_c--;
        }
        
        if (carry > 0) return '1' + result;
        return result;
    }
};