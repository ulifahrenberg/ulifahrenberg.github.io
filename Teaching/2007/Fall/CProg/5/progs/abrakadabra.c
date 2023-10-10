#include <stdio.h>

int main( void) { /* abrakadabra.c */
/*  char s[]= "abrakadabra"; */ /* virker */
    char *s= "abrakadabra"; /* virker IKKE */
  char *p;

  printf( "%s\n", s);

  p= s;
  while( *p!= '\0') {
    if( *p== 'a')
      *p= 'i';
    p++;
  }

  printf( "%s\n", s);
  return 0;
}
