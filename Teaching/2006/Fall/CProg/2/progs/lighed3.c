# include <stdio.h>

int main( void) {  /* lighed2.c */
  int a, b;
  char lig;

  printf( "Vi sammenligner to tal.\n\n\
Må jeg bede om to heltal?\n");
  scanf( "%d %d", &a, &b);

  if( a== b) lig= ' ';
  else lig= 'u';

  printf( "%d er %clig %d\n", a, lig, b);
  return 0;
}
