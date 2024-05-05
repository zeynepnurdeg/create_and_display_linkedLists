#define MAX 25

typedef struct {
	int type;
	char name[MAX];
	char time[MAX];
}info_t;

typedef info_t LType;

typedef struct node_s {
	LType data;
	struct node_s* next;
}node_t;

node_t* getnode(void) {
	node_t* node;
	node = (node_t*)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}

node_t* addBeginning(node_t* hp, LType item) {
	node_t* newp;
	newp = getnode();
	newp->next = hp;
	newp->data = item;
	return (newp);
}

void addAfter(node_t* p, LType item) {
	node_t* newp;
	newp = getnode();
	newp->next = p->next;
	p->next = newp;
	newp->data = item;
}