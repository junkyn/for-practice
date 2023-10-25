#include "proj1.h"


int main(int argc, char**argv){
	// 1. Set the number of input and process using arguments.
	int n_input = atoi(argv[1]);
	int n_childs = atoi(argv[2]);
	// 2. Fill the sets_shared memory function in proj1.c file
	
	
	void *arr= sets_shared_memory();
	generate_input((int *)arr,n_input);
        // 3-1. Create child processes and divides the numbers..
	pid_t* pid = (pid_t*)malloc(sizeof(pid_t)*n_childs);
	int* chunks = (int*)malloc(sizeof(int)*n_childs);
	for(int i = 0; i<n_childs; i++)chunks[i]=0;
	for(int i = 0; i<n_input;i++)chunks[i%n_childs]++;
	for(int i = 0; i<n_childs; i++){
		pid[i] = fork();
		if(pid[i] == 0){
			int min;
			int offset=0;
			for(int j = 0; j<i; j++){
				offset+=chunks[j];
			}
			min = child_find_min_value(i,(int*)arr+offset,chunks[i]);
			put_value((int*)arr,n_input,i,min);
			exit(0);
		}
	}
	for(int i = 0; i<n_childs; i++){
		wait(NULL);
	}
	int min = parent_find_min_value((int*)arr,n_input,n_childs);
	printf("\n");
	printf("Min Value is %d\n",min);
	shm_unlink(SHM_NAME);

	// 3-2. Childs: Find the minimum value from their chunk.
	// 4. Childs: After finding the minimum value, store it to the share memory spaces.
	//            Dest : arr + (size of int * number of input + child process index)
	//    
	
	//5-1. Parent waits and reaps child processes
	
	//5-2. Find min values from the results of child processes.
	//parent_find_min_value(arr, n_input, n_process);

	//6-1. Print the minimum value.

	//6-2. Unmap and Unlink shared memory region
	return 0;

}
