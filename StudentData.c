#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct {
  int RollNo;
  char Name[20];
  int Mark[5];
} Student;

Student *stdData[MAX],*NewStd;

void addStudent();
void display();

int i,j,opt,n=0;
void main(){
  do {
    printf("\n\t\tMenu\n");
    printf("\t1. Add Student\n");
    printf("\t2. Display\n");
    printf("\t3. Exit\n");
    printf("Enter Option: ");
    scanf("%d",&opt);
      switch (opt) {
        case 1:
          addStudent();
        break;
        case 2:
          display();
        break;
        case 3:
          exit(0);
        break;
        default:
          printf("Invalued Option\n");
        break;
    }
  } while(opt!=3);
}

void addStudent(){
  if(n<MAX){
    NewStd=(Student *)malloc(sizeof(Student));
    printf("\n\tAdd Student\n");
    printf("\nEnter RollNo:\t");
    scanf("%d",&NewStd->RollNo);
    printf("\nEnter Name:\t");
    scanf("%s",NewStd->Name);
    printf("\nEnter Mark:\t");
    for (i = 0; i < 5; i++) {
      scanf("%d",&NewStd->Mark[i]);
    }
    stdData[n]=NewStd;
    n+=1;
    printf("%d\n",n );
  }else{
    printf("Array Full");
  }
}
void display(){
  printf("%d\n",n );
  if(n!=0){
    for (j = 0; j < n; j++) {
      NewStd=stdData[j];
      printf("\n-----------------------");
      printf("\nRollNo:%d",NewStd->RollNo);
      printf("\nName:%s",NewStd->Name);
      printf("\nMarks:");
      for (i = 0; i < 5; i++) {
        printf(" %d ",NewStd->Mark[i]);
      }
      printf("\n-----------------------");
    }
  }else{
    printf("Array Empty");
  }
}
