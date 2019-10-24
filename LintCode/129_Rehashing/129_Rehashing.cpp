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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int capacity = hashTable.size(); 
        int capacity2 = capacity << 1;
        vector<ListNode *> result(capacity2, NULL);
        for (int i = 0; i < capacity; ++i) {
            ListNode * curNode = hashTable[i];
            while(curNode) {
                int val = curNode->val;
                ListNode * newNode = new ListNode(val);
                int newIndex = val < 0 ? (val % capacity2 + capacity2) % capacity2 : val % capacity2;
                if (result[newIndex] == NULL) {
                    result[newIndex] = newNode;
                } else {
                    ListNode * tmp = result[newIndex];
                    while(tmp->next) {
                        tmp = tmp->next;
                    }
                    tmp->next = newNode;
                }
                curNode = curNode->next;
            }
        }
        
        return result;
    }
};
