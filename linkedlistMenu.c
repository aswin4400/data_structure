/*This is Menu Driven Program written in C, to demonstrate the Singly Linked List Operations........
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
int item;
struct node* next;
};
typedef struct node NODE;
NODE* insertBeg(NODE*);
NODE* insertEnd(NODE*);
NODE* insertPos(NODE*,int);
NODE* deleteBeg(NODE*);
NODE* deleteEnd(NODE*);
NODE* deletePos(NODE*,int);
void search(NODE*,int);
void display(NODE*);
void main(){
NODE* head = NULL;
do{
printf("\nEnter :: (1-Insert at End, 2-Insert at Beginning, 3-Insert at any Position\n4-Delete at the Beginning,5-Delete at the End,6-Delete at any Position, 7 - DISPLAY, 8 - SEARCH) : ");
int op,n;
scanf("\n%d",&op);
switch(op){
case 1:
head = insertEnd(head);
break;
case 2:
head = insertBeg(head);
break;
case 3:
printf("Enter Position of Element to be inserted : "); scanf("%d",&n);
head = insertPos(head,n);
break;
case 4:
head = deleteBeg(head);
break;
case 5:
head = deleteEnd(head);
break;
case 6:
printf("Enter the postition of the element to be deleted : ");scanf("%d",&n);
head = deletePos(head,n);
break;
case 7:
display(head);
break;
case 8:
printf("Enter item to be searched : "); scanf("%d",&n);
search(head,n);
break;
default :
printf("\n\nThank you.... Come back again !!!\n\n");
exit(0);
}

}while(1);

}
NODE* insertEnd(NODE* head){
int item;
printf("Enter the item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(head == NULL)
head = newnode;
else{
NODE* current = head;
while(current->next!= NULL)
current = current->next;
current->next = newnode;
}
return head;
}
NODE* insertBeg(NODE* head){
int item;
printf("Enter the item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(head == NULL)
head = newnode;
else{
newnode->next = head;
head = newnode;
}
return head;
}
NODE* insertPos(NODE* head, int n){
int item;
printf("Enter item : ");scanf("%d",&item);
NODE* newnode = (NODE*)malloc(sizeof(NODE));
newnode->item = item;
newnode->next = NULL;
if(head == NULL){
head=newnode;
return head;
}
int i = 0;
NODE* current = head,*prev = head;
while((i<n-1) && (current!= NULL)){
prev = current;
current = current->next;
i++;
}
if(current == head){
newnode->next = head; head = newnode;}
else{
newnode->next = current;
prev->next = newnode;}
return head;
}

NODE* deleteEnd(NODE* head){
NODE* current,*pre =head;
if(head == NULL){printf("There is no node to Delete !!\n\n"); return head;}
else{
current = head;
while(current->next!=NULL){
pre = current;
current = current->next;
}
free(current);
if(current == head)
head = NULL;
else
pre->next = NULL;
}
return head;
}

NODE* deleteBeg(NODE* head){
if(head == NULL){
printf("There is no nod to delete!!!!\n\n");
return head;
}
else{
NODE* current = head;
head = (current)->next;
free(current);
}
return head;
}

NODE* deletePos(NODE* head, int n){
if(head == NULL){
printf("There is no node to delete !!!!\n\n");
return head;
}
NODE* current = head;NODE* pre = head;
int i = 2;
while((i<=n) && (current->next != NULL)){
pre = current;
current = current->next;
i++;
}
if(i==2){
head=(current)->next;
free(current);
}
else{
pre->next = current->next;
free(current);
}
return head;
}
void search(NODE* head, int n){
NODE* current = head;
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
