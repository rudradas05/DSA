class MyLinkedList {

    ListNode * dummy;
    int size;
public:
    MyLinkedList() {
        dummy = new ListNode(0);
        size=0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode * temp = dummy->next;
        for(int i =0; i< index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);

    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;
        ListNode * prev = dummy;
        for(int i = 0; i< index; i++){
            prev = prev->next;
        }
        ListNode * node =  new ListNode(val);
        node->next = prev->next;
        prev->next = node;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        ListNode* prev = dummy;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        
        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */