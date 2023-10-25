#include "proj1.h"
#include <sys/shm.h>
void generate_input(int*arr, int ninput){
   srand(time(NULL));
   int result = 0;
   int cnt =0;
   while(cnt < ninput){
   	result = rand()%BILLION;
	arr[cnt]=result;
	cnt++;
   } 
}

void *sets_shared_memory(){ // FIX ME!
	void *ret = NULL;
	int fd;
        if((fd = shm_open(SHM_NAME,O_RDWR|O_CREAT,0666))==-1){
		printf("shmget failed\n");
		exit(0);
	}
	ftruncate(fd,MEM_SIZE);
	ret = mmap(0,MEM_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	return ret;
}

int child_find_min_value(int id, int *arr, int chunk){ // FIX ME
	int min = BILLION;
	int* array = (int*)arr;
	for(int i = 0; i<chunk; i++){
		printf(" [%d] %d",id,*(array+i));
		min = min<*(array+i) ? min : *(array+i);
	}
	printf("\n");
	return min;
}

void put_value(int *arr, int n_input, int id, int min){ // FIX ME
//	
	*((int*)arr+n_input+id) = min;
	return;
}

int parent_find_min_value(void *arr,int n_input, int n_process){ // FIX ME
	int min = BILLION;
	int* array = (int*)arr;
	for(int i = 0; i<n_process; i++){
		min = min<*(array+n_input+i) ? min : *(array+n_input+i);
	}
	return min;
}
