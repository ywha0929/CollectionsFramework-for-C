#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>


typedef struct queue{
    struct list_head* node;
    void* data;
}Queue;

Queue* initQueue();
int size(Queue* head);
void push(Queue* head, size_t size, void* data);
void enqueue(Queue* head, size_t size, void* data);
void dequeue(Queue* head);
void clear(Queue* head);
void pop(Queue* head);
void* top(Queue* head);
int isEmpty(Queue* head);