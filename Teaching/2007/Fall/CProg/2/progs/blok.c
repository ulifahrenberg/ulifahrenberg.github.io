#include <stdio.h>
int main(void){ /*blok.c*/
  int a=5;
  printf("Før: a==%d\n",a);
  
  {  /*en blok*/
    int a=7; /*deklaration*/
    printf("I: a==%d\n",a);
  }

  printf("Efter: a==%d\n",a);

  return 0;
}
  
