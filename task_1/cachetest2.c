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

/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest2 [--repetitions M] [--array_size N]\n");
	exit(1);
}



//go random through array
int main (int argc, char *argv[])
{
  double t1, t2;

  /* variables for task 1 */
  unsigned int M = 1000;		//number of repetition
  unsigned int N = 256*1024; 	//array size
  unsigned int i;

  /* declare variables; examples, adjust for task */
	int *a;
//	double  a[100];
	int  *b;

	double sum;
	int j;
	int k;
	int temp;


	//make sure randomly generated num not the same
	srand(time(NULL));
	int rand1 ;
	int rand2;


  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {

	  //Get the number of reptitions
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();

		 //get array size
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }



  /* allocate memory for arrays; examples, adjust for task */
	 a = malloc (N * sizeof(int));
	 b = malloc (N * sizeof(int));
	 sum = 0.0;


	 /* initialise array a elements */
	 for (j =0; j<N; j++){
		 a[j] = (double)j;
		 b[j] = j;
	 }

	 //randomise array b
	 for (j=0; j<N; j++){\

		 //get random index
		 rand1 = rand()%N;
		 rand2 = rand()%N;
		 printf("r1 %d \n",rand1);
		 printf("r2 %d \n",rand2);

		 //swap values
		 temp = b[rand1];
		 b[rand1] = b[rand2];
		 b[rand2] = temp;
	 }




	  t1 = getTime();
	  printf("start time %f \n",t1);
	  /* code to be measured goes here */
	  /***************************************/

	  //for M repeats
	  for( k=0; k<M; k++){

		  for (j=0;j<N;j++){
		  	  sum = sum + a[b[i]];
		   }
	  }

	  printf("sum: %f \n",sum);

	  /***************************************/
		t2 = getTime();

		printf("end time %f \n",t2);
		printf("total time %f \n",(t2-t1));

	  /* output: (total time / M.N)*/
	  printf("time: %6.8f secs\n",((t2 - t1)/(M*N)));
	  /* free memory; examples, adjust for task */
	  free(a);
	  free(b);


  return 0;
}
