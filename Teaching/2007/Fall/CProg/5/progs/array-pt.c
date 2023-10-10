#include <stdio.h>

int main( void) { /* array-pt.c */
  int a[ 3], i;

  *a= 4;
  *( a+ 1)= 5;
  *( a+ 2)= *a+ *( a+1);

  for( i= 0; i< 3; i++)  printf( "%d: %d\n", i, a[i]);

  return 0;
}
