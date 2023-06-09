#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head)
        return NULL;
    int cnt = 0;
    unordered_map<LinkedListNode<int>*, int> nodeCnt;
    unordered_map<int, LinkedListNode<int>*> cntNode;

    LinkedListNode<int> *curr = head;

    while(curr){
        cnt++;
        nodeCnt[curr] = cnt;
        cntNode[cnt] = curr->random;
        curr = curr->next;
    }

    curr = head;
    LinkedListNode<int> *newHead = NULL, *nprev = NULL;
    while(curr){
        LinkedListNode<int> *temp = new LinkedListNode<int>(curr->data);
        if(!newHead){
            newHead = temp;
        }else{
            nprev->next = temp;
        }
        temp->random = cntNode[nodeCnt[curr]];
        nprev = temp;
        curr = curr->next;
    }
    return newHead;
}
