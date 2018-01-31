#include <stdio.h>
#include "stdlib.h"


#define RowLength 100// max 

void removeSpaces(char* string) {
	int x = 0;
	for (int i = 0; string[i]; i++) {
		if (!isspace(string[i]) || (i > 0 && !isspace(string[i - 1]))) {
			string[x] = string[i];
			x++;
		}
	}
	string[x] = '\0';
}

int main() {
	FILE *file = fopen_s("textfile", "r");
	if (file == NULL) {
		puts("NOT FOUND!!!");// если не существует
		return 1;
	}

	char row[RowLength];
	fgets(&row, RowLength, file);//считывает символы из потока пока не будет достигнут конец файла.
	char *end;
	long count = strtol(row, &end, 10);// преобразовывает строку в long int
	char **rows = malloc(count * sizeof(char *));
	for (int i = 0; i < count; i++) {
		fgets(row, RowLength, file);
		rows[i] = malloc((RowLength + 1) * sizeof(char));
		strcpy(rows[i], row);
	}

	fclose(file);// закрыли файл

	for (int i = 0; i < count; i++) {
		removeSpaces(rows[i]);
	}

	for (int i = 0; i < count; i++) {
		printf("%s", rows[i]);
	}

	free(rows); // освободили память

	return 0;
}
