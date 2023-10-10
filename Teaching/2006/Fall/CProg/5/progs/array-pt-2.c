#include <stdio.h>

/* array-pt-2.c */
int main( void) { 
  int a[ 5]= {1, 2, 3, 4, 5};
  int *pta, i;

  pta= a; /* or, pta= &a[0]; */
  *pta= 4;
  pta++;
  *pta= *( pta- 1)* 2;
  pta+= 3;
  (*pta)++;
  printf( "index: %d\n", pta-a);

  for( i= 0; i< 5; i++)
   printf("a[%d]: %d\n",i,a[i]);

  return 0;
}
