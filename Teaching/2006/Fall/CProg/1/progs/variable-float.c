#include <stdio.h>

int main( void) {
  int a= 5, b= 3;
  float c;
  c= (float)a/ b;
  printf( "%d divideret med %d giver %f\n",
	  a, b, c);
  printf( "Det var bedre!\n");
  return 0;
}
