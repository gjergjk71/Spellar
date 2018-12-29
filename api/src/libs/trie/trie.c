#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int load(struct node trie[],char dict[]){
	char ch;
	FILE *fp;
	fp = fopen(dict,"r");
	if (fp == NULL){
		perror("Error while opening file\n");
		exit(EXIT_FAILURE);
	}
	struct node *cNodes = trie;
	int i = 0;
	int *last_nodes_comp_word = NULL;
	while ((ch = fgetc(fp)) != EOF){
		if (ch == '\n'){
			*last_nodes_comp_word = 1;
			cNodes = trie;
		} else {
			int found = 0;
			for (i=0;i<ALPHABET_LENGTH+1;i++){
				if (cNodes->childrens[i] == NULL){
					break;
				}
				if (cNodes->childrens[i]->ch == ch){
					found = 1;
					cNodes = cNodes->childrens[i];
					break;
				}
			}
			if (!found){
				cNodes->childrens[i] = malloc(sizeof(struct node));
				cNodes->childrens[i]->ch = ch;
				last_nodes_comp_word = &(cNodes->childrens[i]->comp_word);
				cNodes = cNodes->childrens[i];
			}
		}
	}
	fclose(fp);
	return 0;
}

int check(struct node trie[],char string[],size_t size){
	struct node *cNodes = trie;
	int found = 0;
	for (int x=0;x<size-1;x++){
		found = 0;
		for (int i=0;i<ALPHABET_LENGTH+1;i++){
			if (cNodes->childrens[i] == NULL){
				printf("%d\n",i);
				break;
			}
			if (cNodes->childrens[i]->ch == string[x]){
				found = 1;
				printf("Found %c\n",string[x]);
				cNodes = cNodes->childrens[i];
				break;
			}
		}
		if (!found){
			return 0;
		}
	}
	return 1;
}