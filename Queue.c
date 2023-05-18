#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>


typedef struct queue{
    struct list_head* node;
    void* data;
}Queue;

int size(Queue* head)
{
	struct list_head* cur;
	int i = 0;
	list_for_each(cur,head->node)
	{
			i++;
	}
	return i;
}
int isEmpty(Queue* head)
{
	if(size(head) == 0)
		return 1;
	else
		return 0;

}

Queue* initQueue(size_t sizeOfData)
{
    // List* thisList = (List*) malloc(sizeof(List));
    // thisList->node = (struct list_head *) malloc(sizeof(struct list_head));
    Queue* thisQueue = (Queue*) calloc(1,sizeof(Queue));
    thisQueue->node = (struct list_head *) calloc(1,sizeof(struct list_head));
    thisQueue->node->next = thisQueue->node;
    thisQueue->node->prev = thisQueue->node;
    // thisList->data = malloc(sizeof(sizeOfData));
	thisQueue->data = calloc(1,sizeof(sizeOfData));
	return thisQueue;
}

void push(Queue* head, size_t size, void* data)
{
    // List* newList = (List*) malloc(1,sizeof(List*));
    Queue* newNode = (Queue*) calloc(1,sizeof(Queue*));
    // printf("size of Data : %d\n",sizeof(data));
    // newList->node = (struct list_head *) malloc(1,sizeof(struct list_head));
    newNode->node = (struct list_head *) calloc(1,sizeof(struct list_head));
    newNode->node->next = newNode->node;
    newNode->node->prev = newNode->node;
    // newList->data = malloc(1,size);
    newNode->data = calloc(1,size);
    memcpy((newNode->data),data,size);
    // printf("%lld\n",*((int*)newList->data));
    // printf("%lld\n",*((int*)data));
    // printf("targetList address : %p\n",newList);
    list_add_tail((newNode->node) , head->node);
    // printf("targetList address : %p\n",newList);
    return;
}

void* top(Queue* head)
{
    struct list_head* cur;
    cur = head->node->prev;
    Queue* targetNode = list_entry(cur,Queue,node)-2;
    return targetNode->data;
}

int pop(Queue* head)
{
    struct list_head* cur;
    int i = 0;
    Queue* targetList = NULL;
    cur = head->node;
    if(cur->next == cur->prev)
    {
        return -1;
    }
    else
    {
        cur = cur->prev;
        targetList = list_entry(cur,Queue,node)-2;
    }
    
    // printf("%p\n",targetList->node->prev->next);
    // printf("%p\n",targetList->node->next);
    // targetList->node->prev->next = targetList->node->next;
    // // printf("%p\n",targetList->node->prev->next);
    // // printf("%p\n",targetList->node->next);
    // targetList->node->next->prev = targetList->node->prev;
    list_del(targetList->node);
    free(targetList->node);
    free(targetList->data);
    free(targetList);
    return 0;
}

void clear(Queue* head)
{
    struct list_head* cur;
    Queue* targetNode = NULL;
    int Size = size(head);
    // int Size = size(head);
    for(int i = 0; i< Size; i++)
    {
        targetNode = list_entry(head->node->next,Queue,node)-2;
        list_del(targetNode->node);
        free(targetNode->node);
        free(targetNode->data);
        free(targetNode);
    }
    return;
}
