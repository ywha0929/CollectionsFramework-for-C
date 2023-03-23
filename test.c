#include <stdio.h>
#include "List.h"

typedef struct data{
	int number1;
	int number2;

}Data;
int main(void)
{
	printf("-----------------------------------------------\n");
	printf("Tests for List\n");
	List* list = initList(sizeof(Data));
	Data firstData;
	firstData.number1 = 1;
	firstData.number2 = 2;
	Data secondData;
	secondData.number1 = 3;
	secondData.number2 = 4;
    // secondData.number3 = 5;
	add(list,sizeof(Data),&firstData);
	add(list,sizeof(Data),&secondData);
	printf("\nPrint Second Data\n");
	printf("%20s %20s\n","Expected Data","Tested Data");
	printf("%20d %20d\n",secondData.number1,((Data*)get(list,1))->number1);
	printf("%20d %20d\n",secondData.number2,((Data*)get(list,1))->number2);
    printf("\nPrint First Data\n");
	printf("%20s %20s\n","Expected Data","Tested Data");
	printf("%20d %20d\n",firstData.number1,((Data*)get(list,0))->number1);
	printf("%20d %20d\n",firstData.number2,((Data*)get(list,0))->number2);
}
