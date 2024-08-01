///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 4               //
//      Part 5 "Control the Fire!"       //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

// uint and ullong for abbreviation :)
#define uint    unsigned int
#define ullong  unsigned long long

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

// Matrix I (Identity Matrix)
#define I {1,0,0,1}

// Macro For Calculate Elements of Matrix m in mod 10000
#define MOD(m)  m[0] = (m[0] < 0) ? (m[0] % 10000) + 10000 : (m[0] % 10000); \
                m[1] = (m[1] < 0) ? (m[1] % 10000) + 10000 : (m[1] % 10000); \
                m[2] = (m[2] < 0) ? (m[2] % 10000) + 10000 : (m[2] % 10000); \
                m[3] = (m[3] < 0) ? (m[3] % 10000) + 10000 : (m[3] % 10000)

// Macro For Copy a matrix
#define COPY(src,dest) dest[0] = src[0]; dest[1] = src[1]; dest[2] = src[2]; dest[3] = src[3]; 

// Macro For Product 2 Matrixes (Put answer to m1)
#define PRODUCT(m1,m2) \
 int _dest[4]; \
 _dest[0] = m1[0] * m2[0] + m1[1] * m2[2]; \
 _dest[1] = m1[0] * m2[1] + m1[1] * m2[3]; \
 _dest[2] = m1[2] * m2[0] + m1[3] * m2[2]; \
 _dest[3] = m1[2] * m2[1] + m1[3] * m2[3]; \
 MOD(_dest); \
 COPY(_dest,m1) // Copy _dest to m1

void power(uint m[], ullong N)
{
    // Declare final_matrix = I (because we product it to exponents of matrix m , each step)
    uint final_matrix[4] = I;
    // This (( base2_matrix = m )) , At the end of each step, it reaches the power of 2
    uint base2_matrix[4]; COPY(m, base2_matrix);
    for(uint i = 0; (i < 64) && (N >= (1ULL<<i)); i++)
    {
        // In each step, base2_matrix is equal to (m)^(2^i)
        // If we have to product the m with this base2_matrix, do it.
        if((N & (1ULL<<i)) != 0) { PRODUCT(final_matrix, base2_matrix); }

        PRODUCT(base2_matrix, base2_matrix); // base2_matrix = (base2_matrix)²
    }
    COPY(final_matrix, m); // ->  return final_matrix to pointer m
}

int main()
{
    ullong N = 0;
    scanf("%llu", &N);  // Scan the N (exp of matrix)

    // Matrix 2x2:
    // matrix[0]   matrix[1]
    // matrix[2]   matrix[3]
    int matrix[4];

    scanf("%d%d%d%d", &matrix[0], &matrix[1], &matrix[2], &matrix[3]);  // Input the elements
    MOD(matrix); // in mod 10000
    power(matrix, N); // Apply Power to matrix :)
    printf("%u %u\n%u %u", matrix[0], matrix[1], matrix[2], matrix[3]); // Print the matrix

    return 0;
}