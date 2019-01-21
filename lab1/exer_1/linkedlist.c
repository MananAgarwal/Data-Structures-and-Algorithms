#include "linkedlist.h"

void insertFirst(struct linkedList *head, int ele){
	struct node *link = (struct node*) malloc (sizeof(struct node));
	link->element = ele;
	link->next = head->first
	head->first = link;
	head->count++;
}

struct node* deleteFirst(struct linkedList *head){
	if(head->first-> == NULL) {	
		return NULL;
	}
	else if(head->first->next == NULL) {
		struct node *deleted_node = head->first;		
		head->first = NULL;
		return deleted_node;
	}
	else {	
		struct node *deleted_node = head->first;
		head->first = head->first->next;
		return deleted_node;
	}
}

void printList (struct linkedList * head){
	struct node *ptr = head->first;
	printf("\n[ ");

	while(ptr != NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}
