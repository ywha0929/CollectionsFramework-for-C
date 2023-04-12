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

int add(List* head, size_t size, void* data)
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

void* get(List* head, int index)
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


int size(List* head)
{
	struct list_head* cur;
	int i = 0;
	list_for_each(cur,head->node)
	{
			i++;
	}
	return i;
}
