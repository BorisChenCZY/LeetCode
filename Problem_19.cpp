ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last = head;
        ListNode* prev = head;
        ListNode* ans = head;
        
        while(n--)
        {
            last = last->next; //error may happen
        }
        
        while(last != nullptr && last->next)
        {
            prev = prev->next;
            last = last->next;
        }
        
        if(last == nullptr)
        {
            ans = head->next;
            // delete head;
        }
        else
        {
            ans = prev->next;
            prev->next = prev->next->next;
            // delete ans;
            ans = head;
        }
        
        return ans;
        
    }