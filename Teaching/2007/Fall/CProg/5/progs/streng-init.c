#include <stdio.h>
#include <string.h>

int main( void) { /* streng-init.c */

  char s1[ 8], *s2, s3[ 8];

  /* Ulovlig brug af initializer */
  /*  s1={ 'A', 'a', 'l', 'b', 'o', 'r', 'g', '\0'}; */

  /* Ulovligt assignment til array navn */
  /*  s1= "Aalborg"; */

  /* Alternativ: kopier tegnene selv */
  strcpy(s1, "Aalborg");

  /* Pointer assignment - OK */
  s2= "Aalborg";

  /* Tegnvis assignment - OK */
  s3[ 0]= 'A';  s3[ 1]= 'a';  s3[ 2]= 'l';  
  s3[ 3]= 'b';  s3[ 4]= 'o';  s3[ 5]= 'r';  
  s3[ 6]= 'g';  s3[ 7]= '\0';     

  printf("%s\n%s\n%s\n", s1, s2, s3);
  
  return 0;
}
