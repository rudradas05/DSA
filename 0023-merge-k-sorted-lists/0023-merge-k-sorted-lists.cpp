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
    ListNode * mergeTwoLists(ListNode * list1, ListNode * list2){
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        if(list1->val<=list2->val){
            list1->next= mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode * bisection(vector<ListNode *>& lists, int i , int j){
        if(i> j)return NULL;
        if(i==j)return lists[i];
        if(j==i+1)return mergeTwoLists(lists[i], lists[j]);
        else{
            int mid = (i+j)/2;
            ListNode * a = bisection(lists, i, mid);
            ListNode * b = bisection(lists, mid+1, j);
            return mergeTwoLists(a,b);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        ListNode * res = lists[0];
        if(lists.size()==1)return lists[0];
        res = bisection(lists, 0, lists.size()-1);
        return res;
    }
};