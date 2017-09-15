#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int Queue[MAX];
int front=0,rear=-1;
int opt,i,val;

void Insert(int);
int Delete();
void Display();
int isEmpty();
int isFull();

void main(){
  do {
    printf("\n\t\tMenu\n");
    printf("\t1.Insert\n");
    printf("\t2.Delete\n");
    printf("\t3.Display\n");
    printf("\t4.Exit\n");

    printf("\n\nF:%d R:%d\n\n",front,rear);
    printf("\nEnter Option: ");
    scanf("%d",&opt);
    switch (opt) {
      case 1:
        if (isFull()) {
          printf("Queue Is Full\n");
        }else{
          printf("\nEnter Data: ");
          scanf("%d",&val);
          Insert(val);
        }
      break;
      case 2:
        if (isEmpty()) {
          printf("Queue Is Empty\n");
        }else{
          val=Delete();
          printf("\nData: %d",val);
        }
      break;
      case 3:
        Display();
      break;
      case 4:
        exit(0);
      break;
      default:
        printf("Invalued Option\n");
      break;
    }
  } while(opt!=4);
}

void Insert(int Data){
  rear+=1;
  Queue[rear]=Data;
}

int Delete(){
  Queue[front]=0;
  front+=1;
  return Queue[front-1];
}

void Display() {
  for(i=front;i<=rear;i++){
    printf(" %d\n",Queue[i]);
  }
}

int isEmpty(){
  return front>rear;
}

int isFull(){
  return (rear==MAX-1);
}
