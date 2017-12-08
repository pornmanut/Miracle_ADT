#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int data;
	struct node* next;

}NODE;

/*NewNode*/
NODE* create(int data,NODE* next){
	
	NODE* node = (NODE*)malloc(sizeof(NODE));
	
	node->data = data;
	node->next = next;
	
	return node;
}

/*InserFirst*/
NODE* prepend(NODE* head,int data){
	
	NODE* node = create(data,head);
	head = node;
	return head;

}
/*InsetLast*/
NODE* append(NODE * head,int data){

	NODE* cursor = head;
	while(cursor-> next != NULL){
		cursor = cursor->next;
	}

	NODE* node = create(data,NULL);
	cursor->next = node;
	return head;
}
/*SerachInfo*/
NODE* search(NODE *head,int data){
	
	NODE* cursor = head;
	while(cursor != NULL){
		if(cursor->data == data)return cursor;	
		cursor = cursor->next;
	}
}
/*InsertBefore*/
NODE* insertBefore(NODE* head,int data,NODE* nxt){
	if(head == NULL || nxt == NULL) return NULL;

	if(head == nxt)
	{
		head = prepend(head,data);
		return head;
	}

	NODE* cursor = head;
	while(cursor != NULL){
		if(cursor->next == nxt) break;
		cursor = cursor->next;
	}
	
	if(cursor == NULL) return NULL;
	
	NODE* node = create(data,cursor->next);
	cursor->next = node;
	
	return node;
	
}
/*InsertAfter*/
NODE* insertAfter(NODE *head,int data,NODE* prev){
	
	if(head == NULL || prev == NULL) return NULL;

	NODE* cursor = head;
	while(cursor != prev){
		cursor = cursor->next;
	}
	if(cursor == NULL) return NULL;	

	NODE* node = create(data,prev->next);
	prev->next = node;
	
	return node;

}
/*FreeNode*/

void freeNode(NODE* node){
	free(node);
}

/*DeleteFirst*/
NODE* removeFront(NODE* head){
	if(head == NULL)return NULL;

	NODE* front = head;
	head = head->next;

	front->next = NULL;

	freeNode(front);
	return head;

}

/*DeleteAfter*/
NODE* removeLast(NODE* head){
	if(head == NULL)return NULL;

	NODE* cursor = head;
	NODE* back = NULL;

	while(cursor-> next != NULL){
		back = cursor;
		cursor = cursor->next;
	}
	if(back != NULL)back->next = NULL;
	if(cursor == head) head = NULL;

	freeNode(cursor);

	return head;
}
/*PrintInfo*/
void printInfo(NODE* head){
	
	NODE* cursor = head;
	int count = 0;
	while(cursor != NULL){
		printf("%2.d: %3.d ",count+1,cursor->data);
		if((count+1)%5 == 0)printf("\n");
		count++;
		cursor = cursor->next;
	}
	printf("Count: %d\n\n",count);
}
/*Main*/
int main(){
	
	NODE* start = NULL;
	start = prepend(start,5);
	start = prepend(start,6);
	append(start,15);
	append(start,10);
	
	insertAfter(start,20, search(start,5) );
	insertBefore(start,100, search(start,20));	
	printInfo(start);

	start = removeFront(start);
	printInfo(start);
	start = removeLast(start);
	start = removeLast(start);
	printInfo(start);
	return 0;
}
