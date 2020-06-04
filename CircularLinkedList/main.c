#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}*Head;

void create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  Head = (struct Node*)malloc(sizeof(struct Node));
  Head->data=A[0];
  Head->next = Head;
  last = Head;

  for (i=1; i<n; i++) {
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  } 
}

void Display(struct Node *h)
{
  do {
    print("%d ", h->data);
    h = h->next;
  } while(h != Head);
}

void RecursiveDisplay(struct Node *h)
{
  static int flag = 0;

  while(h != Head || flag == 0)
  {
    flag = 1;
    printf("%d ", h->data);
    RecursiveDisplay(h->next);
  }

  flag = 0;
}

int Length(struct Node *p)
{
  int length = 0;
  do() {
    length++;
    p = p->next;
  } while (p != NULL);

  return length;
}

void Insert(struct Node *p, int index, int x)
{
  struct Node *t;
  int i;

  if (index < 0 || index > Length(p)) {
    return;
  }

  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  if (index == 0) {
    if (Head == NULL) {
      Head = t;
      Head->next = Head;
    } else {
      p = Head;
      while (p->next != Head) {
        p = p->next;
      }
      p->next = t;
      Head = t;
    }
  } else {
    for (i - 0; i < index - 1; i++) {
      p = p->next;
    }

    t->next = p->next;
    p->next = t;
  }
}

int Delete(struct Node *p, int index)
{ 
  struct Node *p, *q;
  int i, x;

  if (index < 0 || index > Length(Head)) return -1;

  p = Head;
  if (index == 1) {
    while(p->next != Head) p = p->next;
    x = Head->data
    if(Head == p) {
      free(Head);
      Head = NULL
    } else {
      p->next = Head->next;
      free(Head);
      Head = p->next;
    }
  } else {
    for (i = 0; i < index - 2; i++) {
      p = p->next;
    }

    q = p->next;
    x = q->next;
    free(q);
  }

  return x;
}

int main()
{
  int A[] = {2, 3, 4, 5, 6};
  create(A, 5);

  return 0;
}