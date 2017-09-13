
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE *head,*current,*newnode;

void main(){
  int n,i;
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
    printf("\nEnter Data: ");
    scanf("%d",&current->data);
  }

  current=head;

  printf("\nDisplaying\n");
  for (i = 0; i < n; i++) {
    printf(" %d\n",current->data);
    current=current->next;
  }
}
