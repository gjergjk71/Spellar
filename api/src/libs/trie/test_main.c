#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int main(void){
	char dict[] = "test_dict.txt";
	struct node root = {.comp_word=0};
	load(&root,dict);
	return 0;
}