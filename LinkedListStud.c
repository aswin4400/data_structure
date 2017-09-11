#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int RollNo;
  char Name[20];
  int Mark[5];
  struct node *next;
} NODE;

NODE *head,*current,*newnode;

void main(){
  int n,i,j;
  printf("Enter number of data: ");
  scanf("%d",&n);
  head=NULL;
  for (i = 0; i < n; i++) {
    newnode=(NODE *)malloc(sizeof(NODE));
    if(head==NULL){
      head=newnode;
    }else{
      current->next=newnode;
    }
    current=newnode;

    printf("\nEnter RollNo: ");
    scanf("%d",&current->RollNo);
    printf("\nEnter Name: ");
    scanf("%s",current->Name);
    printf("\nEnter Mark: ");
    for (j = 0; j < 5; j++)
      scanf("%d",&current->Mark[j]);
  }

  current=head;

  printf("\nDisplaying\n");
  for (i = 0; i < n; i++) {
    printf("\n------------------\n");
    printf("\nRollNo: %d",current->RollNo);
    printf("\nName: %s",current->Name);
    printf("\nMark: ");
    for (j = 0; j < 5; j++)
      printf(" %d ",current->Mark[j]);
    printf("\n------------------\n");
    current=current->next;
  }
}
