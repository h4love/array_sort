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
}

void bit()
{
}

void triangle()
{
}