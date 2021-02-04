class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long coeff = 1;
        res.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
          //  cout<<"i="<<i<<" coeff="<<coeff<<endl;
            coeff = coeff * (rowIndex - i + 1) / i;
            res.push_back((int)coeff) ;
        }
        return res;
    }
};
/*
input 30
i=1 coeff=1
i=2 coeff=30
i=3 coeff=435
i=4 coeff=4060
i=5 coeff=27405
i=6 coeff=142506
i=7 coeff=593775
i=8 coeff=2035800
i=9 coeff=5852925
i=10 coeff=14307150
i=11 coeff=30045015
i=12 coeff=54627300
i=13 coeff=86493225
i=14 coeff=119759850
i=15 coeff=145422675
i=16 coeff=155117520
i=17 coeff=145422675
i=18 coeff=119759850
i=19 coeff=86493225
i=20 coeff=54627300
i=21 coeff=30045015
i=22 coeff=14307150
i=23 coeff=5852925
i=24 coeff=2035800
i=25 coeff=593775
i=26 coeff=142506
i=27 coeff=27405
i=28 coeff=4060
i=29 coeff=435
i=30 coeff=30
*/