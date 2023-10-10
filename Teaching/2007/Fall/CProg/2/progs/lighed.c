# include <stdio.h>

int main( void) {  /* lighed.c */
  int a, b, lig;

  printf( "Vi sammenligner to tal.\n\
Output 0 betyder at de er forskellige.\n\n\
Må jeg bede om to heltal?\n");
  scanf( "%d %d", &a, &b);

  lig= a== b;  /* bedre med parenteser... */

  printf( "\nOutput: %d\n", lig);
  return 0;
}
