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

void Insert(struct Node *p, int index, int x)
{
  struct Node *t;
  int i;
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

int main()
{
  int A[] = {2, 3, 4, 5, 6};
  create(A, 5);

  return 0;
}