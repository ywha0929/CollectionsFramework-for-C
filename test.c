#include <stdio.h>
#include "List.h"

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
