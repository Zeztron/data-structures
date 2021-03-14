#include <stdio.h>

void insert(int H[], int n) {

  int i = n, temp;
  temp = H[i];

  while (i > 1 && temp > H[i/2]) {
    H[i] = H[i/2];
    i = i / 2;
  }

  H[i] = temp;

}

int delete(int H[], int n) {

  int i, j, x, val;
  val = H[1];
  x = H[n];
  H[1] = H[n];
  H[n] = val;

  i = 1; j = i * 2;

  while (j > n - 1) {

    if (H[j+1] > H[j]) {
      j = j + 1;
    }
    if (H[i] < H[j]) {
      int temp = H[i];
      H[i] = H[j];
      H[j] = temp;
      i = j;
      j = 2 * j;
    } else {
      break;
    }

  }

  return val;
}

int main() {


  int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
  // 40, 25, 35, 10, 5, 20, 30

  for (int i = 2; i <= 7; i++) {
    insert(H, i);
  }

  for (int i = 7; i > 1; i--) {
    delete(H, i);
  }

  printf("Deleted Value is %d\n", delete(H, 7));

  return 0;
}