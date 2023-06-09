/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head || !head->next)
		return head;
	
	Node *first = head;
	Node *second = flattenLinkedList(head->next);
	first->next = NULL;
	second->next = NULL;
	Node *ans = new Node(0);
	Node *temp = ans;
	while(first && second){
		if(first->data <= second->data){
			temp->child = first;
			first = first->child;
		}else{
			temp->child = second;
			second = second->child;
		}
		temp = temp->child;
	}

	if(first)
		temp->child = first;
	if(second)
		temp->child = second;
	return ans->child;
}	
