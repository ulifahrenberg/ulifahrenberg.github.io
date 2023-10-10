#include <stdio.h>
int main( void) {  /* while.c */
  int h= 0;
  while( h!= 1234) {
    printf("Indtast det hemmelige heltal: ");
    scanf( "%d", &h);
  }
  printf( "\nHurra!\n");
  return 0;
}

