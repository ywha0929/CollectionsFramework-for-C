#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <List.h>
#include <Queue.h>

#define FORWARD_EDGE 1
#define REVERSE_EDGE 2
#define TWOWAY_EDGE

typedef struct tree{
	//struct list_head node;
	void* data;
	struct tree* parent;
	List* children;
}Tree;

Tree* initTree()
{
	Tree* head;
	head = (Tree*) malloc(sizeof(Tree));
	memset(head,0,sizeof(Tree));
	head->data = NULL;
	head->parent = NULL;
	head->children = initList();
	return head;
}



void linkNode(Tree*node, Tree* newNode)
{
	Tree* parent = node;
	Tree* child = newNode;
	addNode(parent->children,sizeof(Tree*),newNode);
	child->parent = parent;
}

Tree* makeNode(void* data, size_t size)
{
	Tree* newNode;
	newNode = (Tree*)malloc(sizeof(Tree));
	memset(newNode,0,sizeof(Tree));
	newNode->data = malloc(size);
	memset(newNode->data,0,size);
	newNode->children = initList();
	newNode->parent = NULL;
}

int deleteNode(Tree* targetNode)
{
	Tree* parent = targetNode->parent;
	if(parent == NULL) // targetNode root
	{

	}
	else
	{
		
	}
}

int deleteEdge(Tree* from, Tree* to)
{

}

int depth(Tree* head)
{
	
}

void drawTree(Tree* head, void(*printNode)())
{
	Queue* visit = initQueue();
	push(visit,sizeof(Tree*), head);
	static int depth = 0;
	while(isEmpty(visit) ==0)
	{
		
	}
}
