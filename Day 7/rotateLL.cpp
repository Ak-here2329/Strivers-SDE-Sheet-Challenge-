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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;

        int sz = 0;
        ListNode *curr = head, *prev = NULL, *last;
        while(curr){
            sz++;
            if(curr->next == NULL)
                last = curr;
            curr = curr->next;
        }
        k = k % sz;
        k = sz - k;
        curr = head;
        last->next = head;

        while(curr && k){
            prev = curr;
            curr = curr->next;
            k--;
        }
        prev->next = NULL;
        return curr;
    }
};
