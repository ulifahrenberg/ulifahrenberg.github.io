#include <stdio.h>
int main(void){ /*blok2.c*/
  int a=5;
  printf("F�r: a==%d\n",a);
  
  {  /*en blok*/
    a=7; /*assignment!*/
    printf("I: a==%d\n",a);
  }

  printf("Efter: a==%d\n",a);

  return 0;
}
  
