///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//      Part 5 "6-Head Accountant!"      //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %u): ", __LINE__); printf(fmt,val1, val2,val3)

// Abreviations
#define uint unsigned int
#define ullong unsigned long long
#define uchar unsigned char

// Type of matrix elements
#define mattype uint

// Our Main Matrix
mattype * matrix;
uint rows = 0, columns = 0;

// A Useful Macro for derefrencing the matrix Element(row,column)
#define Element(r,c) *(matrix+((r)*columns)+(c))

void ravel();
void reshape();
void resize();
void append_row();
void insert_row();
void append_column();
void insert_column();
void delete_row();
void delete_column();
void tile();
void transpose();

void print_matrix();

/* Use Realloc to resize the mem allocated to matrix (Does not change the rows,columns number values)*/
void __resizeMatrix(uint __rows, uint __cols);

/* Our Main Function */
int main()
{
    scanf("%u%u", &rows, &columns); // Scan the number of rows and columns
    matrix = (mattype *) malloc(rows * columns * sizeof(mattype));  // Allocate the Matrix in memory

    // Scan the elements of matrix
    for(uint i = 0; i < rows; i++)
        for(uint j = 0; j < columns; j++)
            scanf("%u", &(Element(i,j)));
    
    // Define an array for getting input string
    char *input_buffer = (char *) malloc(30);
    do
    {
        scanf("\n%[^\n]s", input_buffer); // Getting the input line until \n

        // Process the commands
        if(!strcmp(input_buffer, "ravel")) ravel();
        else if(!strcmp(input_buffer, "reshape")) reshape();
        else if(!strcmp(input_buffer, "resize")) resize();
        else if(!strcmp(input_buffer, "append_row")) append_row();
        else if(!strcmp(input_buffer, "insert_row")) insert_row();
        else if(!strcmp(input_buffer, "append_column")) append_column();
        else if(!strcmp(input_buffer, "insert_column")) insert_column();
        else if(!strcmp(input_buffer, "delete_row")) delete_row();
        else if(!strcmp(input_buffer, "delete_column")) delete_column();
        else if(!strcmp(input_buffer, "tile")) tile();
        else if(!strcmp(input_buffer, "transpose")) transpose();
        else continue; // Non-defined Command Entered (Or "exit" command which is checked in while condition)

        // Print the matrix in each step
        print_matrix();
    } while (strcmp(input_buffer, "exit")); // Loop until we give "exit"
    
    free(input_buffer);
    free(matrix);
    return 0;
}

/* Prints the matrix in Rows */
void print_matrix()
{
    for(uint i = 0; i < rows; i++)
    {
        for(uint j = 0; j < columns; j++) printf("%u ", Element(i,j));
        printf("\n");
    }
}

/* This function converts matrix to an one-row matrix. */
void ravel() // Test Cases : 2/4/6/7/9/10/11/12/13/14/15/17/18/19/20/21/24
{
    columns *= rows;
    rows = 1;
}

/* This funtion scan and change the dimensions of matrix without chnaging total count of elements. */
void reshape() // Test Cases : 1/5/8/9/10/11/15/16/20/21/24/25
{
    // We dont't need to resize the allocated memory
    // We only have to set the rows,columns variables
    scanf("%u%u", &rows, &columns);
}

/* This funtion scans new dimensions, and change the dimensions of matrix. */
/* And if target is larger, repeat the elements from begining in new empty elemnts */
void resize() // Test Cases : 6/7/8/9/11/12/13/14/16/17/18/21/23/24/25
{
    uint new_r = 0, new_c = 0;
    scanf("%u%u", &new_r, &new_c);

    // Reallocate the Memory
    __resizeMatrix(new_r, new_c);
    
    // For filling the new empty elements (repeat from begining)
    // (If the target is larger)
    if((new_c*new_r) > (rows*columns))
        for(uint i = rows*columns; i < (new_c*new_r); i++) 
            *(matrix+i) = *(matrix + (i % (columns*rows)));
    
    // Change the rows,columns number variables
    rows = new_r;
    columns = new_c;
}

/* This funtion scan a row, and append it at the end of the matrix. */
void append_row() // Test Cases : 3/4/6/7/8/10/14/17/18/19/22/24/25
{
    // First, We reallocate the memory and extends matrix.
    __resizeMatrix(rows + 1, columns);
    // Next, Scan the row and put it directly to the end of matrix.
    for(uint i = 0; i < columns; i++) scanf("%u", &(Element(rows, i)));
    // Increament the (rows) number
    rows++;
}

/* This funtion scan a row, and insert it at i-th (which will be scanned) row of matrix. */
void insert_row() // Test Cases : 1/4/5/6/9/12/13/14/15/16/17/18/19/20/22/24/25
{
    // First, We reallocate the memory and extends matrix.
    __resizeMatrix(rows + 1, columns);
    rows++;    // Increament the (rows) number

    // Scan the index of new row (where be placed?)
    uint rowNumber = 0;
    scanf("%u", &rowNumber);

    // Shift old rows down (from bottom upward) , to make free space in rowNumber-th row
    for(int i = rows-2; i >= (int)rowNumber; i--)
        for(int j = 0; j < columns; j++)
            Element(i+1,j) = Element(i,j);

    // Scan and put the row directly to the rowNumber-th row
    for(uint i = 0; i < columns; i++)
         scanf("%u", &(Element(rowNumber,i)));
}

/* This funtion scan a column, and append it as last column to the matrix. */
void append_column() // Test Cases : 2/4/5/6/8/9/10/12/13/14/15/17/18/19/20/21/23
{
    // First, We reallocate the memory and extends matrix.
    __resizeMatrix(rows, columns + 1);

    // Rearrange the matrix to make free space in last column
    // (Because our matrix is only have one dimension in memory!!)
    for(int i = rows*columns - 1; i >= 0; i--)
        *(matrix+((i/columns)*(columns+1) + (i%columns))) = *(matrix+i);
    
    // Increament the (columns) number
    columns++;

    // Next, Scan the column and put it directly to the last column.
    for(uint i = 0; i < rows; i++)
        scanf("%u", &(Element(i,columns-1)));    
}

/* This funtion scan a column, and insert it at i-th (which will be scanned) column of matrix. */
void insert_column() // Test Cases : 2/3/4/8/11/12/13/18/19/20/22/23/24/25
{
    // First, We reallocate the memory and extends matrix.
    __resizeMatrix(rows, columns + 1);
    
    // Scan the index of new column (where be placed?)
    uint colNumber = 0;
    scanf("%u", &colNumber);

    // Rearrange the matrix to correct the matrix (and make free space in column index colNumber )
    // It may be confusing and complicated (Because our matrix is only have one dimension in memory!!)
    for(int i = rows*columns - 1; i >= 0; i--)
        *(matrix+
            ((i+(columns-colNumber)) / columns) * (columns+1) +
            ((i+(columns-colNumber)) % columns) -(columns-colNumber)) 
            = *(matrix+i);
    
    // Increament the (columns) number
    columns++;

    // Scan and put the column directly to the colNumber-th column
    for(uint i = 0; i < rows; i++)
        scanf("%u", &(Element(i,colNumber)));
}

/* This function delete a row in index i (will be scanned) from the matrix */
void delete_row() // Test Cases : 1/2/5/8/15/16/19/20/22/23/25
{
    // Scan the index
    uint rowNumber = 0;
    scanf("%u", &rowNumber);

    // Shift Up the rows below of index i
    for(uint i = rowNumber; i < rows-1; i++)
        for(uint j = 0; j < columns; j++)
            Element(i,j) = Element(i+1,j);
    
    // Reallocate the memory with deleting last one row
    __resizeMatrix(rows - 1, columns);
    rows--; // Decreament the (rows) number
}

/* This function delete a column in index i (will be scanned) from the matrix*/
void delete_column() // Test Cases : 3/4/5/6/7/8/10/11/17/19/21/22/24
{
    uint colNumber = 0, col = columns - 1;
    scanf("%u", &colNumber); // Scan the index

    // This Part of code may be very confusing and complex!!
    // Not much explanation can be given for this part.
    // But in short, the result of this code is to remove the colNumber-th column from the matrix
    // and elements can be removed from the end. (by reallocating memory)
    for(uint i = 0; i < rows*columns; i++)
        *(matrix+i) =
            *(matrix+
                ((i+(col-colNumber)) / col) * (col+1) +
                ((i+(col-colNumber)) % col) - (col-colNumber));
    
    __resizeMatrix(rows, col); // Reallocate the memory
    columns--; // Decreament the (columns) number
}

/* The function tiles the matrix i by j (i,j will be scanned) */
void tile() // Test Cases : 1/6/7/8/10/11/12/14/15/16/18/20/21/22/23/24/25
{
    uint x = 0, y = 0;
    scanf("%u%u", &y, &x); // Scan the input

    // Make a copy from initial matrix
    mattype* oldMatrix = (mattype *) malloc(rows * columns * sizeof(mattype));
    uint old_r = rows, old_c = columns;
    for(uint i = 0; i < old_r; i++)
        for(uint j = 0; j < old_c; j++)
            *(oldMatrix+(old_c*i)+j) = Element(i,j);
    
    // Reallocate the memory larger enough
    __resizeMatrix(rows*y, columns*x);

    // multiply the rows and columns values to i,j (number of tiles)
    rows *= y;
    columns *= x;
    
    // TileWork the matrix (the source , is the copy of initial matrix (oldMatrix))
    for(uint i = 0; i < rows; i++)
        for(uint j = 0; j < columns; j++)
            Element(i,j) = *(oldMatrix+(i%old_r)*old_c+(j%old_c));
    
    free(oldMatrix); // Free the oldCopy of matrix  
}

/* This Function Transpose the matrix (swap rows and columns) */
void transpose() // Test Cases : 2/4/5/6/9/10/12/13/14/16/17/20/21/22/23/24/25
{
    // Create a temp new matrix and pour the transpose of main matrix into it
    mattype* newMatrix = (mattype *) malloc(rows * columns * sizeof(mattype));
    for(uint i = 0; i < rows; i++)
        for(uint j = 0; j < columns; j++)
            *(newMatrix+(j*rows)+i) = Element(i,j);
    
    // Put back the temp new matrix into the main matrix
    for(uint i = 0; i < rows*columns; i++)
        *(matrix+i) = *(newMatrix+i);

    // Swap the rows,columns number
    uint tmp = rows;
    rows = columns;
    columns = tmp;

    // Free the temp new matrix
    free(newMatrix);
}

/* Use Realloc to resize the mem allocated to matrix (Does not change the rows,columns number values)*/
void __resizeMatrix(uint __rows, uint __cols)
{
    matrix = (mattype *) realloc(matrix, __rows * __cols * sizeof(mattype));
}