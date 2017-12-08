#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int data;
	struct node* next;

}NODE;

NODE* create(int data,NODE* next){
	
	NODE* node = (NODE*)malloc(sizeof(NODE));
	
	node->data = data;
	node->next = next;
	
	return node;
}

NODE* prepend(NODE* head,int data){
	
	NODE* node = create(data,head);
	head = node;
	return head;

}

void printInfo(NODE* head){
	
	NODE* cursor = head;
	int count = 0;
	while(cursor != NULL){
		printf("%d: %d \n",count+1,cursor->data);
		count++;
		cursor = cursor->next;
	}
	printf("Count: %d\n",count);
}
int main(){
	
	NODE* start = NULL;
	start = prepend(start,5);
	start = prepend(start,6);
	printInfo(start);
	return 0;
}
