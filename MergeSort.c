#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void mergesort(uint64_t array[], uint64_t arraysize, uint64_t(*arr)[]){

	if(arraysize>1){
		uint32_t half=arraysize/2;
		uint64_t halfarray1[half];
		uint64_t halfarray2[arraysize-half];
		uint64_t j=0;
		for(; j<half; j++){
			halfarray1[j]=array[j];
			halfarray2[j]=array[j+half];
		}
		if(arraysize%2==1){
			halfarray2[half]=array[arraysize-1];
		}
		
		mergesort(halfarray1, half, &halfarray1);
		mergesort(halfarray2, arraysize-half, &halfarray2);
		
		uint32_t i=0;
		uint32_t half1=0;
		uint32_t half2=0;
		for(; i<arraysize; i++){
			if(halfarray1[half1]>halfarray2[half2]) {
				(*arr)[i]=halfarray2[half2];
				half2++;
			}
			else{
				(*arr)[i]=halfarray1[half1];
				half1++;
			}
			if(half1==(half) || half2==(arraysize-half)){
				if(half1==(half)){
					uint32_t ii=i+1;
					for(; ii<arraysize; ii++){
						(*arr)[ii]=halfarray2[half2];
						half2++;
					}
					return;
				}
				else{
					uint32_t ii=i+1;
					for(; ii<arraysize; ii++){
						(*arr)[ii]=halfarray1[half1];
						half1++;
					}
					return;
				}
			}		
		}
	}
	return;
}

void bubblesort(uint64_t(*array)[], uint32_t arrsize){
	bool sorted=0;
	while(!sorted){
		sorted=1;
		uint32_t i=0;
		for(; i<arrsize-1; i++){
			if((*array)[i]>(*array)[i+1]){
				uint64_t carry=(*array)[i];
				(*array)[i]=(*array)[i+1];
				(*array)[i+1]=carry;
				sorted=0;
			}
		}
	}
	
}

void inittestingarray(uint64_t seed, uint64_t(*arr)[], uint32_t arraysize){
	uint32_t i=0;
	uint64_t seedpp=seed;
	while(i<arraysize){
		uint64_t coll=seedpp;
		while(coll>1 && i<arraysize){
			(*arr)[i]=coll;
			coll=(coll%2==0)*(coll/2)+(coll%2==1)*(coll*3+1);
			i++;
		}
		seedpp+=1;
	}
	return;
}

int main(){
	
	uint32_t arrsize;
	printf("enter array size and will be generated randomly\n");
	scanf("%lu", &arrsize);
	uint64_t testarr[arrsize];
	
	inittestingarray(time(0), &testarr, arrsize);
	uint64_t testarr2[arrsize];
	for(uint32_t i=0; i<arrsize; i++){
		testarr2[i]=testarr[i];
		//printf("%llu, ", testarr[i]);
		
	}
	
	//printarr(arr, 10);
	clock_t start=clock();
	bubblesort(&testarr2, arrsize);
	clock_t end=clock();
	double btime=((double)(end-start));
	printf("buuble sort time was: %f miliseconds\n", btime);
	start=clock();
	mergesort(testarr, arrsize, &testarr);
	end=clock();
	double mtime=((double)(end-start));
	printf("merge sort time was: %f miliseconds\n\n", mtime);
	
	system("pause");
	return 0;
}
