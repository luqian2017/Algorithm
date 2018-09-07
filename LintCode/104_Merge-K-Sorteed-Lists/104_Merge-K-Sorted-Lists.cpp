/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int listsSize = lists.size();
        
        if (listsSize == 0) return nullptr;
        
        ListNode dummy(ListNode(0));
        ListNode *result = &dummy;
        ListNode *head = result;
        
        vector<ListNode *> listPtrs(listsSize);
        set <int> s;
        
        for (int i = 0; i < listsSize; ++i) {
            s.insert(i);
            listPtrs[i] = lists[i];
        }
        
        while (!s.empty()) {
            
            int index = *(s.begin());
            int minVal = INT_MAX;
            if (listPtrs[index]) minVal = listPtrs[index]->val;
            for (auto i : s) {
                if (listPtrs[i]) {
                    if (listPtrs[i]->val <= minVal) {
                        index = i;
                        minVal = listPtrs[i]->val;
                    }
                } else {
                  s.erase(i);
                }
            }
            
            result->next = listPtrs[index];
            result = result->next; 
            if (listPtrs[index]) listPtrs[index] = listPtrs[index]->next;
         }
        
        return head->next;
    }
};