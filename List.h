#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>

typedef struct list{
    struct list_head node;

}List;

List* initList();
int addNode(List* head, size_t size, void* data);
int addNodeAfter(List* head, size_t size, void* data, int index);
int addNodeBefore(List* head, size_t size, void* data, int index);
void* getNode(List* head, int index);
int removeNode(List* head, int index);
void clear(List* head);
int size(List* head);
void sort(List* head, int(*comaprator)());
