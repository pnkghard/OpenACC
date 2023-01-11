#include<stdio.h>
#include<stdlib.h>
//#include<omp.h>

#define ARRSIZE 10
/*
    export PGI_ACC_NOTIFY=1
    pgcc -Minfo=accel -ta=tesla:managed vector_addition_v2.c
    pgcc -Minfo=accel -ta=multicore vector_addition_v2.c
*/

void print(int *p, int size){
	for(int i=0; i<size; i++){
		printf("\t%d", p[i]);
	}
}

void addition(int *a, int *b, int *c, int size){
	#pragma acc parallel loop
	for(int i=0; i<size; i++){
		c[i] = a[i] + b[i];
		printf("\t%d", c[i]);
	}
}

int main(int argc, char **argv){
	int myid, size;
	int i;
	int *A, *B, *C;	
	
	//Allocate and initialize the arrays
	A = (int *)malloc(ARRSIZE*sizeof(int));
	B = (int *)malloc(ARRSIZE*sizeof(int));
	C = (int *)malloc(ARRSIZE*sizeof(int));
	
	//Initialize data to some value
	for(i=0;i<ARRSIZE;i++){
		A[i] = rand()%100;
		B[i] = rand()%100;
	}
	
	// print the data
	printf("\nInitial data : \n");
	for(i=0;i<ARRSIZE;i++){
		printf("\t%d %d\t", A[i], B[i]);
	}

	//print the data
	printf("\nVector addition output: \n");
	addition(&A[0], &B[0], &C[0], ARRSIZE);
	printf("\nProgram exit!\n");
	
	//Free arrays
	free(A);
	free(B);
	free(C);
}

