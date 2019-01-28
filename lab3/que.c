#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "que.h"

struct queue newQ(){
	struct queue qq;
	qq.count = 0;
	qq.last = NULL;
	qq.first = NULL;
	return qq;
}	

void displayQ(struct queue qq){
	printf("\ncount %d", qq.count);
	if(qq.first != NULL){
		struct node *ptr = qq.first;
		while(ptr != NULL){
			printf("\n%d",ptr->element);
			ptr = ptr->next;
		}
	}
	else{
		printf("\nQueue is empty");
	}	
}

bool isEmptyQ(struct queue qq){
	if(qq.first == NULL){
		printf("\nQueue is empty");
		return true;
	}
	else{
		printf("\nQueue is not empty");
		return false;
	}
	//return (qq.first == NULL)?true:false;
}

struct queue addQ(struct queue qq, int e){
	
	struct node *link = (struct node*) malloc (sizeof(struct node));
	link->element = e;
	link->next = NULL;

	if(qq.first == NULL){
		qq.first = link;
		qq.last = link;
	}
	else{
		qq.last->next = link;
		qq.last = link;
	}	
	
	qq.count++;
	return qq;
}

struct queue delQ(struct queue qq){
	if(qq.first != NULL){
		qq.first = qq.first->next;
	}
	else{
		printf("\nQueue is empty");
	}
	return qq;
}

void main(){
	struct queue que = newQ();
	bool isEmpty = isEmptyQ(que);
	que = addQ(que, 5);
	que = addQ(que, 10);
	que = addQ(que, 15);
	isEmpty = isEmptyQ(que);
	displayQ(que);
	que = delQ(que);
	que = delQ(que);
	displayQ(que);
	que = delQ(que);
	displayQ(que);
}

