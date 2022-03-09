#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[]) {
	int nlines;
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **) lineptr,  0, nlines - 1, 
			(int (*)(void *, void *)) (numeric ? numcmp : strcmp));
		printf("after sort\n");
		writelines(lineptr, nlines);
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;

	void swap(void *v[], int , int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0) 
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) {
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}