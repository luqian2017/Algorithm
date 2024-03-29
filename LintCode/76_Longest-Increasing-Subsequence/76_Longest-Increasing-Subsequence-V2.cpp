#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

// find the first number > num
int binarySearch(vector<int> & minLast, int num) {
    int start = 0, end = minLast.size() - 1;
    while (start + 1 < end) {
        int mid = (end - start) / 2 + start;
        if (minLast[mid] < num) {
            start = mid;
        } else {
            end = mid;
        }
    }

    return end;
}

int longestIncreasingSubsequence(vector<int> & nums) {

    vector<int> minLast(nums.size() + 1, 0);
    minLast[0] = INT_MIN;

    for (int i = 1; i <= nums.size(); i++) {
        minLast[i] = INT_MAX;
    }

    for (int i = 0; i < nums.size(); i++) {
        // find the first number in minLast >= nums[i]
        int index = binarySearch(minLast, nums[i]);
        minLast[index] = nums[i];
    }

    for (int i = nums.size(); i >= 1; i--) {
        if (minLast[i] != INT_MAX) {
            return i;
        }
    }

    return 0;
}

int main()
{
  //  vector<int> nums = {2, 3, 1, 7, 6, 4, 8};
    vector<int> nums = {2, 3, 1};
    int result;
    result = longestIncreasingSubsequence(nums);
    cout<<result<<endl;
}
