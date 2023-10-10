#include <stdio.h>

int main( void) {  /* switch.c */
  int a;
  char * dyr;
  printf( "Giv mig et heltal!\n");
  scanf( "%d", &a);

  switch( a) {
  case 1: dyr= "hest"; break;
  case 2: dyr= "gris"; break;
  case 3: dyr= "brilleabe"; break;
  default: dyr= "ko"; break;
  }

  printf( "\n\nDu er en %s!\n", dyr);
  return 0;
}
