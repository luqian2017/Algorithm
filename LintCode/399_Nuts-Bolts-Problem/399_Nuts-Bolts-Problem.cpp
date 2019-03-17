/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will returnds -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare){
        quickSort(nuts, bolts, 0, nuts.size() - 1, compare);
    }
    
private:
    void quickSort(vector<string> &nuts, vector<string> &bolts, int l, int r, Comparator compare) {
        if (l >= r) return;
        string pivot = nuts[l];
        int pos = 0, cnt = 0;
        //find the position of pivot in bolts[]
        for (int i = l; i <= r; ++i) {
            int cp = compare.cmp(pivot, bolts[i]);
            if (cp == 1) cnt++; // # of bolts larger than pivot
            else if (cp == 0) {
                pos = i;
            }
        }
        cnt += l;
        swap(bolts[pos], bolts[cnt]);
        pos = cnt; //pivot's position
        
        int i = l, j = r;
        while(i < pos && pos < j) {
            while(i < pos && compare.cmp(pivot, bolts[i]) == 1) {
                i++;
            }
            while(pos < j && compare.cmp(pivot, bolts[j]) == -1) {
                j--;
            }
            if (i < pos && pos < j) {
                swap(bolts[i], bolts[j]);
                i++; j--;
            }
        }
        
        pivot = bolts[pos];
        swap(nuts[pos], nuts[l]); // why it is not nuts[cnt] ?
        i = l; j = r;
        while(i < pos && pos < j) {
            while(i < pos && compare.cmp(nuts[i], pivot) == -1) {
                i++;
            }
            while(pos < j && compare.cmp(nuts[j], pivot) == 1) {
                j--;
            }
            if (i < pos && pos < j) {
                swap(nuts[i], nuts[j]);
                i++; j--;
            }
        }
        
        quickSort(nuts, bolts, l, pos - 1, compare);
        quickSort(nuts, bolts, pos + 1, r, compare);
    }
};