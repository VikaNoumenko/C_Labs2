#include <stdio.h>
#include <time.h>

int recursive(int n) {// рекурсивное вычисление

	if(n == 0){
		return 1;
	}

	int current = recursive(n / 2)  + recursive(n / 3);
	return current;
}

int iterative(int n) {// итеративная функция
	    int *a = ( int *) calloc(n+1, sizeof(int));
	    a[0]=1;

		for (int  i = 1; i <= n ; i++) {
        a[i] = a[i/ 2]   + a[i / 3];
		}

	return a[n];
}


int main() {
	clock_t begin = clock();

	printf("\n Iterative: %d\n", iterative(2000));
	//--------------------------
	clock_t intermediate = clock();

	printf("\n Recursive: %d\n", recursive(2000));
	clock_t final = clock();

	printf("\n TIME OF EXECUTING: %lu and %lu\n", intermediate - begin, final - intermediate);
	_getch();
	return 0;

}
