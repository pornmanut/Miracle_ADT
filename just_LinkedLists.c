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

/*InsertAfter*/
NODE* insertAfter(NODE *head,int data,NODE* prev){
	
	if(head == NULL || prev == NULL) return NULL;

	NODE* cursor = head;
	while(cursor != prev){
		cursor = cursor->next;
	}
	if(cursor = NULL) return NULL;	

	NODE* node = create(data,prev->next);
	prev->next = node;
	
	return node;
}

/*PrintInfo*/
void printInfo(NODE* head){
	
	NODE* cursor = head;
	int count = 0;
	while(cursor != NULL){
		printf("%2.d: %3.d ",count+1,cursor->data);
		if((count+1)%2 == 0)printf("\n");
		count++;
		cursor = cursor->next;
	}
	printf("Count: %d\n",count);
}
/*Main*/
int main(){
	
	NODE* start = NULL;
	start = prepend(start,5);
	start = prepend(start,6);
	append(start,15);
	append(start,10);
	
	insertAfter(start,20, search(start,5) );
	
	printInfo(start);
	return 0;
}
