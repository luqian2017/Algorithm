class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        int m = image.size();
        if (m == 0) return 0;
        int n = image[0].size();
        vector<vector<char>> image2 = image, image3 = image;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (image2[i - 1][j] == '1') image2[i][j] = '1';
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (image3[i][j - 1] == '1') image3[i][j] = '1';
            }
        }

        int widthX = 0, widthY = 0;
        for (int i = 0; i < n; ++i) {
            if (image2[m - 1][i] == '1') widthX++;
        }

        for (int i = 0; i < m; ++i) {
            if (image3[i][n - 1] == '1') widthY++;
        }

        return widthX * widthY;
    }
};