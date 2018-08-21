
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());
    int p1, p2;
    p1 = 0;
    p2 = nums.size()-1;
 
    while(p1!=p2) {
        if (nums2[p1]+nums2[p2]>target)
            p2--;
        else if (nums2[p1]+nums2[p2]<target)
            p1++;
        else
            break;
    }
 
    vector<int> result;
 
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]==nums2[p1])
            result.push_back(i);
        else if (nums[i]==nums2[p2])
            result.push_back(i);
    }
 
    return result;
 
}
 
#if 0
vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> um;
    for (int i=0; i<numbers.size(); i++) {
        int diff = target - numbers[i];
        if (um.count(diff) > 0)
            return vector<int>{um[diff], i};
        else
            //um.insert(make_pair(numbers[i], i));   //??????
            um[numbers[i]]=i;
    }
 
    return vector<int>();
 
}
#endif
 
 
int main()
{
    vector<int> a = {2,2,5,6};
    vector<int> ret = twoSum(a, 4);
    for (vector<int>::iterator it= ret.begin(); it!=ret.end(); it++)
        cout<<*it<<" ";
 
    return 0;
}
