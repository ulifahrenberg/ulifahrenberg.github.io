# include <stdio.h>

int main( void) {  /* lighed2.c */
  int a, b;
  char lig;

  printf( "Vi sammenligner to tal.\n\n\
Må jeg bede om to heltal?\n");
  scanf( "%d %d", &a, &b);

  (a== b) &&( lig= ' ');
  (a!= b) &&( lig= 'u');

  printf( "%d er %clig %d\n", a, lig, b);
  return 0;
}
