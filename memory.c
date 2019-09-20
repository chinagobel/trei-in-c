#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <time.h>

struct Node ////node
{ 
	struct Node *children[26];///alphabet size  
	bool isEndOfWord; ////end of a word
}; 

int main(){
double time_spent=0.0;
clock_t begin=clock();

printf("bytes :%ld \n",sizeof(struct Node));

clock_t end=clock();

time_spent+=(double)(end-begin)/CLOCKS_PER_SEC;

printf("time elpased is %f seconds \n",time_spent);
return 0;

}