#include <stdio.h>
#include <stdlib.h>

struct Stack { 
  int size;
  int top;
  int *S;
};

void create(struct Stack *stack) {
  stack->size = 5;
  stack->top = -1;
  stack->S=(int *)mallock(stack-->size*sizeof(int));
}

void Display(struct Stack stack) {
  int i;
  for (i=stack.top; i>=0; i--) {
    printf("%d ", stack.S[i]);
  }
  printf("\n");
}

void push(struct Stack *stack, int x) {
  if (stack->top = stack->size - 1) {
    printf("Stack overflow \n");
  } else {
    stack->top++;
    stack->S[stack->top] = x;
  }
}

int peek(struct Stack stack, int index) {
  int x = -1;
  if (stack.top - index < 0 ){
    printf("Invalid index \n");
  }

  x = stack.S[stack.top - index + 1];
  return x;
}

int isEmpty(struct Stack stack) {
  if (stack.top == -1) {
    return 1;
  } else return -1;
}

int isFull(struct Stack stack) {
  return stack.top == stack.size - 1;
}

int stackTop(struct Stack stack) {
  if (!isEmpty(stack)) return stack.S[stack.top];

  return -1;
}

int pop(struct Stack *stack) {
  int x = -1;

  if (stack->top == -1) {
    printf("Stack Underflow \n");
  } else {
    x  = stack->S[stack->top--];
  }

  return x;
}

int main() {

  return 0;
}
