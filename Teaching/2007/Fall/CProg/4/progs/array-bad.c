#include <stdio.h>

int main( void) { /* array-bad.c */
  int a[ 3];

  /* Menigsl�st resultat */
  printf( "%d\n", a[ 3]);

  /* FARLIGT! */
  /*  a[ 3]= 17; */

  return 0;
}
