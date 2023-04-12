#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>


typedef struct stack{
    struct list_head* node;
    void* data;
}Stack;

Stack* initStack();
int size(Stack* head);
void push(Stack* head, size_t size, void* data);
void stack(Stack* head, size_t size, void* data);
void unstack(Stack* head, size_t size, void* data);
void clear(Stack* head);
void pop(Stack* head);
void top(Stack* head);
