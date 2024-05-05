#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

#define SIZE 3

void createList(FILE* inp, node_t* hp[]) {
	info_t temp;

	while (fscanf(inp, "%d %[^:]: %[^\n]", &temp.type, temp.name, temp.time) != EOF)
		hp[temp.type - 1] = addBeginning(hp[temp.type - 1], temp);
}

void displayList(node_t* hp) {
	if (hp == NULL)
		printf("The list is empty\n");
	else
	{
		while (hp != NULL) {
			printf("%4d %-20s %-10s\n", hp->data.type, hp->data.name, hp->data.time);
			hp = hp->next;
		}
		printf("  NULL\n");
	}
}

int main(void)
{
	FILE* inp;
	inp = fopen("courses.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		node_t* headp[SIZE];

		int i;

		for (i = 0; i < SIZE; i++)
			headp[i] = NULL;

		createList(inp, headp);

		for (i = 0; i < SIZE; i++)
		{
			switch (i)
			{
			case 0:
				printf("\n\tAerobics\n");
				break;
			case 1:
				printf("\n\tZumba\n");
				break;
			case 2:
				printf("\n\tPilates\n");
				break;
			}
			printf("**********************************\n");
			displayList(headp[i]);
		}
	}
	return 0;
}