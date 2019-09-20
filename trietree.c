#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <time.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct Node ////node
{ 
	struct Node *children[26];///alphabet size  
	bool isEndOfWord; ////end of a word
}; 



struct Node *createNode(void) //////create a new node
{ 
	struct Node *newnode = NULL; 

	newnode = (struct Node *)malloc(sizeof(struct Node)); 
    
    newnode->isEndOfWord = false; 

	for (int i = 0; i <26; i++) ////set all child node to null
		newnode->children[i] = NULL; 
	

	return newnode; 
}


void insert(struct Node *root, const char *key) 
{ 
	
	int index; 

	struct Node *temp = root; 
	//printf("%ld",strlen(key));
	for (int i = 0; i < strlen(key)-2; i++) 
	{   

		index = CHAR_TO_INDEX(key[i]); 
		if (!temp->children[index]) 
			temp->children[index] = createNode(); 

		temp = temp->children[index]; 
	} 

 
	temp->isEndOfWord = true; ///end of a stored word 
}

void treeTraverse(struct Node* node, char* arr){

	char k[100]={0};
	char a[2]={0};
	struct Node * current = node;
	bool isNull = true;
	int i;
	for(i=0;i<26;i++){  /////check wether childern have values
		if(current->children[i]!=NULL){
			isNull = false;//if at least one child si
		}
	}
	if(current->isEndOfWord&&!isNull){
		printf("%s",arr);
		printf("\n");
	}

	if(isNull){
		
		printf("%s",arr);
		printf("\n");
		return;
	}

	int j;
	for(j=0;j<26;j++){
		if(current->children[j] != NULL){
			
			strcpy(k,arr);
			a[0]=j+'a';
			a[1]='\0';
			strcat(k,a);		
			treeTraverse(current->children[j],k);
		}
	}

}



int printSuggestions(struct Node* node, char* arr){
	int i=0;
	while(arr[i]!='\0'){
		if(node->children[arr[i]-'a']==NULL){
			printf("No suggestions\n");
			return 1;
		}else{
			node = node->children[arr[i]-'a'];
			
		}
		i++;
	}
	
	treeTraverse(node, arr);

	return 0;
}

int count(struct Node* root){ ///count the number of nodes
  int numberofnodes=0;
  
  for(int i=0;i<26;i++){
  	if(root->children[i]!=NULL){
  		break;
  	}
  }
  numberofnodes++;


  for(int i=0;i<26;i++){
  	if(root->children[i]!=NULL){
  		
  		numberofnodes+=count(root->children[i]);
  	}
  }

  return numberofnodes;

}


int main(){
 
//char keys[][1] = {"the"}; 
//char output[][32] = {"Not present in trie", "Present in trie"};
struct Node *root = createNode(); 
 
//for (int i = 0; i < ARRAY_SIZE(keys); i++) 
		//insert(root,"t");
		//insert(root,"b");
//printf("number of node :%d",count(root));

	FILE *fp;
	char str[100];
	fp=fopen("wordlist1000.txt","r");///open txt file
	if(fp==NULL){
		printf("could not open the file");
		return 1;
	}


	double time_spentinsert=0.0,time_spentsugges=0.0;
    clock_t begin=clock();
	
	while(fgets(str,100,fp)!=NULL){
		//printf("%s",str);
		insert(root,str); ///insert into tree
	}
	clock_t end=clock();
	time_spentinsert+=(double)(end-begin)/CLOCKS_PER_SEC;


	fclose(fp);

	printf("Enter a word :");
	char prefix[100];
	scanf("%s",prefix);
	
	printf("suggetions...\n");

	clock_t begin2=clock();

	printSuggestions(root,prefix);

	clock_t end2=clock();
	time_spentsugges+=(double)(end2-begin2)/CLOCKS_PER_SEC;


	//////caculate the memory usage
	long int nodesize=sizeof(struct Node);

	long int memsize=nodesize*count(root);

	printf("insertion time  :%f second \n",time_spentinsert);
	printf("suggestion time :%f second \n",time_spentsugges);
	printf("memory usage :%ld bytes \n",memsize);

return 0;

}




