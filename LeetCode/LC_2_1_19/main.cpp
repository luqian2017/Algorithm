//#include <string.h>
//#include <algo.h>
//#include <vector.h>
//#include <stdlib.h>
//#include <iostream.h>

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
    public:
      //Solution(void);
      //Solution(const Solution &);
      //~Solution(void);
      //Solution & operator=(const Solution &);

      vector<int> grayCode(int n)
      {
        int i,j;
        vector<int> result;
        vector<int>::iterator iter;
        result.reserve(1<<n);
        result.push_back(0);
        for (i=0; i<n; i++)
        {
           cout << "i=" << i<<endl;
           const int highest_bit = 1 << i;

           cout<<"result_size="<<result.size()<<endl;
           for (j = result.size() - 1; j>=0; j--)
           {
               result.push_back(highest_bit | result[j]);
               cout<<"push_back "<<bitset<3>(highest_bit | result[j])<<endl;
           }
        }

        for (iter=result.begin(); iter !=result.end(); iter++)
        {
            //cout<<(*iter)<<endl;
            cout<<bitset<3>(*iter)<<endl;
        }
        return result;
      }
};

int main()
{

  Solution s;
  s.grayCode(3);
  /*
  vector<int> v;  // create an empty vector of integers
  int input;
  while (cin >> input)    // while not end of file
    v.push_back (input);  // append to vector

  // sort takes two random iterators, and sorts the elements between
  // them.  As is always the case in STL, this includes the value
  // referred to by first but not the one referred to by last; indeed,
  // this is often the past-the-end value, and is therefore not
  // dereferenceable.
  sort(v.begin(), v.end());

  int n = v.size();
  for (int i = 0; i < n; i++)
    cout << v[i] << "\n";
  */
  //return 0;
}
