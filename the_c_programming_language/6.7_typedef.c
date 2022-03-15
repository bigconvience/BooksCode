#include <stdlib.h>

typdef int Length;

Length len, maxlen;
Length *lengths[];

typedef char *String;

#define MAXLINE 10000

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
p = (String) malloc(100);

typedef struct tnode *Treeptr;

typedef struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
} TreeNode;

typedef int (*PFI)(char *, char *);

PFI strcmp, numcmp;