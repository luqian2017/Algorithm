class Solution {
public:
    /**
     * @param push: the array push
     * @param pop: the array pop
     * @return: return whether there are legal sequences
     */
    bool isLegalSeq(vector<int> &push, vector<int> &pop) {
        int m = push.size();
        int n = pop.size();
        if (m != n) return false;
        if (n == 0) return true;
        
        stack<int> st;
		int index = 0;   // index is for arr, num is from [1,2,3,...]
		for (int i = 0; i < n; ++i) {
            st.push(push[i]);
		    while(!st.empty() && st.top() == pop[index]) {
		       st.pop();
			   index++;
		    }
		}
		
		if (!st.empty()) return false;

		return true;
    }
};