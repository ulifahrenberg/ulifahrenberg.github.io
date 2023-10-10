#include <stdio.h>
#include <string.h>
#define LEN 25

int main( void) { /* streng-eks.c */
  char s[ LEN]= "Aalborg"; /* virker */
  /* char *s= "Aalborg" */ /* virker IKKE */
  /* char s[]= "Aalborg" */ /* virker IKKE */
  char *t= "Universitet";
  int cmp;
  int i;

  cmp= strcmp( s, t); /* sammenlign s og t */
  printf( "%s kommer %s %s\n", s,
	  cmp< 0? "foer":( cmp== 0? "sammen med": "efter"),
	  t);

  strcat( strcat( s, " "), t); /* sammensaet s, " " og t */
  printf( "%s, laengde: %u\n", s, strlen( s));

  strcpy( s, t); /* kopier t ind i s */
  printf( "%s\n", s);

  strncpy( s, t+2, 4); /* kopier substreng(3-6) af t ind i s */
  printf( "%s\n", s); /* virkede ikke; \0 mangler! */

  for( i= 0; i< LEN; i++) /* det her virker: vi fylder */
    s[ i]= '\0';          /* s op med \0 foerst! */
  strncpy( s, t+2, 4); /* kopier substreng(5-8) af t ind i s */
  printf( "%s\n", s);

  return 0;
}

