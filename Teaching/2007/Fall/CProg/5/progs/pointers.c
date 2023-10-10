#include <stdio.h>

int main( void) { /* pointers.c */
  int i= 5, *pti= &i, j= 7, *ptj;
  char c= 'a', *ptc = &c;

  ptj= &j;
  pti= ptj;

  printf( "i=%d, pti=%p, *pti=%d\n", i, pti,  *pti); 
  printf( "j=%d, ptj=%p, *ptj=%d\n", j, ptj,  *ptj);  
  printf( "c=%c, ptc=%p, *ptc=%c\n", c, ptc,  *ptc);   
  return 0;
}
