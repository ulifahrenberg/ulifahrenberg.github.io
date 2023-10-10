#include <stdio.h>
#define GREGORIAN 1583

int main( void) {  /* dag.c */
  int d, m, y;  /* day, month, year */
  int legal= 1;  /* whether entered date is legal */

  printf( "\nEnter a day, a month and a year.\n\
We compute the next day of the year.\n\
We do not accept years before %d.\n\nDay: ", GREGORIAN);
  scanf( "%d", &d);
  printf( "Month: ");
  scanf( "%d", &m);
  printf( "Year: ");
  scanf( "%d", &y);

  if( d< 1|| m< 1|| m> 12|| y< GREGORIAN)
    legal= 0;
  else {  /* month and year are legal, day>= 1 */
    if( m== 1|| m==3|| m==5|| m== 7|| m== 8|| m== 10|| m== 12) {
      /* 31 days in these months */
      if( d> 31)
	legal= 0;
      else {  /* day is legal */
	if( d< 31)
	  d++;
	else {  /* last day of the month */
	  d= 1;
	  if( m< 12)
	    m++;
	  else {  /* last month of the year */
	    m= 1;
	    y++;
	  }
	}
      }
    }  /* end months with 31 days */
    else if( m== 4|| m== 6|| m== 9|| m== 11) {
      /* 30 days in these months */
      if( d> 30)
	legal= 0;
      else {  /* day is legal */
	if( d< 30)
	  d++;
	else {  /* last day of the month */
	  d= 1;
	  if( m< 12)
	    m++;
	  else {  /* last month of the year */
	    m= 1;
	    y++;
	  }
	}
      }
    }  /* end months with 30 days */
    else {  /* month== 2 has 28 or 29 days */
      if( y% 4== 0&&( y% 100!= 0|| y% 400== 0)) {
	/* leap year! */
	if( d> 29)
	  legal= 0;
	else {  /* day is legal */
	  if( d< 29)
	    d++;
	  else {  /* last day of the month */
	    d= 1;
	    m++;
	  }
	}
      }
      else {  /* no leap year */
	if( d> 28)
	  legal= 0;
	else {  /* day is legal */
	  if( d< 28)
	    d++;
	  else {  /* last day of the month */
	    d= 1;
	    m++;
	  }
	}
      }
    }  /* end month== 2 */
  }  /* end computations */

  if( legal)
    printf( "\nNext date is: %d. %d. %d\n", d, m, y);
  else
    printf( "This is an illegal date\n");
  return 0;
}
