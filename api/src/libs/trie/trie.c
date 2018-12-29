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
					break;
				}
			}
			if (!found){
				cNodes->childrens[i] = malloc(sizeof(struct node));
				cNodes->childrens[i]->ch = ch;
				last_nodes_comp_word = &(cNodes->childrens[i]->comp_word);
				cNodes = cNodes->childrens[i];
				printf("<%c>Not found!\n",ch);
			}
		}
	}
	fclose(fp);
	return 0;
}