///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//     Part 8(2) "Violet Matrixes!"      //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int n = 0, m = 0;
    scanf("%u %u", &n, &m);  //Scan the n (dimension of matrix) and m (number of operations)

    // Input the matrix
    unsigned int matrix[n][n];
    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++)
            scanf("%u", &matrix[row][col]);
    
    // Start Inputing , and performing the operations at the same time :)
    for(int k = 0; k < m; k++)
    {
        char cmd = 0;
        scanf("%c", &cmd); // Input the operation
        if(cmd < 'A' || cmd > 'Z') {k--; continue;} // If not valid: input again

        unsigned int dest_matrix[n][n];
        unsigned int max = 0, row_num = 0,  col_num = 0;
        switch (cmd)
        {
            case 'M': // Mirror main diameter
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        dest_matrix[row][col] = matrix[col][row];
                break;
            //=========================================================
            case 'S': // Mirror second diameter
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        dest_matrix[row][col] = matrix[n-1-col][n-1-row];
                break;
            //=========================================================
            case 'H': // Reflection in a horizontal symmetry line
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        dest_matrix[row][col] = matrix[n-1-row][col];
                break;
            //=========================================================
            case 'V': // Reflection in a vertical symmetry line
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        dest_matrix[row][col] = matrix[row][n-1-col];
                break;
            //=========================================================
            case 'A': // Replace with Average of around elements (Up,Down,Left,Right)
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                    {
                        // we aren't in corner or edges
                        if(row > 0 && row < n-1 && col > 0 && col < n-1)
                            // Calculate the averages
                            dest_matrix[row][col] = (matrix[row-1][col] + 
                                                     matrix[row+1][col] + 
                                                     matrix[row][col-1] + 
                                                     matrix[row][col+1] ) / 4;
                        
                        // If we are in corner (0,0)
                        else if(row == 0 && col == 0)
                            dest_matrix[row][col] = (matrix[1][0] + matrix[0][1] ) / 2;
                        
                        // If we are in corner (0, n-1)
                        else if(row == n-1 && col == 0)
                            dest_matrix[row][col] = (matrix[n-2][0] + matrix[n-1][1] ) / 2;
                        
                        // If we are in corner (n-1, 0)
                        else if(row == 0 && col == n-1)
                            dest_matrix[row][col] = (matrix[0][n-2] + matrix[1][n-1] ) / 2;

                        // If we are in corner (n-1, n-1)
                        else if(row == n-1 && col == n-1)
                            dest_matrix[row][col] = (matrix[n-1][n-2] + matrix[n-2][n-1] ) / 2;
                        
                        // Else, If we are in top edge
                        else if(row == 0)
                            dest_matrix[row][col] = (matrix[row+1][col] + 
                                                     matrix[row][col-1] + 
                                                     matrix[row][col+1] ) / 3;
                        // Else, If we are in bottom edge
                        else if(row == n-1)
                            dest_matrix[row][col] = (matrix[row-1][col] + 
                                                     matrix[row][col-1] + 
                                                     matrix[row][col+1] ) / 3;
                        // Else, If we are in left edge
                        else if(col == 0)
                            dest_matrix[row][col] = (matrix[row+1][col] + 
                                                     matrix[row-1][col] + 
                                                     matrix[row][col+1] ) / 3;
                        // Else, If we are in right edge
                        else if(col == n-1)
                            dest_matrix[row][col] = (matrix[row+1][col] + 
                                                     matrix[row-1][col] + 
                                                     matrix[row][col-1] ) / 3;
                    }
                break;
            //=========================================================
            case 'U': // Tafazol az bishine
                max = 0;
                // Iterate to find the maximum element
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        max = (matrix[row][col] > max) ? matrix[row][col] : max;
                // Tafazol
                for(int row = 0; row < n; row++)
                    for(int col = 0; col < n; col++)
                        dest_matrix[row][col] = max - matrix[row][col];
                break;
            //=========================================================
            case 'R': // Row sorting
                scanf("%d", &row_num);
                row_num -= 1; // The input row_num is one-based

                // Bubble Sort Algorithm (Acsending)
                for(int i = 0; i < n-1; i++)
                    for(int j = i; j < n; j++)
                        if(matrix[row_num][j] < matrix[row_num][i])
                        {
                            matrix[row_num][j] = matrix[row_num][j] ^ matrix[row_num][i];
                            matrix[row_num][i] = matrix[row_num][j] ^ matrix[row_num][i];
                            matrix[row_num][j] = matrix[row_num][j] ^ matrix[row_num][i];
                        }
                continue; // Continue the operations loop : because we mustn't copy dest_matrix to matrix :)
            //=========================================================
            case 'C': // Column Sorting
                scanf("%d", &col_num);
                col_num -= 1; // The input col_num is one-based

                // Bubble Sort Algorithm (Acsending)
                for(int i = 0; i < n-1; i++)
                    for(int j = i; j < n; j++)
                        if(matrix[j][col_num] < matrix[i][col_num])
                        {
                            matrix[j][col_num] = matrix[j][col_num] ^ matrix[i][col_num];
                            matrix[i][col_num] = matrix[j][col_num] ^ matrix[i][col_num];
                            matrix[j][col_num] = matrix[j][col_num] ^ matrix[i][col_num];
                        }
                continue; // Continue the operations loop : because we mustn't copy dest_matrix to matrix :)
        }

        // Copy dest_matrix to matrix :)
        // Because in next proccess of loop, we will work with matrix :)
        for(int row = 0; row < n; row++)
            for(int col = 0; col < n; col++)
                matrix[row][col] = dest_matrix[row][col];
    }

    // Print
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
            printf("%d ", matrix[row][col]);
        
        if(row < n-1) printf("\n");
    }
}