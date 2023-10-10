#include <stdio.h>

int main( void) { /* variable-noinit.c */
  int a, b, c;
  c= a/ b;
  printf( "%d divideret med %d giver %d\n",
	  a, b, c);
  printf( "Hov, hvad er nu det?\n");
  return 0;
}
