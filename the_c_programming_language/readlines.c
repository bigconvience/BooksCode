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