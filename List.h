#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>

typedef struct list{
    struct list_head node;

}List;

List* initList();
int add(List* head, size_t size, void* data);
void* get(List* head, int index);