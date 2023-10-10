#include <stdio.h>
#define GREGORIAN 1583

int main( void) {  /* dag2.c */
  int d, m, y;  /* day, month, year */
  int dmin= 1, mmin= 1, ymin= GREGORIAN;  /* minimal values */
  int dmax= 31;  /* maximal day value, depends on month! 
		    give default because of compiler warning */
  int mmax= 12;  /* maximal month value */
  int legal= 1;  /* whether entered date is legal */

  printf( "\nEnter a day, a month and a year.\n\
We compute the next day of the year.\n\
We do not accept years before %d.\n\nDay: ", GREGORIAN);
  scanf( "%d", &d);
  printf( "Month: ");
  scanf( "%d", &m);
  printf( "Year: ");
  scanf( "%d", &y);

  /* Is input legal? (Check for day<= dmax only later) */
  legal=(( y>= ymin)&&( m>= mmin)&&( d>= dmin)&&( m<= mmax));

  /* How many days are there in the given month? */
  switch( m) {
  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    dmax= 31; break;
  case 4: case 6: case 9: case 11:
    dmax= 30; break;
  case 2:
    if( y% 4== 0&&( y% 100!= 0|| y% 400== 0)) /* leap year! */
      dmax= 29;
    else
      dmax= 28;
    break;
  }

  /* Is day legal? */
  legal=( d<= dmax);
  
  /* Compute */
  if( legal) {
    if( d< dmax)
      d++;
    else {
      d= 1;
      if( m< mmax)
	m++;
      else {
	m= 1;
	y++;
      }
    }
  }

  /* Output */
  if( legal)
    printf( "\nNext date is: %d. %d. %d\n", d, m, y);
  else
    printf( "This is an illegal date\n");
  return 0;
}
