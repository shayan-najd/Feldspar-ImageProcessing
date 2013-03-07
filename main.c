#include <stdio.h>
#include <stdlib.h>

#include "logoPPM.c"
#include "fromColoredToBW.c"
#include "toGray.c"

int toBw  ();
int toGSc ();

int main() 
{
  int r;
  printf ("For grayscale enter 0, for black and white 1:");
  scanf("%d", &r);
  if (r) 
    {
      return toBw();
    }
  else
    {
      return toGSc();
    }
} 

int toBw ()
{
  struct array * colored;
  colored = calloc(1, sizeof(struct array));
  logoPPM(colored);
  struct array * bw;
  bw = calloc(1, sizeof(struct array));
  fromColoredToBW(colored,bw);
  FILE *fp = fopen("results.pbm", "a");
  if (fp == NULL)
    {
      printf("Couldn not open results.pbm!\n");
    } 
  else
    { 
      fprintf(fp, "P1\n100 92\n255\n");
      int j;
      for (j = 0;j < bw->length ; j++) 
	fprintf(fp,"%d\n", at(int32_t,bw,j));
      //fclose(fp);
      // free(bw);
    }
  return 0;
}

int toGSc ()
{
  struct array * colored;
  colored = calloc(1, sizeof(struct array));
  logoPPM(colored);
  struct array * gsc;
  gsc = calloc(1, sizeof(struct array));
  toGray(colored,gsc);
  FILE *fp = fopen("results.pgm", "a");
  if (fp == NULL)
    {
      printf("Couldn not open results.pgm!\n");
    } 
  else
    { 
      fprintf(fp, "P2\n100 92\n255\n");
      int j;
      for (j = 0;j < gsc->length ; j++) 
	fprintf(fp,"%d\n", at(int32_t,gsc,j));
      //fclose(fp);
      // free(bw);
    }
  return 0;
}
