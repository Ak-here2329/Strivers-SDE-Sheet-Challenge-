#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverse(Node *head){
	Node *curr = head, *prev = NULL, *next;
	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node *solve(Node *head, int i, int b[], int n, int rem){
	if(i >= n || !head)
		return head;
	
	if(b[i] == 0)
		return solve(head, i + 1, b, n, rem);

	if(rem <= b[i])
		return reverse(head);

	int cnt = b[i] - 1;
	
	Node *curr = head;
	while(cnt){
		curr = curr->next;
		cnt--;
	}

	Node *next = solve(curr->next, i + 1, b, n, rem - b[i]);
	curr->next = NULL;
	Node *newHead = reverse(head);
	head->next = next;
	return newHead;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	int cnt = 0;
	Node *curr = head;
	while(curr){
		cnt++;
		curr = curr->next;
	}
	return solve(head, 0, b, n, cnt);
}
