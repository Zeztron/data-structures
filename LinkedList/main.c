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

void Insert(int pos, int x)
{
  struct Node *t, *p;
  t = (struct Node*)malloc(sizeof(struct Node));
  t->data = x;

  if (pos == 0) {
    t->next = first;
    first = t;
  } else if (pos > 0) {
    p = first;
    for (int i = 0; i < pos - 1 && p; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}
void InsertList(int x)
{
  struct Node *t, *last;
  t = (struct Node*)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;
  if (first == NULL) {
    first = last = t;
  } else {
    last->next = t;
    last = t;
  }
}

void InsertInSortedList(int x)
{
  struct Node *q, *p, *t;
  p = first;
  q = NULL;

  while(p && p->data < x) {
    q = p;
    p = p->next;
  }

  t = (struct Node*)malloc(sizeof(struct Node));
  t->data = x;
  if(p == first) {
    t->next = first;
    first = t;
  } else {
    t->next = q->next;
    q->next = t;
  }
}

int DeleteNode(struct Node *p, int index)
{
  struct Node *q;
  int x = -1, i;

  if (index < 1 || index > count(p)) {
    return -1;
  }

  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  } else {
    for (i = 0; i<index - 1; i++) {
      q = p;
      p = p->next;
    }

    q->next = p->next;
    x=p->data;
    free(p);
    return x;
  }
}

int isSorted(struct Node *p)
{
  int x = INT_MIN;
  while (p != NULL) {
    if(p->data < x) {
      return 0;
    }
    x = p->data;
    p = p->next;
  }

  return 1;
}

struct Node* removeDuplicates(struct Node *p)
{
  p = first;
  struct Node *q = first->next;

  while (q != NULL) {
    if (p->data != q->data) {
      p = q;
      q = q->next;
    } else {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

struct Node* ReverseLinkedList(struct Node *p)
{
  p = first;
  struct Node *q = NULL;
  struct Node *r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }

  first = q;
}

struct Node* RecursiveReverse(struct Node *p, struct Node *q)
{
  if (p != NULL) {
    RecursiveReverse(p, p->next);
    p->next = q;
  } else {
    first = q;
  }
}

struct Node* MergeLists(struct Node *first, struct Node *second)
{
  struct Node *last = NULL, *third = NULL;
  if (first->data < second->data) {
    third = last = first;
    first = first->next;
    last->next = NULL;
  } else {
    third = last = second;
    second = second->next;
    last->next = NULL;
  }

  while (first!= NULL && second != NULL) {
    if (first->data < second->data) {
      last->next = first;
      last = first;
      first = first->next;
    } else {
      last->next = second;
      last = second;
      second = second->next;
    }

    last->next = NULL;
  }

  if (first != NULL) {
    last->next = first;
  } else {
    last->next = second;
  }

  return third;
}

struct Node* concatonateList(struct Node* first, struct Node* second) {
  struct Node *p;
  while(p->next != NULL) {
    p = p->next;
  }

  p->next = second;
  second = NULL;

  return first;
}

int isLoop(struct Node *head)
{
  struct Node *p, *q;
  p = q = head;

  if (!head || !head->next) return -1;
  do {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p!= q);

  if (p == q) { 
    return 1;
  } else {
    return -1;
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