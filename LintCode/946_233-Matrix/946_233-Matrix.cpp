class Matrix {
public:
    vector<vector<long long>> matrix;
    
    Matrix(int n, int mod) {
        dim = n;
        this->mod = mod;
        matrix.resize(dim, vector<long long>(dim, 0LL));
    }
    
    void unit() {
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                //matrix[i][j] = (long long)(i == j);
                if (i == j) matrix[i][j] = 1LL;
            }
        }
    }
    
    Matrix operator * (const Matrix & m) const {
        Matrix result(dim, mod);
        for (int i = 0; i < dim; ++i) {
            for (int k = 0; k < dim; ++k) {
                if (matrix[i][k] == 0) continue;
                for (int j = 0; j < dim; ++j) {
                    result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                    result.matrix[i][j] %= mod;
                }
            }
        }
        return result;
    }

    Matrix power(int n) {
        Matrix result(dim, mod);
        result.unit();
        while(n) {
            if (n & 0x1) result =  result * (*this);
            //matrix = matrix * matrix;
            *this = (*this) * (*this);
            n /= 2;
        }
        return result;
    }
    
private:
    int dim, mod;
};


class Solution {
public:
    /**
     * @param X: a list of integers
     * @param m: an integer
     * @return: return an integer
     */
    int calcTheValueOfAnm(vector<int> &X, int m) {
        int n = X.size();
        if ((n == 0) && (m == 0)) return 0;
        if (m == 0) return X[n - 1];
        Matrix mx(n + 2, 10000007);
        
        for(int i = 0; i <= n; ++i) mx.matrix[i][0] = 10;
        for(int i = 0; i <= n + 1; ++i) mx.matrix[i][n + 1] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                mx.matrix[i][j] = 1;
        
        Matrix tmp = mx.power(m);
        long long answer = 23 * tmp.matrix[n][0] + 3 * tmp.matrix[n][n + 1];
 
        for (int i = 1; i <= n; ++i) {
            answer += tmp.matrix[n][i] * X[i - 1];
        }
        
        answer %= 10000007;
        return answer;
    }
};