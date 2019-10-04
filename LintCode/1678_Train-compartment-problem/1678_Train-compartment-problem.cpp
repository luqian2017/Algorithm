
class Solution {
public:
    /**
     * @param arr: the arr
     * @return:  the number of train carriages in this transfer station with the largest number of train carriages
     */
    int trainCompartmentProblem(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        stack<int> st;
		int result = 0;
		int index = 0;   // index is for arr, i is from [1,2,3,...]
		for (int i = 1; i <= n; ++i) {
            st.push(i);
			result = max(result, (int)st.size() - 1);
		    while(!st.empty() && st.top() == arr[index]) {
		       st.pop();
			   index++;
		    }
		}
		
		if (!st.empty()) {
		    return -1;
        }
        
		return result;
    }
};