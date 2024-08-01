#include <stdio.h> // Sara Ghazavi 402106348
#include <string.h>
#include <stdlib.h>
int row, column;
int *matrix;

void print_mat()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", *(matrix + i * column + j));
        }
        printf("\n");
    }
}

void ravel()
{
    column = row * column;
    row = 1;
}

void reshape()
{
    scanf("%d %d", &row, &column);
}

void resize()
{
    int new_row, new_collumn, tmp = 0;
    scanf("%d %d", &new_row, &new_collumn);
    matrix = (int *)realloc(matrix, new_row * new_collumn * sizeof(int));
    for (int i = 0; i < new_row; i++)
    {
        for (int j = 0; j < new_collumn; j++)
        {
            if (tmp == row * column)
                tmp = 0;
            *(matrix + i * new_collumn + j) = *(matrix + tmp);
            tmp++;
        }
    }
    row = new_row;
    column = new_collumn;
}

void append_row()
{
    matrix = (int *)realloc(matrix, (row + 1) * column * sizeof(int));
    for (int i = 0; i < column; i++)
        scanf("%d", matrix + row * column + i);
    row++;
}

void insert_row()
{
    matrix = (int *)realloc(matrix, (row + 1) * column * sizeof(int));
    int where;
    scanf("%d", &where);
    for (int i = 0; i < column; i++)
    {
        for (int j = row; j > where; j--)
        {
            *(matrix + j * column + i) = *(matrix + (j - 1) * column + i);
        }
        scanf("%d", matrix + where * column + i);
    }
    row++;
}

void append_column()
{
    matrix = (int *)realloc(matrix, row * (column + 1) * sizeof(int));
    for (int idx = row * column - 1; idx >= 0; idx--)
    {
        *(matrix + (idx / column) * (column + 1) + (idx % column)) = *(matrix + idx);
    }
    for (int i = 0; i < row; i++)
        scanf("%d", matrix + column * (i + 1) + i);
    column++;
}

void insert_column()
{
    matrix = (int *)realloc(matrix, row * (column + 1) * sizeof(int));
    int where;
    scanf("%d", &where);
    for (int idx = row * column - 1; idx >= 0; idx--)
    {
        if ((idx % column) < where)
        {
            *(matrix + (idx / column) * (column + 1) + (idx % column)) = *(matrix + idx);
        }
        else
        {
            *(matrix + (idx / column) * (column + 1) + (idx % column) + 1) = *(matrix + idx);
        }
    }
    for (int i = 0; i < row; i++)
        scanf("%d", matrix + (column + 1) * i + where);
    column++;
}

void delete_row()
{

    int where;
    scanf("%d", &where);
    for (int i = (where + 1) * column; i < row * column; i++)
    {
        *(matrix + i - column) = *(matrix + i);
    }
    matrix = (int *)realloc(matrix, (row - 1) * column * sizeof(int));
    row--;
}

void delete_column()
{
    int where;
    scanf("%d", &where);
    for (int i = 0; i < row * column; i++)
    {
        if (i % column == where)
            continue;
        else if (i % column > where)
            *(matrix + i - (i / column + 1)) = *(matrix + i);
        else
            *(matrix + i - (i / column)) = *(matrix + i);
    }
    matrix = (int *)realloc(matrix, row * (column - 1) * sizeof(int));
    column--;
}

void tile()
{
    int big_row, big_column;

    scanf("%d %d", &big_row, &big_column);
}

void transpose()
{
    int *copy = (int *)malloc(row * column * sizeof(int));
    for (int i = 0; i < row * column; i++)
        *(copy + i) = *(matrix + i);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            *(matrix + j * row + i) = *(copy + i * column + j);
    row = row + column;
    column = row - column;
    row = row - column;
}

int main()
{
    scanf("%d %d", &row, &column);
    matrix = (int *)malloc(row * column * sizeof(int));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            scanf("%d", matrix + i * column + j);

    char input[100];
    do
    {
        scanf("\n%[^\n]s", input);
        if (!strcmp(input, "ravel"))
            ravel();
        else if (!strcmp(input, "reshape"))
            reshape();
        else if (!strcmp(input, "resize"))
            resize();
        else if (!strcmp(input, "append_row"))
            append_row();
        else if (!strcmp(input, "insert_row"))
            insert_row();
        else if (!strcmp(input, "append_column"))
            append_column();
        else if (!strcmp(input, "insert_column"))
            insert_column();
        else if (!strcmp(input, "delete_row"))
            delete_row();
        else if (!strcmp(input, "delete_column"))
            delete_column();
        else if (!strcmp(input, "tile"))
            tile();
        else if (!strcmp(input, "transpose"))
            transpose();
        else 
            continue;
        print_mat();
    } while (strcmp(input, "exit"));

    free(matrix);
    return 0;
}