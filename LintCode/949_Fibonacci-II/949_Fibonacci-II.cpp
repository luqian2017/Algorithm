struct Matrix {
    long long matrix[2][2];
    
    //void zero() {
    Matrix() {
        for (int i = 0; i < 2; ++i) 
            for (int j = 0; j < 2; ++j)
                matrix[i][j] = 0;
    }
    
    void unit() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (i == j) matrix[i][j] = 1;
    }
    
    Matrix operator * (const Matrix & m) const {
        Matrix tmp;
        for (int i = 0; i < 2; ++i) {
            for (int k = 0; k < 2; ++k) {
                if (matrix[i][k] == 0) continue;
                for (int j = 0; j < 2; ++j) {
                    tmp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                    tmp.matrix[i][j] %= 10000;
                }
            }
        }
        return tmp;
    }
    
    Matrix power(int n) {
        Matrix result;
        result.unit();
        while(n) {
            if (n & 0x1) result = result * (*this);
            *this = (*this) * (*this);
            n /= 2;
        }
        return result;
    }
};

class Solution {
public:
    /**
     * @param n: an integer
     * @return: return a string
     */
    string lastFourDigitsOfFn(int n) {
        if (n == 0) return "0";
        Matrix A;
        A.matrix[0][0] = 1;
        A.matrix[0][1] = 1;
        A.matrix[1][0] = 1;
        A.matrix[1][1] = 0;
        
        Matrix m = A.power(n - 1);
        string answer;
        int p = m.matrix[0][0];
        if (p == 0) answer = "0";
        else {
            for (int i = 0; i < 4; ++i) {
                answer = to_string(p % 10) + answer;
                p /= 10;
            }
        }
        
        return answer;
    }
};