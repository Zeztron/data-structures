#include <stdio.h>


void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int A[], int n) {

  int i, j, k;

  for (i = 0; i < n - 1; i++) {

    for (j = k = i; j < n; j++) {
      if (A[j] < A[k]) {
        k = j;
      }
    }
    swap(A[i], A[k]);


  }


}

int main() {


  return 0;
}