#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    LinkedListNode<int> *curr = head, *prev = NULL, *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head || !head->next)
        return true;
    LinkedListNode<int> *slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);

    LinkedListNode<int> *a = head, *b = slow->next;
    while(a != slow->next && b != NULL){
        if(a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return true;
}
