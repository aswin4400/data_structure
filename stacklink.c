
#include<stdio.h>
#include<stdlib.h>
struct node{
int item;
struct node* next;
};
typedef struct node NODE;
NODE* pop(NODE*);
NODE* push(NODE*);
void  peek(NODE*);
void display(NODE*);
void main(){
NODE* top = NULL;
do{
printf("Enter(1- PUSH, 2-POP, 3-PEEK, 4-DISPLAY)\n\n\n");
int op,n;
scanf("\n%d",&op);
switch(op){
case 1: 
top = push(top);
break;
case 2:
top = pop(top);
break;
case 3:
peek(top);
break;
case 4:
display(top);
break;
default :
exit(0);
}

}while(1);

}
NODE* pop(NODE* top){
	NODE* temp;
	if(top == NULL)
		printf("Empty Stack\n");
	else{
		temp = top;
		printf("Popped value = %d \n",top->item);
		top = top->next;
		free(temp);
	}
return top;
}

NODE* push(NODE* top){
int item;
printf("Enter the item \n\n");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = top;
top = newnode;
return top;
}
void peek(NODE* top){
	if(top == NULL)
		printf("NULL\n");
	else
		printf("TOP = %d\n",top->item);
}
void display(NODE* top){

NODE* current = top;
while(current!=NULL){
printf("\n%d\n--",current->item);
current = current->next;
}
printf("\nNULL\n\n");
}

