#include <stdio.h>
#include "Queue.h"

typedef struct data{
	int number1;
	int number2;

}Data;

typedef struct data2{
    int number1;
    char* string1;
    int number2;
}Data2;
char border[] = "----------------------------------------------------------------------\n";

int compare(Data* firstNode, Data* secondNode);

int main(void)
{
	Data data1,data2,data3;
    data1.number1 = 1;
    data1.number2 = 2;
    data2.number1 = 3;
    data2.number2 = 4;
    data3.number1 = 5;
    data3.number2 = 6;
    Queue* dataQueue = initQueue();
    push(dataQueue,sizeof(Data),&data1);
    push(dataQueue,sizeof(Data),&data2);
    push(dataQueue,sizeof(Data),&data3);
    printf("%s\n",border);
    printf("pop : \n");
    Data* cur = top(dataQueue);
    printf("%d %d\n",cur->number1,cur->number2);
    pop(dataQueue);
    cur = top(dataQueue);
    printf("%d %d\n",cur->number1,cur->number2);
}

int compare(Data* firstNode, Data* secondNode)
{
    // printf("compare\n");
    // printf("%p\n",firstNode);
    if(firstNode->number1 <= secondNode->number1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
