#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

#define N 100

int main(int argc, char **argv){
	int myid, size;
	int i, j, sum;
	int *A, *B, *C;		
	double exe_time;
	struct timeval stop_time, start_time;
	
	//Allocate and initialize the arrays
	A = (int *)malloc(N*N*sizeof(int));
	B = (int *)malloc(N*sizeof(int));
	C = (int *)malloc(N*sizeof(int));
	
	//Initialize data to some value
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i*N+j] = 1;	
		}
		B[i] = 1;
	}
	
	gettimeofday(&start_time, NULL);

    #pragma acc parallel loop gang vector	
	for(i=0;i<N;i++){
		sum = 0;
		for(j=0;j<N;j++){
			sum += A[i*N+j]*B[i];	
		}
		C[i] =  sum;
	}
	gettimeofday(&stop_time, NULL);	
	exe_time = (stop_time.tv_sec+(stop_time.tv_usec/1000000.0)) - (start_time.tv_sec+(start_time.tv_usec/1000000.0));
	
	//print the data
	printf("\n Matrix-Vector Multiplication output: \n");
	for(i=0;i<N;i++){
		printf("\t%d", C[i]);	
	}
	printf("\n Execution time is = %lf seconds\n", exe_time);
	
	printf("\nProgram exit!\n");
	
	//Free arrays
	free(A); 
	free(B);
	free(C);
}