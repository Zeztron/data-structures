#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int A[], int n) {

  int i, j, flag=0;

  for (i = 0; i < n - 1; i++) {
    flag = 0;
    for (j = 0; j < n - 1 - i; j++) {
      if (A[i] > A[j]) {
        swap(&A[i], &A[j]);
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

int main() {
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;


  return 0;
}