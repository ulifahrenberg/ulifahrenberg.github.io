#include <stdio.h>
#include <limits.h>
#include <float.h>

/* typer.c
   print information on the different C types */

int main( void) { 
  printf( "char: %d bits, values from %d to %d\n",
	  sizeof( char), CHAR_MIN, CHAR_MAX);
  printf( "unsigned char: %d bits, values from %d to %d\n\n",
	  sizeof( unsigned char), 0, UCHAR_MAX);
  printf( "short: %d bits, values from %d to %d\n",
	  sizeof( short), SHRT_MIN, SHRT_MAX);
  printf( "unsigned short: %d bits, values from %d to %d\n\n",
	  sizeof( unsigned short), 0, USHRT_MAX);
  printf( "int: %d bits, values from %d to %d\n",
	  sizeof( int), INT_MIN, INT_MAX);
  printf( "unsigned int: %d bits, values from %d to %u\n\n",
	  sizeof( unsigned int), 0, UINT_MAX);
  printf( "long: %d bits, values from %li to %li\n",
	  sizeof( long), LONG_MIN, LONG_MAX);
  printf( "unsigned long: %d bits, values from %d to %lu\n\n",
	  sizeof( unsigned long), 0, ULONG_MAX);

  printf( "float:\n\
  %d bits\n\
  values from -%e to -%e and from %e to %e\n\
  with %d digits precision\n\n",
	  sizeof( float), FLT_MAX, FLT_MIN, FLT_MIN, FLT_MAX, FLT_DIG);
  printf( "double:\n\
  %d bits\n\
  values from -%e to -%e and from %e to %e\n\
  with %d digits precision\n\n",
	  sizeof( double), DBL_MAX, DBL_MIN, DBL_MIN, DBL_MAX, DBL_DIG);
  printf( "long double:\n\
  %d bits\n\
  values from -%Le to -%Le and from %Le to %Le\n\
  with %d digits precision\n",
	  sizeof( long double), LDBL_MAX, LDBL_MIN, LDBL_MIN, LDBL_MAX, LDBL_DIG);

  return 0;
}
