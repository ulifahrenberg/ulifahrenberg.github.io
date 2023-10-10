#include <stdio.h>

int main( void) { /* scanf-eks.c */
   int     cnt = 0;
   float   sum = 0.0, x;

   printf( "The sum of your numbers will be computed\n\n");
   printf( "Input some numbers (Control-D when finished):\n");
   while( scanf("%f", &x) == 1) {
      cnt = cnt + 1;
      sum = sum + x;
   }
   printf("\n%s%5d\n%s%12f\n\n",
      "Count:", cnt,
      "  Sum:", sum);
   return 0;
}

