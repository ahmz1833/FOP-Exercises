///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//     Part 3 "Fall down of jelly!"      //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

// Declare a macro for checking a double variable is zero or not
#define IS_ZERO(x)   ((x < 0.00000000000001) && (x > -0.00000000000001))

// Abreviations
#define uint unsigned int
#define ullong unsigned long long
#define uchar unsigned char

/* Our function for swap two row with n items */
void swap(double*,double*,int);

/* Our Funtion for make matrixes row-echolon :) */
void rowEcholon(double*,int);

/* A Function for printing the matrix */
void printMatrix(double*,int);

/* Our Main Function */
int main()
{
    uint N = 0; // Declare N
    scanf("%u", &N); // Input N
    
    // Allocate Memory for the matrix
    double* matrix = (double *) calloc(N*N, sizeof(double));

    // Scan the matrix from the input
    for(int i = 0; i < N*N; i++) scanf("%lf", matrix+i);

    // Make the matrix row-echolon
    rowEcholon(matrix, N);

    // Print The result matrix (2 digit decimal point)
    printMatrix(matrix, N);

    return 0;
}

void printMatrix(double* matrix, int N)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%.2lf ", *(matrix+(i*N)+j));
        
        printf("\n");
    }
}

void rowEcholon(double* matrix, int N)
{
    // Iterate Over the rows
    for(int rowIndex = 0; rowIndex < N; rowIndex++)
    {
        int nonzerofound_flag = 1, swaped_flag = 0;

        //If Diagonal Element is Zero : 
        if(IS_ZERO(*(matrix+(rowIndex*N)+rowIndex)))
        {
            nonzerofound_flag = 0;

            // Try to found a non-zero element below it
            for(int i = rowIndex+1; i < N; i++)
                if(!IS_ZERO(*(matrix+(i*N)+rowIndex)))
                {
                    // Then Swap the rows -> To make the Diagonal Element non-zero
                    swap(matrix+(rowIndex*N), matrix+(i*N), N);
                    nonzerofound_flag = 1;
                    swaped_flag = 1;
                    break;
                }
        }
        
        // If All below elements are zero, goto next row
        if(!nonzerofound_flag) continue;

        // We have to work with pivot , for zeroing the elements below Diagonal Element
        // Iterate over rows below the diagonal element
        for(int i = rowIndex+1; i < N; i++)
        {
            // calculate a coefficient
            // (which we multiply the rowIndex-th row to it, and then subtract it from i-th row)
            double coef = ((*(matrix+(i*N)+rowIndex)) / (*(matrix+(rowIndex*N)+rowIndex)));

            // If the coefficient is zero, goto next row and check it :)
            if(IS_ZERO(coef)) continue;

            // subtract  coef*(rowIndex-th Row)    from  the i-th row
            // This makes Zero the elements below of diagonal element  .
            for(int col = rowIndex; col < N; col++)
                (*(matrix+(i*N)+col)) -= coef * (*(matrix+(rowIndex*N)+col));
            
            /* For Debug */
            // printf("\n");
            // printMatrix(matrix, N);
            // printf("\n");
        }
    }
}

void swap(double *row1, double *row2, int n)
{
    for(int i = 0; i < n; i++)
    {
        double tmp = *(row1+i);
        *(row1+i) = *(row2+i);
        *(row2+i) = tmp;
    }
}