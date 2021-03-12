#include <stdio.h>

struct Node {
  struct Node *lChild;
  int data;
  int height;
  struct Node *rChild;
}*root=NULL;

int nodeHeight(struct Node *p) {
  int leftHeight, rightHeight;

  leftHeight = p && p->lChild ? p->lChild->height : 0;
  rightHeight = p && p->rChild ? p->rChild->height : 0;

  return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int balanceFactor(struct Node *p) {
  int leftHeight, rightHeight;

  leftHeight = p && p->lChild ? p->lChild->height : 0;
  rightHeight = p && p->rChild ? p->rChild->height : 0;

  return leftHeight - rightHeight;
}

struct Node *LLRotation(struct Node *p) {
  struct Node *pl = p->lChild;
  struct Node *plr = pl->rChild;

  pl->rChild = p;
  p->lChild = plr;

  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if (root == p) {
    root = pl;
  }

  return pl;
}

struct Node *LRRotation(struct Node *p) {
  struct Node *pl = p->lChild;
  struct Node *plr = pl->rChild;

  pl->rChild = plr->lChild;
  p->lChild = plr->rChild;

  plr->lChild = pl;
  plr->rChild = p;

  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);
  plr->height = nodeHeight(plr);

  if (root == p) {
    root = plr;
  }

  return plr;
 
}

struct Node *recursiveInsert(struct Node *p, int key) {

  struct Node *t=NULL;

  if (p == NULL) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->height = 1;
    t->lChild = t->rChild = NULL;
    return t;
  }
  if (key < p->data) {
    p->lChild = recursiveInsert(p, key);
  } else if (key > p->data) {
    p->rChild = recursiveInsert(p, key);
  }

  p->height = nodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->lChild) == 1) {
    return LLRotation(p);
  } else if (balanceFactor(p) == 2 && balanceFactor(p->lChild) == -1) {
    return LRRotation(p);
  } else if (balanceFactor(p) == -2 && balanceFactor(p->rChild) == -1) {
    return RRRotation(p);
  } else if (balanceFactor(p) == -2 && balanceFactor(p->rChild) == 1) {
    return RLRotation(p);
  }


  return p;

}


int main() {

  root = recursiveInsert(root, 10);
  recursiveInsert(root, 5);
  recursiveInsert(root, 2);




  return 0;
}