#include <stdio.h>

int main( void) {  /* seconds.c */
  long int input, temp, h, m, s;
  printf( "Giv mig et heltal!\n");
  scanf( "%ld", &input);
  h= input/ 3600;
  temp= input- h* 3600;
  m= temp/ 60;
  s= temp% 60;
  printf( "\n%ld sekunder svarer til \
%ld timer, %ld minutter og %ld sekunder\n",
	  input, h, m, s);
  return 0;
}

  
