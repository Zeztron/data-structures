#include <stdio.h>

struct Array {
  int A;
  int size;
  int length;
};

// Displays the array
void Display(struct Array arr) {
  int i;
  printf("Elements are\n");
  for(i=0; i<arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
}

// Adds an element in the array
void Append(struct Array *arr, int x) {
  if (arr->length<arr->size) {
    arr->A[arr->length++] = x;
  }
}

// Inserts element in a specific index
void Insert(struct Array *arr, int index, int x) {
  
  int i;
  if (index>=0 && arr->length) {
    for(i=arr->length, i>index; i--) {
      arr->A[i] = arr->A[i-1];
    }

    arr->A[index] = x;
    arr->length++
  }
}

int main() {
  struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

  Append(&arr, 10);
  Insert(&arr, 5, 10);
  Display(arr);
  return 0;
}