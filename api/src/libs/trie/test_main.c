#include "trie.c"
#include <stdlib.h>

int main(void){
	char dict[] = "test_dict.txt";
	FILE *fp = fopen(dict,"r");
	if (fp == NULL){
		perror("Error while opening file\n");
		exit(EXIT_FAILURE)
	}
	while ((ch = fgetc(fp)) != EOF){
		printf("%c",ch);
	}
	fclose(fp);
}