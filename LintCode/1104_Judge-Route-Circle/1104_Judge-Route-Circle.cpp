class Solution {
public:
    /**
     * @param moves: a sequence of its moves
     * @return: if this robot makes a circle
     */
    bool judgeCircle(string &moves) {
        int len = moves.size();
        int x = 0, y = 0;
        for (int i = 0; i < len; ++i) {
            char c = moves[i];
            switch (c) {
                case 'R':
                    x += 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
                case 'U':
                    y -= 1;
                    break;
                case 'D':
                    y += 1;
                    break;
                default:
                    break;
            }
        }
        if (x == 0 && y == 0) return true;
        return false;
    }
};