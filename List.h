#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>

typedef struct list{
    struct list_head node;

}List;

List* initList();
int add(List* head, size_t size, void* data);
int addAfter(List* head, size_t size, void* data, int index);
int addBefore(List* head, size_t size, void* data, int index);
void* get(List* head, int index);
void* delete(List* head, int index);
void* clear(List* head);
int size(List* head);
void* sort(List* head);
