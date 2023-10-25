#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>


//#define BILLION 100
#define BILLION 1000000000
#define KEY_NUM 9998
#define MEM_SIZE 400 * 1024 * 1024 
#define	SHM_NAME "/SHM_FILE"

void generate_input(int*, int);
void *sets_shared_memory();
int child_find_min_value(int, int*, int);
void put_value(int*, int, int, int);
int parent_find_min_value(void *,int, int);
