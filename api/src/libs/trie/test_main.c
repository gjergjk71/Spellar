#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


int main(void){
	char dict[] = "dict/large";
	struct node trie = {.comp_word=0};
	load(&trie,dict);
	char str[] = "dog";
	size_t sz = sizeof(str)/sizeof(str[0]);
	if (check(&trie,str,sz)){
		printf("'dog' found in trie\n");
	}
	return 0;
}