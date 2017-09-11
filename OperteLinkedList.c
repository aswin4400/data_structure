#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} NODE;

void menuBuilder(int *opt);
void optionRunner(int opt,NODE **head);
void readOptInputs(int opt,int *Data,int *Location);
void insertNode(NODE **head,int Data,int Location);
void insertPosition(NODE **head,NODE *newNode,int Location);
int traverseList(NODE **currentNode,NODE **previousNode,int Location);
void deleteNode(NODE **head,int Location);
void deletePosition(NODE **head,int Location);
void searchList(NODE *currentNode,int Data);
void displayList(NODE *currentNode);

void main() {
  int opt;
  NODE *head=NULL;
  do {
    menuBuilder(&opt);
    optionRunner(opt,&head);
  } while(opt!=9);
}

void menuBuilder(int *opt) {
  printf("\n\t\tMenu\n");
  printf("\t1.Insert On First\n");
  printf("\t2.Insert On Positon\n");
  printf("\t3.Insert On Last\n");
  printf("\t4.Delete On First\n");
  printf("\t5.Delete On Positon\n");
  printf("\t6.Delete On Last\n");
  printf("\t7.Search For Value\n");
  printf("\t8.Display\n");
  printf("\t9.Exit\n");
  printf("\n\tEnter Option : ");
  scanf("%d",opt);
}

void optionRunner(int opt,NODE **head) {
  int Data=0,Location=0;
  readOptInputs(opt,&Data,&Location);

  switch (opt) {
    case 1:insertNode(head,Data,1);break;
    case 2:insertNode(head,Data,Location);break;
    case 3:insertNode(head,Data,-1);break;

    case 4:deleteNode(head,1);break;
    case 5:deleteNode(head,Location);break;
    case 6:deleteNode(head,0);break;

    case 7:searchList(*head,Data);break;
    case 8:displayList(*head);break;
    case 9:exit(0);break;

    default:printf("\nInvalued Option\n");break;
  }
}

void readOptInputs(int opt,int *Data,int *Location) {
  if (opt>=1&&opt<=3||opt==7){
    if (opt>=1&&opt<=3)
      printf("\nEnter Data To Insert: ");
    else
      printf("\nEnter Data To Search: ");
    scanf("%d",Data);
  }
  if(opt==2||opt==5){
    printf("\nEnter Location: ");
    scanf("%d",Location);
  }
}

void insertNode(NODE **head,int Data,int Location) {
  NODE *newNode;

  newNode=(NODE *)malloc(sizeof(NODE));
  newNode->next=NULL;
  newNode->data=Data;

  if (*head==NULL) {
    if (Location==1||Location==-1) {
      *head=newNode;
    }else{
      free(newNode);
      printf("\nE:Invalued Location\n");
    }
  }else{
    insertPosition(head,newNode,Location);
  }
}

void insertPosition(NODE **head,NODE *newNode,int Location) {
  NODE *currentNode=*head,*previousNode=NULL;
  int count=traverseList(&currentNode,&previousNode,Location);
  if(!(Location<count+1)){
    printf("E:Invalued Location\n");
  }else if(Location==1){
    newNode->next=*head;
    *head=newNode;
  }else{
    newNode->next=currentNode;
    previousNode->next=newNode;
  }
}

int traverseList(NODE **currentNode,NODE **previousNode,int Location) {
  int count=1;
  while ((count<Location)||
        (Location==0&&(*currentNode)->next!=NULL)||
      (Location==-1&&(*currentNode)!=NULL)) {
          *previousNode=*currentNode;
          *currentNode=(*currentNode)->next;
          count++;
  }
  return count;
}

void deleteNode(NODE **head,int Location) {
  if (*head==NULL) {
      printf("\nE:Nothing To Delete\n");
  }else{
    deletePosition(head,Location);
  }
}

void deletePosition(NODE **head,int Location) {
  NODE *currentNode=*head,*previousNode=NULL;
  int count=traverseList(&currentNode,&previousNode,Location);
  if(!(Location<=count)){
    printf("E:Invalued Location\n");
  }else if(Location==1){
    *head=currentNode->next;
    free(currentNode);
  }else{
    if (previousNode==NULL)
      *head=currentNode->next;
    else
      previousNode->next=currentNode->next;
    free(currentNode);
  }
}

void searchList(NODE *currentNode,int Data) {
  int count=0,found=0;
  while (currentNode!=NULL) {
    count++;
    if (currentNode->data==Data) {
      found=1;
      printf("Data Found At:%d\n",count);
      break;
    }
    currentNode=currentNode->next;
  }
  if(!found)
    printf((!found&&currentNode==NULL)?
      "E:Nothing To Search":"Data Not Found\n");
}

void displayList(NODE *currentNode) {
  if(currentNode==NULL){
    printf("E:Nothing To Display\n");
    return;
  }
  printf("\n\t------ Displaying -------\n");
  while (currentNode!=NULL) {
    printf("\t\t %d \n",currentNode->data);
    currentNode=currentNode->next;
  }
  printf("\n\t-------------------------\n");
}
