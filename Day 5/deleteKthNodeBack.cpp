Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int cnt = 0;
    Node* curr = head;
    while(curr){
        cnt++;
        curr = curr->next;
    }

    cnt = cnt - K;
    curr = head;
    Node *prev = NULL;
    while(cnt){
        cnt--;
        prev = curr;
        curr = curr->next;
    }

    if(prev){
        prev->next = curr->next;
        delete curr;
        return head;
    }
    return head->next;
}
