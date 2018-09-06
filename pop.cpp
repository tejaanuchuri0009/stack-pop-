#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};
struct node* pop(struct node *head){
	struct node *temp=head;
	head=temp->next;
	free(temp);
	return head;
}
void print(struct node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
struct node* newnode(int data){
	struct node *node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->next=NULL;
	return node;
}
struct node* push(struct node *head,int data){
	struct node *stacknode =newnode(data);
	stacknode->next=head;
	head=stacknode;
	return head;
}
int main(){
	struct node *head= NULL;
    int num_node,data;
    cin>>num_node;
    for(int i=0;i<num_node;i++){
    	cin>>data;
    	head=push(head,data);
	}
	cout<<"before pop()"<<endl;
	print(head);
	head=pop(head);
	cout<<endl<<"after pop()"<<endl;
	print(head);
	return 0;
}
