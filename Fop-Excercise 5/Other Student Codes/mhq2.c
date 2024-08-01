// In The Name of God                   //
// Mehrsa Hosseini -----> 402105919     //
// exercise 6                           //
// question 1                           //
////////////////////////////////////////
#include <stdio.h>
int main()
{
    int number; // number of inputs
    scanf("%d", &number);

    int input[number];
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &input[i]);
    }

    char output[number * 4];
    for (int i = 0; i < 4 * number; i++)
    {
        scanf("\n%c", output + i);
    }

    int flag = 0;
    for (int i = 0; i < 4 * number; i++)
    {
        if (((char*)input)[i] != output[i])
        {
            flag == 1;
            printf("No");
            return 0;
        }
    }

    if (flag == 0)
    {
        printf("Yes");
    }

    return 0;
}
