#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		printf("after sort\n");
		writelines(lineptr, nlines);
		return 0;
	} else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

void qsort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) {
		return;
	}

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) <= 0) {
			swap(v, ++last, i);
		}
	}

	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
	char *tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}