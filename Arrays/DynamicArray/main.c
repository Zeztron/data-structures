#include <stdio.h>
#include <stdlib.h>


int main() {
  int *p, *q;
  int i;
  p=(int *)malloc(5*sizeof(int));
  p[0]=3; p[1]=5; p[2]=7; p[3]=9; p[4]=11;

  // Create helper pointer thats double the size of original array
  q=(int *)malloc(10*sizeof(int));

  // Copy values over
  for (i=0; i<5; i++) {
    q[i] = p[i];
  }
  
  // Free up original array as it is not needed
  free(p);

  // p is now pointing to what q is pointing to
  p=q;

  // helper pointer (q) is not needed anymore
  q=NULL;

  return 0;

}
