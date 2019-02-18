class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        int k = times.size();
        int totalTime = 0; 
        int minTime = INT_MAX, maxTime = 0;
        for (int i = 0; i < k; ++i) {
            minTime = min(minTime, times[i]);
            maxTime = max(maxTime, times[i]);
        }
        int left = n * minTime / k;
        int right = n * maxTime / k;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (checkValid(times, mid, n)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        if (checkValid(times, left, n)) return left;
        else return right;
    }
    
private:
    //given array times, time t,
     is it ok to finish n books in time?
    bool checkValid(vector<int> &times, int t, int n) {
        int copyTime = times[0];
        int count = 0;     //count of books 
        int k = times.size();
        for (int i = 0; i < k; ++i) {
            count += t / times[i]; // the ith guy can copy t/times[i] books
        }

        return count >= n;
    }
};

//input cases:
//1) 100
//[1,2]
//2) 4
//[3,2,4]