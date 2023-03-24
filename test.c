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
int main(void)
{
	printf(border);
	printf("\nTest1 for List\n");
	List* list = initList(sizeof(Data));
	Data firstData;
	firstData.number1 = 1;
	firstData.number2 = 2;
	Data secondData;
	secondData.number1 = 3;
	secondData.number2 = 4;
    // secondData.number3 = 5;
	add(list,sizeof(Data),&firstData);
    // printf("sizeof Struct %d\n",sizeof(Data));
	add(list,sizeof(Data),&secondData);
	printf("\nPrint Second Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",secondData.number1,((Data*)get(list,1))->number1);
	printf("%30d %30d\n",secondData.number2,((Data*)get(list,1))->number2);

    printf("\nPrint First Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",firstData.number1,((Data*)get(list,0))->number1);
	printf("%30d %30d\n",firstData.number2,((Data*)get(list,0))->number2);
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

    add(list2,sizeof(Data2),&firstData2);
    add(list2,sizeof(Data2),&secondData2);
    add(list2,sizeof(Data2),&thirdData2);

    
    printf("sizeof struct Data2 : %d\n",sizeof(Data2));
    printf("sizeof firstData2 : %d\n",sizeof(firstData2));
    printf("sizeof secondData2 : %d\n",sizeof(secondData2));
    printf("sizeof thirdData2 : %d\n",sizeof(thirdData2));

    printf("\nPrint Second Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",secondData2.number1,((Data2*)get(list2,1))->number1);
	printf("%30d %30d\n",secondData2.number2,((Data2*)get(list2,1))->number2);
    printf("%30s %30s\n",secondData2.string1,((Data2*)get(list2,1))->string1);

    printf("\nPrint First Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",firstData2.number1,((Data2*)get(list2,0))->number1);
	printf("%30d %30d\n",firstData2.number2,((Data2*)get(list2,0))->number2);
    printf("%30s %30s\n",firstData2.string1,((Data2*)get(list2,0))->string1);

    printf("\nPrint Third Data\n");
	printf("%30s %30s\n","Expected Data","Tested Data");
	printf("%30d %30d\n",thirdData2.number1,((Data2*)get(list2,2))->number1);
	printf("%30d %30d\n",thirdData2.number2,((Data2*)get(list2,2))->number2);
    printf("%30s %30s\n",thirdData2.string1,((Data2*)get(list2,2))->string1);

}
