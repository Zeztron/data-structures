#include <stdio.h>

void merge(int A[], int low, int mid, int high) {
  
  int i = low, j = mid + 1, k = low;
  int B[100];

  while(i <= mid && j <= high) {
    if (A[i] < A[j]) {
      B[k++] = A[i++];
    } else {
      B[k++] = A[j++];
    }
  }

  for(; i <= mid; i++) {
    B[k++] = A[i];
  }

  for(; j <= high; j++) {
    B[k++] = A[j];
  }

  for(int i = low; i <= high; i++) {
    A[i] = B[i];
  }


};

void recursiveMergeSort(int A[], int low, int high) {

  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    recursiveMergeSort(A, low, mid);
    recursiveMergeSort(A, mid+1, high);
    merge(A, low, mid, high);
  }
}

void iterativeMergeSort(int A[], int n) {

  int p, low, high, mid, i;

  for(p = 2; p <= n; p = p * 2) {

    for(i = 0; i+p-1 < n; i = i+p) {
      low = i;
      high = i + p - 1;
      mid = (low + high) / 2;
      merge(A, low, mid, high);
    }


  }


}


int main() {


  return 0;
}