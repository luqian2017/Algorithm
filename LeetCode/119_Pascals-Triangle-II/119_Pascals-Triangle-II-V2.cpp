class Solution {
public:
vector<int> getRow(int rowIndex) {
    if (rowIndex==0) return vector<int>(1,1);
    if (rowIndex==1) return vector<int>(2,1);

    vector<int> result(rowIndex+1, 1);

    for (int i=2; i<=rowIndex; ++i) {
        vector<int> prevResult=result;
        for (int j=1; j<i; ++j) {
            result[j]+=prevResult[j-1];
        }
    }

    return result;
}
};