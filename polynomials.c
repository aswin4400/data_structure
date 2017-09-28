#include<stdio.h>
#include<stdlib.h>
struct poly{
  int coef;
  int expo;
  struct poly* next;
};
typedef struct poly POLY;
POLY* insertPoly(int,int,POLY*);
POLY* addPoly(POLY*,POLY*);
POLY* createPoly(POLY*,int);
void display(POLY*);
int  main(){
POLY* p1 = NULL;
POLY* p2 = NULL;
POLY* p3 = NULL;
p1 = createPoly(p1,1);
printf("\n");
p2 = createPoly(p2,2);
display(p1); printf(" + ");display(p2); printf(" = ");
p3 = addPoly(p1,p2);
display(p3);
return 0;
}

POLY* insertPoly(int coef,int expo,POLY* p){
  POLY* newnode = (POLY*)malloc(sizeof(POLY));
  newnode->coef = coef;
  newnode->expo = expo;
  newnode->next = NULL;
  if(p==NULL){
    p=newnode;
    return p;
  }
  else{
    POLY* current = p;
    while(current->next != NULL)
      current = current->next;
      current->next = newnode;
  }
  return p;
}
POLY* addPoly(POLY* p1,POLY* p2){
  POLY* p3 =  NULL;
  while(p1!=NULL && p2!=NULL){
    if((p1->expo)>(p2->expo)){
      p3 = insertPoly(p1->coef,p1->expo,p3);
      p1 = p1->next;
    }
    else if ((p1->expo)<(p2->expo)){
      p3 = insertPoly(p2->coef,p2->expo,p3);
      p2 = p2->next;
    }
    else{
      p3 = insertPoly(((p2->coef)+(p1->coef)),p2->expo,p3);
      p2 = p2->next;
      p1 = p1->next;
    }}
    while(p1!=NULL){
      p3 = insertPoly(p1->coef,p1->expo,p3);
      p1 = p1->next;
    }
    while(p2!=NULL){
      p3 = insertPoly(p2->coef,p2->expo,p3);
      p2 = p2->next;
    }
return p3;
}
void display(POLY* p){
  POLY* current = p;
  printf("( ");
  while(current != NULL){
    printf("%dX^%d ",current->coef,current->expo);
    if(current->next != NULL)
    printf(" + ");
    else
    printf(" ) ");
    current = current->next;
  }
}
POLY* createPoly(POLY* p,int n){
  int coef,expo;
  printf("Polynomial : %d\n\n",n);
  while(1){
  printf("Coefficent : ");scanf("%d",&coef);
  if(coef == 0)
  return p;
  printf("Exponent :"); scanf("%d",&expo);
  p = insertPoly(coef,expo,p);
  }
  return p;
}
