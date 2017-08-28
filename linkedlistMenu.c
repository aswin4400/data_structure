/*This is Menu Driven Program written in C, to demonstrate the Singly Linked List Operations........
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
int item;
struct node* next;
};
typedef struct node NODE;
void insertBeg(NODE**);
void insertEnd(NODE**);
void insertPos(NODE**,int);
void deleteBeg(NODE**);
void deleteEnd(NODE**);
void deletePos(NODE**,int);
void search(NODE**,int);
void display(NODE*);
void main(){
NODE* head = NULL;
do{
printf("\nEnter :: (1-Insert at End, 2-Insert at Beginning, 3-Insert at any Position\n4-Delete at the Beginning,5-Delete at the End,6-Delete at any Position, 7 - DISPLAY, 8 - SEARCH) : ");
int op,n;
scanf("\n%d",&op);
switch(op){
case 1: 
insertEnd(&head);
break;
case 2:
insertBeg(&head);
break;
case 3:
printf("Enter Position of Element to be inserted : "); scanf("%d",&n);
insertPos(&head,n);
break;
case 4:
deleteBeg(&head);
break;
case 5:
deleteEnd(&head);
break;
case 6:
printf("Enter the postition of the element to be deleted : ");scanf("%d",&n);
deletePos(&head,n);
break;
case 7:
display(head);
break;
case 8:
printf("Enter item to be searched : "); scanf("%d",&n);
search(&head,n);
break;
default :
exit(0);
}

}while(1);

}
void insertEnd(NODE** head){
int item;
printf("Enter the item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(*head == NULL)
*head = newnode;
else{
NODE* current = *head;
while(current->next!= NULL)
current = current->next;
current->next = newnode;
}
}
void insertBeg(NODE** head){
int item;
printf("Enter the item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(*head == NULL)
*head = newnode;
else{
newnode->next = *head;
*head = newnode;
}
}
void insertPos(NODE** head, int n){
int item;
printf("Enter item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(*head == NULL){
*head=newnode;
return;
}
int i = 2;NODE* current = *head;
while((i<=n) && (current->next != NULL)){
current = current->next;
i++;
}
if(i==2){
newnode->next = *head; *head = newnode;}
else{
newnode->next = current->next;
current->next = newnode;}
}

void deleteEnd(NODE** head){
NODE* current,*pre =*head;int i=0;
if(*head == NULL){printf("There is no node to Delete !!\n\n"); return;}
else{
current = *head;
while(current->next!=NULL){
pre = current;
current = current->next;
i++;
}
free(current);
if(i==0)
*head = NULL;
else
pre->next = NULL;
}
}

void deleteBeg(NODE** head){
if(*head == NULL){
printf("There is no nod to delete!!!!\n\n");
return;
}
else{
NODE* current = *head;
*head = (current)->next;
free(current);
}
}

void deletePos(NODE** head, int n){
if(*head == NULL){
printf("There is no node to delete !!!!\n\n");
return;
}
NODE* current = *head;NODE* pre = *head;
int i = 2;
while((i<=n) && (current->next != NULL)){
pre = current;
current = current->next;
i++;
}
if(i==2){
*head=(current)->next;
free(current);
}
else{
pre->next = current->next;
free(current);
}
}
void search(NODE** head, int n){
NODE* current = *head;
int i = 1;
while(current!=NULL){
if(current->item == n){printf("%d is Found at node %d !!!\n\n",n,i); break;}
current= current->next;
i++;
}
if(current == NULL){printf("%d is not in the list \n\n",n);} 
}
void display(NODE* head){

NODE* current = head;
while(current!=NULL){
printf("%d -> ",current->item);
current = current->next;
}
printf("NULL\n\n");
}
