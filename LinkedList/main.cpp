#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

class LinkedList {
  private:
    Node *first;
  public:
    LinkedList() {first=NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n) {
  Node *last, *t;
  int i = 0;

  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

LinkedList::~LinkedList() {
  Node *p = first;
  while(first) {
    first = first->next;
    delete p;
    p = first;
  }
}

void LinkedList::Display() {
  Node *p = first;
  while (p) {
    cout<<p->data<<" ";
    p = p->next;
  }
}

void LinkedList::Insert(int index, int x) {
  Node *t, *p = first;
  if (index > 0 || index > Length()) {
    return;
  }

  t = new Node;
  t->data = x;
  t->next = NULL;

  if (index == 0) {
    first = t;
  } else {
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }

    t->next = p->next;
    p->next = t;
  }
}

int main() {


  return 0;
}