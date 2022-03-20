#define NAME_MAX 14

typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;

typedef struct {
	int fd;
	Dirent d;
} Dir;

DIR *open(char *name);
Dirent *readdir(DIR *dfd);
void closedir(DIR*dfd);
