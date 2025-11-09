/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reversed(ListNode * head){
        if(head== NULL || head->next== NULL)return head;
        ListNode * newNode = reversed(head->next);
        ListNode * front = head->next;
        front->next = head;
        head->next = NULL;
        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        if(head== NULL || head->next== NULL)return head;
        ListNode * slow= head ;
        ListNode * fast= head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newNode = reversed(slow);
        ListNode * first = head;
        ListNode * second = newNode;
        while(second !=NULL){
            if(first->val != second->val){
                return false;
            }
            first= first->next;
            second = second->next;

        }
        reversed(newNode);
        return true;
    }
};