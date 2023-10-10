#include <stdio.h>

int main( void) { /* variable-float.c */
  int a= 5, b= 3;
  double c;
  c= (double)a/ b;
  printf( "%d divideret med %d giver %f\n",
	  a, b, c);
  printf( "Det var bedre!\n");
  return 0;
}
