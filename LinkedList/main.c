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

int Max(struct Node *p) 
{
  int max = INT_MIN;
  while (p != NULL) {
    if (p->data > max) {
      max = p->data;
    }

    p = p->next;
  }

  return max;
}

int RecursiveMax(struct Node *p) 
{
  int max = 0;

  if (p == 0) {
    return INT_MIN;
  }

  max = RecursiveMax(p->next);
  return max > p->data ? max : p->data;  
}

struct Node* Search(struct Node *p, int key)
{
  while(p != NULL) {
    if (key == p->data) {
      return p;
    }

    p = p->next;
  }

  return NULL;
}

struct Node* ImprovedSearch(struct Node* p, int key) // bring key to the front
{
  struct Node *q = NULL;
  while (p != NULL) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
    }

    q = p;
    p = p->next;
  }
}

struct Node* RecursiveSearch(struct Node *p, int key)
{
  if (p == NULL) {
    return NULL;
  } 

  if (key == p->data) {
    return p;
  }

  return RecursiveSearch(p->next, key);
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