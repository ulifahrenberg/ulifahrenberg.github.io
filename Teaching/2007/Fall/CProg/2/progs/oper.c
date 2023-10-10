# include <stdio.h>

int main( void) {  /* oper.c */
  printf( "%d\n", 1==1 || 3==5 && 1==2);
  printf( "%d\n", ( 1==1 || 3==5 ) && 1==2);
  return 0;
}
