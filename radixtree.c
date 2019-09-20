#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>



struct node // a structure to represent tree nodes 
{
    char  value[26][100];  ///value
 
 	struct node *children[26];///alphabet size
    bool isEndOfWord; ////end of a word
};

struct node* newNode(){  ////create a new node
	struct node *Node=(struct node*)malloc(sizeof(struct node));
	
	Node->isEndOfWord=false;
	

	for (int i = 0; i <26; i++) ////set all child node to null
		Node->children[i] = NULL; 
		

 	return Node;

}

char* substring(int position,int length,char *string){
	char *sub;
   	int c = 0;   
 
   while (c < position) {
      sub[c] = string[position+c-1];
      c++;
   }
   return sub;
}


void insert(struct node* root,char *key ){
	struct node *temp=root;
	int index=key[0]-'a';
	if(root->value[index]==NULL){////if there is no string in the from the first letter
		strcpy(temp->value[index],key);
	}
	/////if the key same as the current one
	for(int i=0;i<strlen(root->value[index]);i++){
		if(root->value[index][i]!=key[i]){

		}
	}


}



int main(){

	char *name="rajitha";
	printf("%ld",strlen(name));
	//printf("%s",substring(3,7,name));
	//char *m=substring(3,7,name);
	return 0;
}