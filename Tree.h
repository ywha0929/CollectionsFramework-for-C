#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <List.h>

#define FORWARD_EDGE 1
#define REVERSE_EDGE 2
#define TWOWAY_EDGE 3

typedef struct tree{
	struct list_head* node;
	void* data;
	struct tree* parent;
	List children;
}Tree;

Tree* initTree();
int size(Tree* head);
void linkNode(Tree* node, Tree* newNode);
Tree* makeNode(void* data, size_t size);
int deleteNode(Tree* targetNode);
int deleteEdge(Tree* from,Tree* to);
int depth(Tree* head);
void drawTree(Tree* head);
