#include <stdio.h>
#include <string.h>

#define XMAX 1080
#define YMAX 375

struct point {
	int x;
	int y;
};


struct rect {
	struct point pt1;
	struct point pt2;
};

struct rect screen;
struct point middle;
struct point makepoint(int, int);



struct point makepoint(int x, int y) {
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}


struct point addpoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x <= r.pt2.x 
		&& p.y >= r.pt1.y && p.y <= r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b)) 

struct rect canonrect(struct rect r) {
	struct rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

void dumppoint(char *info, struct point *p) {
	printf("%s:(%d,%d)\n", info, p->x, p->y);
}


int main() {
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, YMAX);

	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
	dumppoint("middle", &middle);

	struct point origin, *pp;
	pp = &origin;
	origin.x = 1;
	origin.y = 2;
	dumppoint("origin is", &origin);

	pp->x += 2;
	pp->y += 3;
	dumppoint("pp is", pp);


	struct cstr {
		int len;
		char *str;
	} *p;

	const char *he = "hello world";

	struct cstr cString;
	cString.len = strlen(he);
	cString.str = he;
	p = &cString;

	printf("%d\n", p->len);
	return 0 ;
}

