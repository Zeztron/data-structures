#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node *next;
}*first;

void create(int A[], int n) 
{
  int i;
  struct Node *t, *last;

  first = (struct Node*)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
  }
}

void Display(struct Node *p) 
{
  while (p != NULL) {
    printf("%d", p->data);
    p = p->next;
  }
}

int CountNodes(struct Node *p) 
{
  int count = 0;
  while (p != NULL) {
    count++;
    p = p->next;
  }

  return count;
}

int RecursiveCount(struct Node *p) 
{
  if (p == 0) {
    return 0;
  } else {
    return RecursiveCount(p->next) + 1;
  }
}

int Sum(struct Node *p)
{
  int sum = 0;
  while (p != NULL) {
    sum += p->data;
    p = p->next;
  }

  return sum;
}

int RecursiveSum(struct Node *p) 
{
  if (p == 0) {
    return 0;
  } else {
    return RecursiveSum(p->next) + p->data;
  }
}

int main() 
{
  int A[] = {3, 5, 7, 10, 15};
  create(A, 5);

  Display(first);
  CountNodes(first);
  sum(first);

  return 0;
}