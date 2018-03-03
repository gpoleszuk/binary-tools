#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
  if (argc == 2)
    printf("%02d = %02Xh\n", atoi(argv[1]), atoi(argv[1]));
  //printf("%d %d\n", 1201 * 1201 * 2 ,0x2c04c2);
  return 0;
}
