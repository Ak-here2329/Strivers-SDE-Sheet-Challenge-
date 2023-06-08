class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while(head1 && head2){
            if(head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
            }else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1 == NULL)
            temp->next = head2;
        else
            temp->next = head1;

        return ans->next;
    }
};
