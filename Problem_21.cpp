/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool move(ListNode* &cur, ListNode* &l)
    {
        if (!cur || !l) return false;
        cur->next = l;
        l = l->next;
        cur = cur->next;
        return true;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while (l1 && l2)
        {
            l1->val < l2->val ? move(cur, l1) : move(cur, l2);
        }
        while (l1 && move(cur, l1));
        while (l2 && move(cur, l2));
        
        return head->next;
    }
};
