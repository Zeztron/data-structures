#include <stdio.h>

struct Array {
  int A[10];
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
  if (index>=0 && index<=arr->length) {
    for(i=arr->length; i>index; i--) {
      arr->A[i] = arr->A[i-1];
    }

    arr->A[index] = x;
    arr->length++;
  }
}

int BinarySearch(struct Array arr, int key) {
  int low = 0;
  int high = arr.length-1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if(key == arr.A[mid]) {
      return mid;
    } else if (key < arr.A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  return -1;
}

int RecursiveBinarySearch(int arr[], int low, int high, int key) {

  if (low <= high) {

  int mid = (low + high) / 2;
    if (key == arr[mid]) {
      return mid;
    } else if (key < arr[mid]) {
      return RecursiveBinarySearch(arr, low, mid-1, key);
    } else {
      return RecursiveBinarySearch(arr, mid + 1, high, key);
    }
  }

  return -1;
}

int Delete(struct Array *arr, int index) {
  int x=0;
  int i;
  if (index>=0 && index<=arr->length-1) {
    x=arr->A[index];
    for (i=index; i<arr->length-1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return x;
  }

  return 0;
}

int main() {
  struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

  Append(&arr, 10);
  Insert(&arr, 5, 10);
  Delete(&arr, 4);
  Display(arr);
  return 0;
}
