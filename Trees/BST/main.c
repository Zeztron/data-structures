#include <stdio.h>

struct Node {
  struct Node *lChild;
  int data;
  struct Node *rChild;
}*root=NULL;

void insert(int key) {

  struct Node *t = root;
  struct Node *r=NULL, *p; // 'r' - tail pointer, 'p' - pointer for creating a new Node.

  // If root is null, this is the first node.
  if (root == NULL) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lChild = p->rChild = NULL;
    root = p;
    return;
  }

  while (t != NULL) {
    r = t;
    if (key < t->data) {
      t = t->lChild;
    } else if (key > t->data) {
      t = t->rChild;
    } else {
      return;
    }
  }

  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = key;
  p->lChild = p->rChild = NULL;

  if (key < r->data) r->lChild = p;
  else r->rChild = p;
}

struct Node *recursiveInsert(struct Node *p, int key) {

  struct Node *t=NULL;

  if (p == NULL) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = NULL;
    t->lChild = t->rChild = NULL;
    return t;
  }
  if (key < p->data) {
    p->lChild = recursiveInsert(p, key);
  } else if (key > p->data) {
    p->rChild = recursiveInsert(p, key);
  } 

  return p;

}

void inOrder(struct Node *p) {
  if (p) {
    inOrder(p->lChild);
    printf("%d ", p->data);
    inOrder(p->rChild);
  }
}

int search(int key) {
  struct Node *t=root;

  while(t != NULL) {
    if (key == t->data) return 1;

    if (key < t->data) {
      t = t->lChild;
    } else if (key > t->data) {
      t = t->rChild;
    }

  }

  return 0;
}

int height(struct Node *p) {

  int x, y;

  if (p == NULL) return 0;

  x = height(p->lChild);
  y = height(p->rChild);

  return x > y ? x + 1 : y + 1;
}

struct Node *inPre(struct Node *p) {
  while (p && p->rChild != NULL) {
    p = p->rChild;
  }

  return p;
}

struct Node *inSucc(struct Node *p) {
  while (p && p->lChild != NULL) {
    p = p->lChild;
  }

  return p;
}


struct Node *delete(struct Node *p, int key) {

  struct Node *q = NULL;

  if (p == NULL) return NULL;

  if (p->lChild == NULL && p->rChild == NULL) { // It's a leaf node
    if (p == root) {
      root = NULL;
    }

    free(p);
    return NULL;
  }

  if (key < p->data) {
    p->lChild = delete(p->lChild, key);
  } else if (key > p->data) {
    p->rChild = delete(p->rChild, key);
  } else {

    // Remove it with inorder predecessor or successor
    // Check the height and based on the height we will decide to delete from left or right.

    if (height(p->lChild) > height(p->rChild)) { // If left height is greater than right height
      q = inPre(p->lChild); // Find the inorder predecessor
      p->data = q->data;
      p->lChild = delete(p->lChild, q->data); // Delete q's data;
    } else {
      q = inSucc(p->rChild); // Find the inorder successor
      p->data = q->data;
      p->rChild = delete(p->rChild, q->data)
    }

  }
}


int main() {

  root = recursiveInsert(root, 10);
  insert(5);
  insert(20);
  insert(8);
  insert(30);
  
  
  inOrder(root);

  int found = search(8);

  printf("\n");


  return 0;
};