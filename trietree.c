#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
bool prefix=true;
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

	for (int i = 0; i < strlen(key); i++) 
	{ 
		index = CHAR_TO_INDEX(key[i]); 
		if (!temp->children[index]) 
			temp->children[index] = createNode(); 

		temp = temp->children[index]; 
	} 

 
	temp->isEndOfWord = true; ///end of a stored word 
}


bool search(struct Node *root, const char *key) 
{ 
	int level; 
	int length = strlen(key); 
	int index; 
	struct Node *pCrawl = root; 

	for (level = 0; level < length; level++) 
	{ 
		index = CHAR_TO_INDEX(key[level]); 

		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

void treeTraverse(struct Node* node, char* arr){
	if(prefix){
		printf("%s",arr);
		prefix = false;
	}
	struct Node * current = node;
	bool isNull = true;
	int i;
	for(i=0;i<26;i++){  /////check wether childern have values
		if(current->children[i]!=NULL){
			isNull = false;//if at least one child si
		}
	}
	if(isNull && !prefix){
		printf("\n");
		printf("%s",arr);
		return;
	}

	int j;
	for(j=0;j<26;j++){
		if(current->children[j] != NULL){
			printf("%c",'a'+j);		
			treeTraverse(current->children[j],arr);
		}
	}

}

bool isword(struct Node * root){

	return root->isEndOfWord!=false;


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


 

 

 





int main(){
 
char keys[][9] = {"the", "tag", "apple", "they", "aim","by", "bye", "their","come"}; 
char output[][32] = {"Not present in trie", "Present in trie"};
struct Node *root = createNode(); 
int i; 
for (i = 0; i < ARRAY_SIZE(keys); i++) 
		insert(root, keys[i]); 


//printf("%s --- %s\n", "the", output[search(root, "the")] );
//printf("Number of word : %d",wordCount(root));
printSuggestions(root,"t");
	

return 0;

}




