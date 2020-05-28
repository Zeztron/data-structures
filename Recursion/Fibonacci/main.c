#include <stdio.h>

// Time complexity = 0(2n) - very slow
// Excessive Recursion
int fib(int n) {
  if (n <= 1) {
    return n;
  }

  return fib(n-2) + fib(n-1);
}

// Can we make it better?
// Holding the values in an array to prevent excessive calls
// Memoization - O(n)

int F[10];
int memoizedFib(int n) {
  if (n <=1 ) {
    F[n] = n;
    return n;
  } else {
    if (F[n-2] == -1) {
        F[n-2] = memoizedFib(n-2);
    }
    if (F[n-1] == -1) {
      F[n-1] = memoizedFib(n-1);
    }
  }

  return F[n-2] + F[n-1];
}

int main() {
  int i;
  for(i = 0; i < 10; i++) {
    F[i] = -1;
  }

  printf("%d \n", memoizedFib(5));
  return 0;
}

