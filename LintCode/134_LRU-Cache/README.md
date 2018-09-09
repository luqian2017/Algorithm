Data strcture is based on doubly linked list and hash map.
Do remember to add the key field in Node class, as it will need the field when deleting element (when capacity reach the threshold):

mp.erase(head->next->key);

