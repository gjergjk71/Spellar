
#define ALPHABET_LENGTH 26


struct node {
	char ch;
	int comp_word; // complete word
	struct node *childrens[ALPHABET_LENGTH + 1]; // +1 is for apostrophes
};

int load(struct node trie[],char dict[]);
int check(struct node trie[],char string[],size_t size);