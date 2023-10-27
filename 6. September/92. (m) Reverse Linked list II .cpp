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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || left == right)
            return head;
        
        ListNode* temp = head;
        ListNode* l = NULL;
        ListNode* r = NULL; 
        ListNode* s = NULL;
        ListNode* e = NULL;
        
        ListNode* tc = NULL; 
        ListNode* tp = NULL;
        ListNode* tn = NULL;
        
        int pos = 1;
        
        while(temp){
            if(left == 1){
                s = NULL;
                l = head;
            }
            if(pos == left-1){
                s = temp;
                l = temp->next;   
            }
            if(pos == right){
                r = temp;
                e = temp->next;
            }   
            
            pos++;
            temp = temp->next;
        }
        
            //outside of loop
            tp= l;
            tc = tp->next;
            tn = tp->next->next;
        
        while(tp != r){
            tc->next = tp;
            
            tp = tc;
            tc = tn;
            
            if(tn)
            tn = tn->next;
        }
        
        if(s)
        s->next = tp;
        else
        head = r;
        
        l->next = tc;
        
        return head;
    }
};