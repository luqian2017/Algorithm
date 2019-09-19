class Solution {
public:
    /*
     * @param stk: an integer stack
     * @return: void
     */
    void stackSorting(stack<int>& stk) {
        stack<int> tmpStk;
		
		while(!stk.empty()) {
		    tmpStk.push(stk.top());
			stk.pop();
		}
		
		while(!tmpStk.empty()) {
		    int tmpStkTop = tmpStk.top();
			tmpStk.pop();
		    if (stk.empty() || tmpStkTop > stk.top()) {
			    stk.push(tmpStkTop);
				continue;
			} 
			
			while(!stk.empty() && tmpStkTop < stk.top()) {
			    int stkTop = stk.top();
				stk.pop();
				tmpStk.push(stkTop);
			}
			
			stk.push(tmpStkTop);
		}
    }
};