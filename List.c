#include <stdio.h>
#include <stdlib.h>
#include "list_head.h"
#include <string.h>




typedef struct list{
    struct list_head* node;
    void* data;
}List;

List* initList(size_t sizeOfData)
{
    List* thisList = (List*) malloc(sizeof(List));
    thisList->node = (struct list_head *) malloc(sizeof(struct list_head));
    thisList->node->next = thisList->node;
    thisList->node->prev = thisList->node;
    thisList->data = malloc(sizeof(sizeOfData));
}

int addNode(List* head, size_t size, void* data)
{
    List* newList = (List*) malloc(sizeof(List*));
    // printf("size of Data : %d\n",sizeof(data));
    newList->node = (struct list_head *) malloc(sizeof(struct list_head));
    newList->node->next = newList->node;
    newList->node->prev = newList->node;
    newList->data = malloc(size);
    memcpy((newList->data),data,size);
    // printf("%lld\n",*((int*)newList->data));
    // printf("%lld\n",*((int*)data));
    // printf("targetList address : %p\n",newList);
    list_add_tail((newList->node) , head->node);
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
    // free(targetList->node);
    // free(targetList->data);
    // free(targetList);
    return 0;
}

void clear(List* head)
{
    struct list_head* cur;
    List* targetList = NULL;
    int size = 2;
    // int size = size(head);
    for(int i = 0; i< size; i++)
    {
        targetList = list_entry(head->node->next,List,node)-2;
        list_del(targetList->node);
        // free(targetList->node);
        // free(targetList->data);
        // free(targetList);
    }
    return;
}

void sort(List* head, int(*comaprator)())
{
    int size = 3;
    for(int i = 0; i< size; i++)
    {
        for(int j= 0; j<size-i-1; j++)
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