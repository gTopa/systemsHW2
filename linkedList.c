#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

int print_list(struct node *start){
  while(start){
    if(start->next){
      printf("%d, ", start->i);
    }
    else{
      printf("%d\n", start->i);
    }
    start=start->next;
  }
  return 0;
}

struct node * insert_front(struct node *new, struct node *start){
  new->next=start;
  start=new;
  return start;
}


struct node * free_list(struct node *start){
  struct node *temp;
  temp=start;
  while(start){
    temp=start;
    free(start);
    start=temp->next;
  }
  return start;
}

int main(){
  struct node *t1;
  t1=(struct node *)malloc(sizeof(struct node));
  t1->i=1;
  t1->next=(struct node *)malloc(sizeof(struct node));
  t1->next->i=2;
  t1->next->next=NULL;
  print_list(t1);
  struct node *t2;
  t2=(struct node *)malloc(sizeof(struct node));
  t2->i=0;
  t1=insert_front(t2, t1);
  print_list(t1);
  t1=free_list(t1);
  print_list(t1);

  return 0;
}
