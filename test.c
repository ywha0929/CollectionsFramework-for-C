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
	printf(border);
	printf("\nTest1 for List\n");
	List* list = initList(sizeof(Data));
	Data firstData;
	firstData.number1 = 4;
	firstData.number2 = 2;
	Data secondData;
	secondData.number1 = 1;
	secondData.number2 = 4;
    // secondData.number3 = 5;
	addNode(list,sizeof(Data),&firstData);
    // printf("sizeof Struct %d\n",sizeof(Data));
	addNode(list,sizeof(Data),&secondData);
	printf("\nPrint Second Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",secondData.number1,((Data*)getNode(list,1))->number1);
	printf("%30d %30d\n",secondData.number2,((Data*)getNode(list,1))->number2);

    printf("\nPrint First Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",firstData.number1,((Data*)getNode(list,0))->number1);
	printf("%30d %30d\n",firstData.number2,((Data*)getNode(list,0))->number2);
    printf(border);

    printf("\nTest2 for List\n");
    List* list2 = initList(sizeof(Data2));
    Data2 firstData2;
    firstData2.number1 = 1;
    char string1[] = "Hello World";
    firstData2.string1 = (char*) malloc(sizeof(char)*strlen(string1)+1);
    strcpy(firstData2.string1,string1);
    firstData2.number2 = 2;

    Data2 secondData2;
    secondData2.number1 = 3;
    char string2[] = "My name is";
    secondData2.string1 = (char*) malloc(sizeof(char)*strlen(string2)+1);
    strcpy(secondData2.string1,string2);
    secondData2.number2 = 4;

    Data2 thirdData2;
    thirdData2.number1 = 5;
    char string3[] = "Ajou University";
    thirdData2.string1 = (char*) malloc(sizeof(char)*strlen(string3)+1);
    strcpy(thirdData2.string1,string3);
    thirdData2.number2 = 6;

    addNode(list2,sizeof(Data2),&firstData2);
    addNode(list2,sizeof(Data2),&secondData2);
    addNode(list2,sizeof(Data2),&thirdData2);

    
    printf("sizeof struct Data2 : %d\n",sizeof(Data2));
    printf("sizeof firstData2 : %d\n",sizeof(firstData2));
    printf("sizeof secondData2 : %d\n",sizeof(secondData2));
    printf("sizeof thirdData2 : %d\n",sizeof(thirdData2));

    printf("\nPrint Second Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",secondData2.number1,((Data2*)getNode(list2,1))->number1);
	printf("%30d %30d\n",secondData2.number2,((Data2*)getNode(list2,1))->number2);
    printf("%30s %30s\n",secondData2.string1,((Data2*)getNode(list2,1))->string1);

    printf("\nPrint First Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",firstData2.number1,((Data2*)getNode(list2,0))->number1);
	printf("%30d %30d\n",firstData2.number2,((Data2*)getNode(list2,0))->number2);
    printf("%30s %30s\n",firstData2.string1,((Data2*)getNode(list2,0))->string1);

    printf("\nPrint Third Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",thirdData2.number1,((Data2*)getNode(list2,2))->number1);
	printf("%30d %30d\n",thirdData2.number2,((Data2*)getNode(list2,2))->number2);
    printf("%30s %30s\n",thirdData2.string1,((Data2*)getNode(list2,2))->string1);

    printf("\nAfter removing second data\n");
    removeNode(list2,1);

    printf("\nPrint First Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",firstData2.number1,((Data2*)getNode(list2,0))->number1);
	printf("%30d %30d\n",firstData2.number2,((Data2*)getNode(list2,0))->number2);
    printf("%30s %30s\n",firstData2.string1,((Data2*)getNode(list2,0))->string1);

    printf("\nPrint Second Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",thirdData2.number1,((Data2*)getNode(list2,1))->number1);
	printf("%30d %30d\n",thirdData2.number2,((Data2*)getNode(list2,1))->number2);
    printf("%30s %30s\n",thirdData2.string1,((Data2*)getNode(list2,1))->string1);

    
    printf("\nAfter clearing list2\n");
    // clear(list2);
    printf("getNode(list2,0) return value : %p\n",getNode(list2,0));
    
    Data thirdData;
	thirdData.number1 = 0;
	thirdData.number2 = 4;
    addNode(list,sizeof(Data),&thirdData);

    printf("\nBefore sorting list1\n");
    for(int i = 0; i< 3; i++)
    {
        printf("number1 : %d \t",((Data*)getNode(list,i))->number1);
	    printf("number2 : %d \n",((Data*)getNode(list,i))->number2);
    }
    printf("\nAfter sorting list1\n");
    printf("%p\n",&firstData);
    sort(list,&compare);
    for(int i = 0; i< 3; i++)
    {
        printf("number1 : %d \t",((Data*)getNode(list,i))->number1);
	    printf("number2 : %d \n",((Data*)getNode(list,i))->number2);
    }
    
}

int compare(Data* firstNode, Data* secondNode)
{
    printf("compare\n");
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
