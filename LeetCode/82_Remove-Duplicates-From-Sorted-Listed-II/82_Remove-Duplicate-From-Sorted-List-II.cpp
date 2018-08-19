struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {

    ListNode dummyNode(0); //pos is the place that
    ListNode* prePos = &dummyNode;
    prePos->next=head;
    ListNode* node=head;

    while(node && node->next) {
        if (node->val==node->next->val) {
            while(node && node->next && (node->val==node->next->val))
                 node->next=node->next->next;
            prePos->next=node->next;
            node=node->next;
        }
        else{
            prePos=node;
            node=node->next;
        }
    }

    return dummyNode.next;
}