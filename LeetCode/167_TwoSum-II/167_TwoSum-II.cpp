#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j=numbers.size()-1;
    vector<int> ret;
    while(i<j) {
        long long sum=numbers[i]+numbers[j];
        if (sum>target) {
            j--;
        }else if (sum<target) {
            i++;
        }else {
            ret.push_back(i+1); //index starts from 1
            ret.push_back(j+1); //index starts from 1
            return ret;
        }
    }
}
 
int main()
{
    vector<int> numbers={2,7,11,15};
    vector<int> findIndex=twoSum(numbers, 9);
    for (auto i: findIndex) cout<<i<<" ";
    return 0;
}