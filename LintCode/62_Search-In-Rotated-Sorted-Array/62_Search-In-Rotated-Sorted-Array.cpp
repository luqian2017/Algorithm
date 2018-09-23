int search(vector<int> &A, int target) {
    if (A.size()==0) return -1;
    int start=0, end=A.size()-1;

    if (A[start]==target) return start;
    if (A[end]==target) return end;

    while(start+1<end) {
        int mid=start+(end-start)/2;
        if (A[mid]==target) return mid;
        if (A[mid]>A[start] && target<A[start]) start=mid;
        if (A[mid]<A[start] && target>A[start]) end=mid;

        if ((A[mid]<A[start] && target<A[start]) || (A[mid]>A[start] && target>A[start])) {
            if (A[mid]>target) end=mid;
            else start=mid;
        }
    }
        
	if (A[start]==target) return start;
    if (A[end]==target) return end;
    return -1;
}
