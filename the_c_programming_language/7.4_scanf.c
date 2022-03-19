#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max);

int main() {
	double sum, v;

	// sum = 0;
	// while(scanf("%lf", &v) == 1) {
	// 	printf("\t%.2f\n", sum += v);
	// }

	int day, month, year;
	char monthname[20], line[MAXLINE];

	while(get_line(line, MAXLINE) > 0) {
		if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
			printf("valid: %s\n", line);
		else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
			printf("valid: %s\n", line);
		else 
			printf("invalid: %s\n", line);
	}

	return 0;
}