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

int push(List* head, size_t size, void* data)
{
    // List* newList = (List*) malloc(1,sizeof(List*));
    List* newList = (List*) calloc(1,sizeof(List*));
    // printf("size of Data : %d\n",sizeof(data));
    // newList->node = (struct list_head *) malloc(1,sizeof(struct list_head));
    newList->node = (struct list_head *) calloc(1,sizeof(struct list_head));
    newList->node->next = newList->node;
    newList->node->prev = newList->node;
    // newList->data = malloc(1,size);
    newList->data = calloc(1,size);
    memcpy((newList->data),data,size);
    // printf("%lld\n",*((int*)newList->data));
    // printf("%lld\n",*((int*)data));
    // printf("targetList address : %p\n",newList);
    list_add_tail((newList->node) , head->node);
    // printf("targetList address : %p\n",newList);
    return 0;
}

int addNodeAfter(List* head, size_t size, void* data, int index)
{
	List* newList = (List*) calloc(1,sizeof(List*));
	newList->node = (struct list_head *) calloc(1,sizeof(struct list_head));
   	INIT_LIST_HEAD(newList->node);
   	newList->data = calloc(1,size);
   	memcpy((newList->data),data,size);
    	// printf("%lld\n",*((int*)newList->data));
   	// printf("%lld\n",*((int*)data));
   	// printf("targetList address : %p\n",newList);
	struct list_head* cur = NULL;
	int i = 0;
	list_for_each(cur, head->node)
	{
		if(i == index)
		{
			list_add(newList->node,cur);
		}
		i++;	

	}
	// printf("targetList address : %p\n",newList);
	return 0;


}

int addNodeBefore(List* head, size_t size, void* data, int index)
{
	List* newList = (List*) calloc(1,sizeof(List*));
	newList->node = (struct list_head *) calloc(1,sizeof(struct list_head));
   	INIT_LIST_HEAD(newList->node);
   	newList->data = calloc(1,size);
   	memcpy((newList->data),data,size);
    	// printf("%lld\n",*((int*)newList->data));
   	// printf("%lld\n",*((int*)data));
   	// printf("targetList address : %p\n",newList);
	struct list_head* cur = NULL;
	int i = 0;
	list_for_each(cur, head->node)
	{
		if(i == index-1)
		{
			list_add(newList->node,cur);
		}
		i++;	

	}
	// printf("targetList address : %p\n",newList);
	return 0;


}

void* getNode(List* head, int index)
{

    struct list_head* cur;
    int i = 0;

    list_for_each(cur,head->node)
    {
        if(i == index)
        {
            List* targetList = list_entry(cur,List,node)-2;
            // printf("targetList address : %p\n",targetList);
            // printf("%lld\n",*((int*)targetList->data));
            return (void*) targetList->data;
        }
        else
        {
            i++;
        }
    }
    return NULL;
}

List* _getNode(List* head, int index)
{

    struct list_head* cur;
    int i = 0;

    list_for_each(cur,head->node)
    {
        if(i == index)
        {
            List* targetList = list_entry(cur,List,node)-2;
            // printf("targetList address : %p\n",targetList);
            // printf("%lld\n",*((int*)targetList->data));
            return targetList;
        }
        else
        {
            i++;
        }
    }
    return NULL;
}

int removeNode(List* head, int index)
{
    struct list_head* cur;
    int i = 0;
    List* targetList = NULL;
    list_for_each(cur,head->node)
    {
        if(i == index)
        {
            targetList = list_entry(cur,List,node)-2;
            break;
        }
        else
        {
            i++;
        }

    }

    if(targetList == NULL)
    {
        return -1;
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

void clear(List* head)
{
    struct list_head* cur;
    List* targetList = NULL;
    int Size = size(head);
    // int Size = size(head);
    for(int i = 0; i< Size; i++)
    {
        targetList = list_entry(head->node->next,List,node)-2;
        list_del(targetList->node);
        free(targetList->node);
        free(targetList->data);
        free(targetList);
    }
    return;
}

void sort(List* head, int(*comaprator)())
{
    int Size = size(head);
    for(int i = 0; i< Size; i++)
    {
        for(int j= 0; j<Size-i-1; j++)
        {
            // printf("%d %d\n",i,j);
            List* firstNode = (List*)_getNode(head,j);
            // printf("%p\n",firstNode->data);
            List* secondNode = _getNode(head,j+1);
            
            if(comaprator(firstNode->data, secondNode->data) == 0)
            {
                struct list_head* prevNode = firstNode->node->prev;
                struct list_head* nextNode = secondNode->node->next;
                prevNode->next = secondNode->node;
                secondNode->node->prev = prevNode;

                secondNode->node->next = firstNode->node;
                firstNode->node->prev = secondNode->node;

                firstNode->node->next = nextNode;
                nextNode->prev = firstNode->node;
            }
        }
    }
}

