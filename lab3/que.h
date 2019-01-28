#include <stdio.h>

struct node {
	int element;
	struct node *next;
};

struct queue {
	int count;
	struct node *first;
	struct node *last;
};

struct queue newQ();

bool isEmptyQ(struct queue);

struct queue addQ(struct queue, int);

struct queue delQ(struct queue);
