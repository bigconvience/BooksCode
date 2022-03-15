
union u_tag {
	int ival;
	float fval;
	char *sval;
} u;


#define NSYM 1000

struct {
	char *name;
	int flags;
	int utype;
	union {
		int iva;
		float fval;
		char *sval;
	} u;
} symtab[NSYM];

