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

struct node * insert_front(struct node *n, int i){
  struct node *new=(struct node *)malloc(sizeof(struct node));
  new->i=i;
  new->next=n;
  return new;
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
  struct node *t3;
  t3=(struct node *)malloc(sizeof(struct node));
  t3->i=2;
  t3->next=NULL;
  t1->next=t3;
  print_list(t1);
  t1=insert_front(t1, 1);
  print_list(t1);
  t1=free_list(t1);
  print_list(t1);

  return 0;
}
