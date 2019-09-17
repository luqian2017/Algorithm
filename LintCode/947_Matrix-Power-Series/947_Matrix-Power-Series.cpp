class Matrix {
public:
    vector<vector<long long>> matrix;

    Matrix(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        matrix.resize(n, vector<long long>(n, 0LL));
    }
    
    void unit() {
          for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
              if (i == j) matrix[i][j] = 1;
    }

    Matrix operator * (const Matrix & M) const {
        Matrix result(m, n, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int h = 0; h < n; ++h) {
                    result.matrix[i][j] += matrix[i][h] * M.matrix[h][j];
                   // result.matrix[i][j] %= m;      
                }
                result.matrix[i][j] %= m;
            }
        }
        return result;
    }

    Matrix operator + (const Matrix & M) const {
        Matrix result(m, n, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.matrix[i][j] = (matrix[i][j] + M.matrix[i][j]) % m;
            }
        }
        return result;
    }
 
    Matrix power(int p) {
        Matrix result(m, n, k);
        result.unit();
        Matrix B = *this;
        while(p) {
            if (p & 0x1) result = result * B;
            B = B * B;
            p /= 2;
        }
        return result;
    }
    
    Matrix sum(int s) {
        if (s == 1) return *this;
        if (s & 0x1) {
            return sum(s - 1) + power(s);
        } else {
           Matrix E(m, n, k);
           E.unit();
           return (power(s / 2) + E) * sum(s / 2);
        }
    }

private:
    int m, n, k;
};



class Solution {
public:
    /**
     * @param A: a n x n matrix
     * @param k: a integer
     * @param m: a integer
     * @return: return a 2D arrays, denote S matrix
     */
    vector<vector<int>> matrixPowerSeries(vector<vector<int>> &A, int k, int m) {
        int n = A.size();
        vector<vector<int>> result;
        if (n == 0) return result;
        result.resize(n, vector<int>(n, 0));
        Matrix M(m, n, k);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0;  j < n; ++j) {
                M.matrix[i][j] = A[i][j];
            }
        }
        
        Matrix Mk = M.sum(k);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = Mk.matrix[i][j];
            }
        }
        
        return result;
    }
};