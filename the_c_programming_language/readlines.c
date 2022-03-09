#include <stdio.h>

#define MAXLINE 1000
int get_line(char *, int);
char *alloc(int);

int str_len(char *s) {
	char *p = s;
	while (*p != '\0') {
		p++;
	}
	return p - s;
}

void str_cpy(char *s, char *t) {
	while((*s++ = *t++) != '\0')
		;
	
}

int str_cmp(char *s, char *t) {
	for (; *s == *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}
	return *s - *t;
}

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLINE];

	nlines = 0;
	while((len = get_line(line, MAXLINE)) > 0) {
		if (nlines > maxlines || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			line[len - 1] = '\0';
			str_cpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines) {
	while(nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}


int get_line(char s[], int lim) {
	int i, c;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}

	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else {
		return 0;
	}
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}	
}