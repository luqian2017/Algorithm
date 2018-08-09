#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

//test if we can divide the data array into x parts, with the max of the sum in each part not larger than x
bool P(vector<int>&data, int k, long long x) {
    int p1 = data.size()-1;
    long long tempSum = 0;
    ans.resize(0);

    while (p1 >= 0) {
        while ((tempSum <= x) && (p1>=k-2)) {
            tempSum += data[p1--];
         }

        p1++; //bounce back because p1 moves too much.

        ans.push_back(p1);
        k--;

        if (p1<k-1) {
           return false;
        }

        tempSum = 0;

        if (k==1) {
            long long sum1 = 0;
            for (int i=0; i<=p1; i++) {
                sum1 += data[i];
            }
            if (sum1 <= x) {
                return true;
            }
            else {
                return false;
            }
        }

    }

}

int main()
{
    int n,k,T;
    vector<int> data;

    cin>>T;
    while(T--) {
       long long sum = 0;
       int maxi = 0;
       cin>>n>>k;
       data.resize(n);
       for (int i=0; i<n; i++){
           cin>>data[i];
           sum+=data[i];
           maxi=max(maxi, data[i]);
       }

       if (k==1) {
           for (vector<int>::iterator it = data.begin(); it<data.end(); it++)
               cout<<*it<<" ";
           cout<<endl;
           continue;
       }

       //binary search with P(x)
       long long l = 0;
       long long r = sum;

       while (l<r) {
           long long m = l + (r-l)/2;
           if (P(data, k, m)) {
               r = m;   //the answer is less than or equal to m
           }
           else {
               l = m+1; //the answer should be larger than m
           }
       }

       P(data, k, l);

       vector<int>::reverse_iterator  r_it = ans.rbegin();
       for (int i=0; i<data.size(); i++) {
          cout<<data[i]<<" ";
          if (i==*r_it) {
              cout<<"/ ";
              ++r_it;
          }
          cout<<endl;
       }
    }

    return 0;
}