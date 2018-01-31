#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

struct Worker
{
	char surname[15];
	char department[15];
	char position[15];
    unsigned int salary;
} company[100];


int workersNumber = 0;


void AddWorker()
{
	printf("SURNAME: ");
	scanf("%s", &company[workersNumber].surname);
	printf("DEPARTMENT: ");
	scanf("%s", &company[workersNumber].department);
	printf("POSITION: ");
	scanf("%s", &company[workersNumber].position);
	printf("SALARY: ");
	scanf("%d", &company[workersNumber].salary);
	printf("\n ADDED \n");
	workersNumber++;

}

void PrintCompany()
{
    int i;
	for (i = 0; i < workersNumber; i++)
	{
		printf("WORKER -%d: SURNAME - %s, DEPARTMENT - %s, POSITION - %s, SALARY - %d\n ", i + 1, company[i].surname, company[i].department, company[i].position, company[i].salary);
	}
}

void FindWorker()
{
	char searchWorker[50];
	printf("ENTER WORKER FOR EDITING': \n");
	scanf("%s", &searchWorker);
	int i;
	int index;
	int isFound = 0;
	for (i = 0; i < workersNumber; i++)
	{
		if (strcmp(company[i].surname, searchWorker) == 0)
		{
			isFound = 1;
			index = i;
		}
	}

	if (isFound)
	{
		printf("WORKER - %d: SURNAME - %s, DEPARTMENT - %s, POSITION - %s, SALARY - %d\n ", index + 1, company[index].surname, company[index].department, company[index].position, company[index].salary);
		return;
	}
	else
	{
		printf("WORKER IS NOT FOUND!!!");
		return;
	}

}

void UpdateWorker()
{
	char searchWorker[50];
	printf("ENTER SURNAME FOR EDITING: \n");
	scanf("%s", &searchWorker);
	int i;
	int index;
	int isFound = 0;
	for (i = 0; i < workersNumber; i++)
	{
		if (strcmp(company[i].surname, searchWorker) == 0)
		{
			isFound = 1;
			index = i;
		}
	}

	if (isFound)
	{
		printf("ENTER DEPARTMENT ");
		scanf("%s", company[index].position);
		printf("ENTER SALARY ");
		scanf("%d", company[index].salary);
	}
	else
	{
		printf("WORKER IS NOT FOUND");
	}

}
void RemoveWorker()
{
	char searchWorker[50];
	printf("ENTER SURNAME FOR REMOVING ");
	scanf("%s", &searchWorker);
	int i, j, index;
	int isWorkerInCompany = 0;
	for (i = 0; i < workersNumber; i++)
	{
		if (strcmp(company[i].surname, searchWorker) == 0)
		{
			isWorkerInCompany = 1;
			index = i;
		}
	}
	if (!isWorkerInCompany)
	{
		printf("WORKER IS NOT FOUND!!!");
	}
	else
	{
		for (j = index; j < workersNumber; j++) {
			company[j] = company[j + 1];
		}
		printf(" \n WORKER IS REMOVED \n");
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int comm;
	while (1) {
		printf("\n SELECT COMMAND: \n 1)ADD\n 2)PRINT\n 3)UPDATE\n 4)REMOVE\n 5)FIND\n 0)EXIT\n");
		printf("\n ENTER NUMBER OF COMMAND: ");
		scanf("%d", &comm);
		switch (comm) {
		case 1: AddWorker(); break;
		case 2: PrintCompany(); break;
		case 3: UpdateWorker(); break;
		case 4: RemoveWorker(); break;
		case 5: FindWorker(); break;
		case 0: printf("EXIT\n"); break;
		default:
			printf("NOT FOUND!!!\n");
		}
	}
	_getch();
	return 0;
}
