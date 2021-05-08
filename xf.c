#include<stdio.h>


int main()
{
   unsigned char buf1[1024*1024];
   unsigned char buf2[1024*1024];

   unsigned int sz1, sz2, sz;

   FILE *fp1;
   FILE *fp2;
   FILE *fp3;

   char fname1[]="input1.bin";
   char fname2[]="input2.bin";
   char fname3[]="output1.bin";

   printf("Opening file 1\n");
   fp1 = fopen(fname1, "rb");
   //fp1 = fopen("input1.bin", "rb");
   printf("Pointer file 1 is 0x%X\n", fp1);
   if (fp1)
   {
      printf("File 1 opened\n");
   }
   else
   {
      printf("File 1 not found\n");
      return 1;
   }

   printf("Opening file 2\n");
   fp2 = fopen(fname2, "rb");
   //fp2 = fopen("input2.bin", "rb");
   printf("Pointer file 2 is 0x%X\n", fp2);
   if (fp2)
   {
      printf("File 2 opened\n");
   }
   else
   {
      printf("File 2 not found\n");
     return 1;
   }


   printf("Opening file 3\n");
   fp3 = fopen(fname3, "wb");
   //fp2 = fopen("input2.bin", "rb");
   printf("Pointer file 3 is 0x%X\n", fp3);
   if (fp3)
   {
      printf("File 3 opened\n");
   }
   else
   {
      printf("File 3 not found\n");
     return 1;
   }


   //fgets(buf1, 255, (FILE*)fp1);
   //fgets(buf2, 255, (FILE*)fp2);

   fseek(fp1, 0L, SEEK_END);
   sz1 = ftell(fp1);
   fseek(fp1, 0L, SEEK_SET);
   //rewind(fp1);

   fseek(fp2, 0L, SEEK_END);
   sz2 = ftell(fp2);
   fseek(fp2, 0L, SEEK_SET);
   //rewind(fp2);

   if (sz1 < sz2)
   {
      sz = sz1;
   }
   else
   {
      sz = sz2;
   }

   printf("File 1 size %10d bytes.\n", sz1);
   printf("File 2 size %10d bytes.\n", sz2);
   printf("Minimo size %10d bytes.\n", sz);

   fread(buf1, sizeof(buf1), 1, fp1);
   fread(buf2, sizeof(buf2), 1, fp2);

   printf("Buffer 1\n");
   for(unsigned int i=0; i<sz; i++)
      printf("%02X ", buf1[i]);

   printf("\n");

   printf("Buffer 2\n");
   for(unsigned int i=0; i<sz; i++)
      printf("%02X ", buf2[i]);

   printf("\n");

   printf("Buffer 3\n");
   for(unsigned int i=0; i<sz; i++)
   {
      printf("%02X", (buf1[i]^buf2[i]));
      fprintf(stderr, "%c", (buf1[i]^buf2[i]));
      fprintf(fp3, "%c", (buf1[i]^buf2[i]));
   }
   printf("\n");
   //fprintf(fp1, "This is testing for fprintf...\n");
   //fputs("This is testing for fputs...\n", fp);

   printf("Closing file 3\n");
   fclose(fp3);
   printf("%X\n", fp3);

   printf("Closing file 2\n");
   fclose(fp2);
   printf("%X\n", fp2);

   printf("Closing file 1\n");
   fclose(fp1);
   printf("%X\n", fp1);


  return 0;
}
