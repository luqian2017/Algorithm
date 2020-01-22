    int searchInsert(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        
        int start=0, end=nums.size()-1;
        
        while(start+1<end) {
            int mid=start+(end-start)/2;
            if (nums[mid]==target) 
                return mid;
            else if (nums[mid]<target)
                start=mid;
            else
                end=mid;
        }

        if (nums[start]>=target) return start;
        if (nums[end]<target) return end+1;
        return end;    
    }
    
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        vector<int> result;
        if (k>A.size()) return result;

        int pos = searchInsert(A, target);
        int p1, p2;
        if (pos == 0) {
            p1=0; p2=1;
        } else {//if (pos == A.size()) {
            p1=pos-1; p2=pos;
        } 
       
        int count=0;
        while(count<k && p1>=0 && p2<A.size()) {
            if ((target-A[p1]) <= (A[p2]-target)) {//note <=here
                result.push_back(A[p1--]);
            } else {
                result.push_back(A[p2++]);
            }
            count++;
        }
        while(count<k) {
            if (p1<0) {
                result.push_back(A[p2++]);
            } else {
                result.push_back(A[p1--]);
            }
            count++;
        }    
    
        return result;
    }