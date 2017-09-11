#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} NODE;

void menuBuilder(int *opt);
void optionRunner(int opt,NODE **head);
void pushStack(NODE **head,int Data);
int popStack(NODE **head);
int peekStack(NODE **head);
void displayStack(NODE *currentNode);

void main() {
  int opt;
  NODE *head=NULL;
  do {
    menuBuilder(&opt);
    optionRunner(opt,&head);
  } while(opt!=5);
}

void menuBuilder(int *opt) {
  printf("\n\t\tMenu\n");
  printf("\t1.Push\n");
  printf("\t2.Pop\n");
  printf("\t3.Peek\n");
  printf("\t4.Display\n");
  printf("\t5.Exit\n");
  printf("\n\tEnter Option : ");
  scanf("%d",opt);
}

void optionRunner(int opt,NODE **head) {
  int Data=0;
  if(opt==1){
    printf("\nEnter Data To Insert: ");
    scanf("%d",&Data);
  }

  switch (opt) {
    case 1:pushStack(head,Data);break;
    case 2:printf("\nPoped Data %d \n",popStack(head));break;
    case 3:printf("\nPeek Data %d \n",peekStack(head));break;
    case 4:displayStack(*head);break;
    case 5:exit(0);break;

    default:printf("\nInvalued Option\n");break;
  }
}

void pushStack(NODE **head,int Data) {
  NODE *newNode;
  newNode=(NODE *)malloc(sizeof(NODE));
  newNode->next=NULL;
  newNode->data=Data;

  if (*head==NULL) {
    *head=newNode;
  }else{
    newNode->next=*head;
    *head=newNode;
  }
}

int peekStack(NODE **head) {
  if (*head==NULL) {
      printf("\nE:Nothing To Peek\n");
      return -1;
  }else{
    return (*head)->data;
  }
}

int popStack(NODE **head) {
  NODE *currentNode=*head;
  int popData=-1;
  if (*head==NULL) {
      printf("\nE:Nothing To Delete\n");
  }else{
    popData=currentNode->data;
    *head=currentNode->next;
    free(currentNode);
  }
  return popData;
}

void displayStack(NODE *currentNode) {
  printf("\n\t------ Displaying -------\n");
  while (currentNode!=NULL) {
    printf("\t\t %d \n",currentNode->data);
    currentNode=currentNode->next;
  }
  printf("\n\t-------------------------\n");
}
