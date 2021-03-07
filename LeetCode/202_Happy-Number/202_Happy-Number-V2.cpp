class Solution {
public:
    bool isHappy(int n) {
        int p = n, q = n; //注意不能是n+1，因为这里n+1并不一定是n的下一个节点，写成q=getNext(n)可以。
        do {
            p = getNext(p);
            q = getNext(getNext(q));
        } while (p != q && q != 1);
        return q == 1;
    }
private:
    int getNext(int x) {
        int res = 0;
        while (x) {
            int temp = x % 10;
            res += temp * temp;
            x /= 10;
        }
        return res;
    }
};