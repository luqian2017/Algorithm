#include <iostream>
#include <vector>
 
using namespace std;
 
bool isValidSudoku(vector<vector<char>>& board) {
 
    if (board.size()!=9) return false;
 
    vector<int> row(9,0), col(9,0), grids(9,0);
 
    for (int i=0; i<9; ++i) {
        if (board[i].size()!=9) return false;
        for (int j=0; j<9; ++j) {
            char c=board[i][j];
            if (c=='.') continue;
            int num=0x1<<(board[i][j]-'0');
            if ((row[i]&num) || (col[j]&num) || (grids[i/3*3+j/3]&num))
                return false;
            row[i]|=num; col[j]|=num; grids[i/3*3+j/3]|=num;
        }
    }
 
    return true;
}
 
int main()
{
    vector<vector<char> > board{ {'.','.','.','.','5','.','.','1','.'},
                                 {'.','4','.','3','.','.','.','.','.'},
                                 {'.','.','.','.','.','3','.','.','1'},
                                 {'8','.','.','.','.','.','.','2','.'},
                                 {'.','.','2','.','7','.','.','.','.'},
                                 {'.','1','5','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','2','.','.','.'},
                                 {'.','2','.','9','.','.','.','.','.'},
                                 {'.','.','4','.','.','.','.','.','.'} };
 
    cout<<isValidSudoku(board);
 
    return 0;
}

————————————————
版权声明：本文为CSDN博主「纸上得来终觉浅 绝知此事要躬行」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/roufoo/article/details/79655726