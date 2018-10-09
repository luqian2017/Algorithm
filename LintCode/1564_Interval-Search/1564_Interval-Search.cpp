

class Solution {
public:
    /**
     * @param intervalList: 
     * @param number: 
     * @return: return True or False
     */
     
     
    string isInterval(vector<vector<int>> &intervalList, int number) {

        // <point, symbol>  symbol=1 is start of an interval, symbol==1 is the end of an interval
        map<int, int> mp; 
        int intervalCount = intervalList.size();
        
        int pointCount = intervalCount << 1;
        vector<int> points;
        
        for (int i = 0; i < intervalCount; ++i) {
            points.push_back(intervalList[i][0]);
            points.push_back(intervalList[i][1]);
            
            if (mp.find(intervalList[i][0]) != mp.end())
                mp[intervalList[i][0]] = 1;
            else
                mp[intervalList[i][0]]++;
                
            if (mp.find(intervalList[i][1]) != mp.end())
                mp[intervalList[i][1]] = -1;
            else
                mp[intervalList[i][1]]--; 
        }
    
        sort(points.begin(), points.end());
        int count = 0;
        map<int, int> mp2; //<point, count>
        for (int i = 0; i < pointCount; ++i) {
            count += mp[points[i]];
            mp2[points[i]] = count;   //count = 0 means no interval, count = 1 is a new interval of in the middle of an interval
        }
        
        int index = binarySearch(points, number); 

        if (mp2[points[index]] > 0) 
            return "True";
        else 
            return "False";
        
    }

private:
//find the position that is just smaller than or equal to number
    int binarySearch(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        int start = 0, end = nums.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) 
                start = mid;
            else if (nums[mid] > target)
                end = mid;
            else 
                return mid;
        }
        return start;   
    }
    
};