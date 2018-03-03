#include<stdio.h>

int main(void) {
  printf("Char    : %02ld bytes\n", sizeof(char));
  printf("S Int   : %02ld bytes\n", sizeof(short int));
  printf("Int     : %02ld bytes\n", sizeof(int));
  //printf("S Double: %02ld bytes\n", sizeof(short double));
  printf("Double  : %02ld bytes\n", sizeof(double));
  //printf("S Float : %02ld bytes\n", sizeof(short float));
  printf("Float   : %02ld bytes\n", sizeof(float));
  printf("L Int   : %02ld bytes\n", sizeof(long int));
  printf("L Double: %02ld bytes\n", sizeof(long double));
  //printf("L Float : %02ld bytes\n", sizeof(long float));

  return 0;
}
