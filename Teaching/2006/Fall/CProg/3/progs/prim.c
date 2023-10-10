#include <stdio.h>

int indlaes( void);
int prim( int tal);
int nextPrime( int tal);

int main( void) {  /* prim.c */
  int tal;

  tal= indlaes();  /* et funktionskald */
  if( prim( tal))  /* et funktionskald */
    printf( "PRIMA\n");
  else {
    tal= nextPrime( tal);  /* endnu et */
    printf( "Next prime is %d\n", tal);
  }

  return 0;
}

/* en funktionsdefinition */
int indlaes( void) {
  int tal;

  printf( "\nEnter a number: ");
  scanf( "%d", &tal);

  return tal;
}

int prim( int tal) {
  int isprime= 1;
  int i;

  for( i= 2; i<= tal- 1; i++) {
    if( tal% i== 0) {
      isprime= 0;
      break;
    }
  }

  return isprime;
}

int nextPrime( int tal) {
  tal++;
  while( !prim( tal)) tal++;

  return tal;
}
