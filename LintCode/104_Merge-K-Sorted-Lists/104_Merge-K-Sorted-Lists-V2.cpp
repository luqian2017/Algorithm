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
 
//bool operator > (const ListNode &a, const ListNode &b) { //最小堆
//    return a.val > b.val;
//}

class cmp {
public:
    bool operator() (ListNode* a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
       
        int listsSize = lists.size();
        if (listsSize == 0) return nullptr;
        
        ListNode dummy(0); 
        ListNode *head = &dummy; 
        
        //priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> pq;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    
        for (auto ptr : lists) {
            if (ptr) {
                pq.push(ptr);
            }
        }
        
        while(!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            head->next = node;
            head = node;
            if (node->next) pq.push(node->next); //. has higher priority than *
        }
            
        return dummy.next;   
    }
};