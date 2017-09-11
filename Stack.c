#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX];
int TOP=-1;

void push(int);
int pop();
int peek();
void displaystack();
int isEmpty();
int isFull();

void main() {
    int opt=0,val;
    do {
      printf("\n\t\tMenu\n");
      printf("\t1.Push\n");
      printf("\t2.Pop\n");
      printf("\t3.Peek\n");
      printf("\t4.DisplayStack\n");
      printf("\t5.Quit\n");
      printf("\n\tEnter the option:");
      scanf("%d",&opt);

    if (isFull()&&opt==1) {
      printf("Stack Is Full");
    }else if(isEmpty()&&(opt>=2&&opt<=4)){
      printf("Stack Is Empty");
    }else{
      switch (opt) {
          case 1:
            printf("\n\tEnter the value:");
            scanf("%d",&val);
            push(val);
          break;
          case 2:
            val=pop();
            printf("Poped Value: %d",val);
          break;
          case 3:
            val=peek();
            printf("Peek Value: %d",val);
          break;
          case 4:
            displaystack();
          break;
          case 5:
            exit(0);
            printf("Come back soon");
          break;
          default:
            printf("Invalued Option");
          break;
        }
      }
  } while(opt!=5);
}

void push(int item) {
  TOP++;
  stack[TOP]=item;
}

int pop(){
 int Temp= stack[TOP];
 stack[TOP]=0;
 TOP--;
 return Temp;
}

int peek(){
  return stack[TOP];
}

void displaystack(){
  printf("\n\nDisplaying Stack\n");
  int i;
  for (i = 0; i <= TOP; i++) {
    printf("  %d  \n", stack[i]);
  }
}

int isEmpty(){
  return TOP==-1;
}

int isFull(){
  return TOP==(MAX-1);
}
