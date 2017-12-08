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
/*InsetAfter*/
NODE* append(NODE * head,int data){

	NODE* cursor = head;
	while(cursor-> next != NULL){
		cursor = cursor->next;
	}

	NODE* node = create(data,NULL);
	cursor->next = node;
	return head;
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
int main(){
	
	NODE* start = NULL;
	start = prepend(start,5);
	start = prepend(start,6);
	append(start,13);
	append(start,10);
	printInfo(start);
	return 0;
}
