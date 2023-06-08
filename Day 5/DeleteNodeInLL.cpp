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

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    LinkedListNode<int> *curr = node, *next = node->next, *prev = NULL;
    
    while(next){
        swap(curr->data, next->data);
        prev = curr;
        curr = curr->next;
        next = next->next;
    }

    prev->next = NULL;
    delete curr;

}
