#include <stdio.h>
//#include "grader.h"

unsigned long long finddecimal(char address[], int base)
{
    int add_number, pow = 1, i = 0;
    unsigned long long decimal = 0;
    while (address[i] != '\0')
    {
        i++;
    }
    i--;
    while (i >= 0)
    {
        if (address[i] >= '0' && address[i] <= '9')
        {
            add_number = address[i] - '0';
        }
        else if (address[i] >= 'A' && address[i] <= 'Z')
        {
            add_number = address[i] - 'A' + 10;
        }
        else if (address[i] >= 'a' && address[i] <= 'z')
        {
            add_number = address[i] - 'a' + 10;
        }
        decimal += add_number * pow;
        i--;
        pow *= base;
    }
    return decimal;
}

void decryption(char *input)
{
    int n;
    sscanf(input, "%d", &n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        while (*(input + (++index)) != '\n')
            ;
        int base, countofbytes, level;
        char address[64];
        sscanf(input + index, "%d.%d.%d.%s", &base, &countofbytes, &level, address);
        unsigned long long decimal = finddecimal(address, base);

        void *sum = (void *)decimal;
        for (int j = 0; j < level - 1; j++)
        {
            sum = *((void **)sum);
        }

        unsigned long long final = 0;
        for (int j = 0; j < countofbytes; j++)
        {
            final += ((unsigned long long)(*(((unsigned char *)sum) + j))) << (8 * j);
        }
        printf("%llu\n", final);
    }
}

/***** Main Function For Testing the program :)  ******/
int main()
{
    unsigned long long a = 0x1122334455667788;
    void *ptr1 = &a;
    void **ptr2 = &ptr1;
    void ***ptr3 = &ptr2;

    char ins[100];
    sprintf(ins, "2\n10.8.3.%llu\n16.4.2.%llX", (unsigned long long) ptr3, (unsigned long long)ptr2);
    decryption(ins);
    return 0;
}
