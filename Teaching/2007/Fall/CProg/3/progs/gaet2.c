#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void) {  /* gaet.c */
  int hemtal;
  int gaet= 0;
  int forsoeg;

  printf( "\nWe generate a random number between 1 and 1000\n\
and let you guess it, at each step telling you\n\
the relation between your guess and our number.\n");

  /* initialise random number generator */
  srand(( unsigned int) time( 0));
  /* generate random number between 1 and 1000 */
  hemtal= rand()% 1000+ 1;

  for( forsoeg= 1; gaet!= hemtal; forsoeg++) {
    printf( "\nEnter your guess: ");
    scanf( "%d", &gaet);

    if( gaet!= hemtal)
      printf( "Your guess is too %s.\n", gaet< hemtal? "small": "big");
    else
      printf( "\nSuccess!\nYou needed %d tries.\n", forsoeg);
  }

  return 0;
}
