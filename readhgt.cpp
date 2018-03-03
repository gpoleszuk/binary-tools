#include<stdio.h>
#include<stdlib.h>

short int swap(short int value) {
  return (value << 8 | value >> 8);
}

int main(int argc, char* argv[]) {
  FILE *fp;
  FILE *ft;
  short int hgt;
  short int row, col;
  int point;

  //printf("%0X\n", swap(0x3412));
/**/

  if (argc == 3) {
    if (((fp = fopen(argv[1], "rb")) && (ft = fopen(argv[2], "w+"))) == NULL) {
      printf("The file %s cannot be open!\n", argv[1]);
    } else {
      printf("The file %s is opened for reading!\n", argv[1]);
      printf("Reading 2 bytes...\n");
      point = 0;
      for(int row = 0; row < 1201; row++) {
        for(int col = 0; col < 1201; col++) {
          point++;
          fread(&hgt, sizeof(short int), 1, fp);
          fprintf(ft, "%+6d ", swap(hgt));
          //printf("[%08d] [%04d][%04d]: %02d m\n", point, row, col, swap(hgt));
        }
        fprintf(ft, "\n", hgt);
      }
      printf("Closing...\n");
      fclose(fp);
      fclose(ft);
    }
  } else {
    printf("Insuficient arguments.\n");
  }
/**/
  //printf("%02d = %02Xh\n", atoi(argv[1]), atoi(argv[1]));
  //printf("%d %d\n", 1201 * 1201 * 2 ,0x2c04c2);
  return 0;
}
