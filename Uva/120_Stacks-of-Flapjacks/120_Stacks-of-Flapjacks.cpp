#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

void FlapjackSort(vector<int> &fj) {
    int n = 0;
    vector<int>::iterator iter = fj.begin();

    while(iter!=fj.end()) {
        cout<<endl<<"n=";
        vector<int>::iterator maxFj = max_element(fj.begin(), fj.end()-n);
        reverse(fj.begin(), maxFj+1);
        cout<<endl<<" ";
        for_each(fj.begin(), fj.end(), [](int i)->void {std::cout << i <<" ";});
        reverse(fj.begin(), fj.end()-n);
        cout<<" ";
        for_each(fj.begin(), fj.end(), [](int i)->void {std::cout << i <<" ";});

        n++;
        iter=fj.begin()+n;
    }

}

int main()
{
    int flapjacks[8] = {2,5,7,6,4,8,11,4};
    vector<int> fj;

    for (int i=0; i<sizeof(flapjacks)/sizeof(flapjacks[0]); i++) {
        fj.push_back(flapjacks[i]);
    }
    cout<<"original flapjacks"<<endl;
    for_each(fj.begin(), fj.end(), [](int i)->void {std::cout << i <<" ";});
    cout<<endl;

    FlapjackSort(fj);

    cout<<endl<<"after sorting"<<endl;
    for_each(fj.begin(), fj.end(), [](int i)->void {std::cout << i <<" ";});

    return 0;
}
