/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;

  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;

  sec = sec + msec/1000000.0;

  return sec;
}



//matrix 1
int main (int argc, char *argv[])
{
  double t1, t2;

  /* variables*/
  unsigned int M = 1000;
  unsigned int N = 1000;
  unsigned int i,j,k;

  double value,sum;

  /* declare variables; examples, adjust for task */
	double  a[1000][1000];
	double  b[1000][1000];
	double  c[1000][1000];

	 /* initialise array elements */
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j] = 5.0;
			b[i][j] = 4.3;
		}
	}

  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/

  //product of matrix a and b
  for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
		  sum = 0.0;
		  for(k=0;k<N;k++){
			  value = a[i][k] * b[k][j];
			  sum = sum + value;

		  }
		  c[i][j] = sum;
	  }
  }




  /***************************************/
	t2 = getTime();

  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));



  return 0;

}
