/* Задачи на сортировку */

#include <stdio.h>

void print_int_array(int** array, int n, int m)
{
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

void print_int_line(int* array, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++) {
		printf("%4d", array[i]);
    }
	printf("\n");
}

//put after scanf
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main()
{
    void tournament();
    void merge();
    void bit();
    void triangle();

    /* -- special variables -- */
    //
    /* temp */ char err = -1;
    //
    /* ----- don't touch ----- */

    int task = -1;

    //Converter type
    while (err < 1 || task < 1 || task > 4) {
        if (err == -1) {
            printf("[>] Select task number [ 1 - 4 ]: ");
        }
        else {
            printf("[>] Wrong input! Try again: ");
        }
        err = scanf("%d", &task);
        clean_stdin();
    }
    err = -1;

    switch (task) {
    case 1:
        tournament();
        break;
    case 2:
        merge();
        break;
    case 3:
        bit();
        break;
    case 4:
        triangle();
        break;
    }

    return 0;
}

void tournament()
{
    void print_int_array(int**, int, int);
    int n;

    printf("[>] Enter matrix length: ");
    scanf("%d", &n);

    //create matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    //matrix input
    printf("[>] Enter matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    //calculate team scores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][i] += matrix[i][j];
                matrix[j][j] -= matrix[i][j];
            }
        }
    }

    //Create and fill additive array
    int** sub = new int*[n];
    for (int i = 0; i < n; i++) {
        sub[i] = new int[2];
        sub[i][0] = i;
        sub[i][1] = matrix[i][i];
    }

    //sort additive array
    int temp, temp2;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (sub[j][1] < sub[j + 1][1]) {
                temp = sub[j][0];
                temp2 = sub[j][1];
                sub[j][0] = sub[j + 1][0];
                sub[j][1] = sub[j + 1][1];
                sub[j + 1][0] = temp;
                sub[j + 1][1] = temp2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        matrix[sub[i][0]][sub[i][0]] = i + 1;
    }

    print_int_array(matrix, n, n);
}

void merge()
{
	void print_int_line(int*, int);
    int n, m, c1, c2 = 0, c3 = 0;

    printf("[>] Enter matrix A length: ");
    scanf("%d", &n);
	
    int* A = new int[n];

    printf("[>] Enter matrix A: \n");
    for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
    }
	
	
	printf("[>] Enter matrix B length: ");
    scanf("%d", &m);
	
    int* B = new int[m];
	
    printf("[>] Enter matrix B: \n");
    for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
    }
	
	int* X = new int[m+n];
	int* C = new int[m+n];
	int* D = new int[m+n];
	
	//creating united array
	for (int i = 0; i < n; i++) {
		X[i]=A[i];
    }
	
	c1 = n;
	for (int i = 0; i < m; i++){
		int z = 0;
		for (int j = 0; j < n; j++){
			if (B[i] == A[j]){
				z = 1;
				break;
			}
		}
		if (z == 0){
			X[c1++] = B[i];
		}
	}
	
	//sort united
    for (int i = c1 - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (X[j] > X[j+1]) {
                int temp = X[j];
                X[j] = X[j+1];
                X[j+1] = temp;
            }
        }
    }
	
	//divide between two arrays
	for (int i = 0; i < c1; i++){
		int z = 0;
		for (int j = 0; j < n; j++){
			if (X[i] == A[j]){
				z++;
				break;
			}
		}
		for (int j = 0; j < m; j++){
			if (X[i] == B[j]){
				z++;
				break;
			}
		}
		if (z == 2){
			C[c2++] = X[i];
		} else {
			D[c3++] = X[i];
		}
	}
	
	print_int_line(C, c2);
	print_int_line(D, c3);
}

void bit()
{
}

void triangle()
{
}