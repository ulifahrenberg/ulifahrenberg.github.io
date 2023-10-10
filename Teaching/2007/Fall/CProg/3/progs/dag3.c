#include <stdio.h>
#define GREGORIAN 1583

/* Function declarations */
int is_input_legal( int d, int m, int y, int dmin, int mmin, int ymin, int mmax);
int days_per_month( int m, int y);
int is_day_legal( int d, int dmax);
void output_result( int d, int m, int y);
void output_error( void);

int main( void) {  /* dag2.c */
  int d, m, y;  /* day, month, year */
  int dmin= 1, mmin= 1, ymin= GREGORIAN;  /* minimal values */
  int dmax= 31;  /* maximal day value, depends on month! 
		    give default because of compiler warning */
  int mmax= 12;  /* maximal month value */

  /* User input */
  printf( "\nEnter a day, a month and a year.\n\
We compute the next day of the year.\n\
We do not accept years before %d.\n\nDay: ", GREGORIAN);
  scanf( "%d", &d);
  printf( "Month: ");
  scanf( "%d", &m);
  printf( "Year: ");
  scanf( "%d", &y);

  if( is_input_legal( d, m, y, dmin, mmin, ymin, mmax)) {
    dmax= days_per_month( m, y);
    if( is_day_legal( d, dmax)) {
      /* Compute */
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
      output_result( d, m, y);
    }
    else
      output_error();
  }
  else
    output_error();
  return 0;
}

int is_input_legal( int d, int m, int y, int dmin, int mmin, int ymin, int mmax) {
  /* Is input legal? (Check for day<= dmax only later) */
  return ( y>= ymin)&&( m>= mmin)&&( d>= dmin)&&( m<= mmax);
}

int days_per_month( int m, int y) {
  /* How many days are there in the given month? */
  int dmax= 30;  /* default to avoid compiler warning */

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
  return dmax;
}

int is_day_legal( int d, int dmax) {
  /* Is day legal? */
  return d<= dmax;
}
  
void output_result( int d, int m, int y) {
  /* Usual output */
  printf( "\nNext date is: %d. %d. %d\n", d, m, y);
}

void output_error( void) {
  /* Error output */
  printf( "This is an illegal date\n");
}
