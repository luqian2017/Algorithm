#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primeFactorization(int n) {
     vector<int> result;
     if (n<=1) return result;
     int sq=sqrt(n);
     for (int i=2; i<=sq; ++i) {
         if (n==1) return result;
         while((n%i==0) && (n>1)) {
            result.push_back(i);
            n=n/i;
         }
     }
     if (n!=1) result.push_back(n);
}

int main()
{
    vector<int> ret1=primeFactorization(10);
    for (auto i : ret1) cout<<i<<" ";
    cout<<endl;

    vector<int> ret2=primeFactorization(660);
    for (auto i : ret2) cout<<i<<" ";
    cout<<endl;

    vector<int> ret3=primeFactorization(1024);
    for (auto i : ret3) cout<<i<<" ";
    cout<<endl;

    return 0;
}

---------------------

本文来自 青灯照壁夜读书 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/roufoo/article/details/80321963?utm_source=copy 