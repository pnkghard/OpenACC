#include<stdio.h>
#include<stdlib.h>

#define N 400

int calc_square(int val){
	int val_square;
	val_square = val*val;
	return val_square;
}

int main(){
	int size = N * sizeof(int);
	int a[N], aa[N];
	int i=0;
	

	//Initialize the vectors
	for(i=0; i<N; i++ ){
		a[i] = i;
	}

	// Add two vectors
    #pragma acc parallel loop
	for(i=0; i<N; i++ ){
		aa[i] = calc_square(a[i]);		
	}

	// print the output
	for(i=0; i<N; i++ ){
		printf("\t%d",aa[i]);
	}	
}