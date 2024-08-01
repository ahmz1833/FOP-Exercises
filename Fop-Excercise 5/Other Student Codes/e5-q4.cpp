#include <stdio.h>
//#include "grader.h"

void decryption(char *input)
{
    int n;
    sscanf(input, "%d", &n);
    int read_idx = 0;

    for (int i = 0; i < n; i++)
    {
        while (*(input + (++read_idx)) != '\n');
        int base, CountBites, level;
        char address[64];
        sscanf(input + read_idx, "%d.%d.%d.%s", &base, &CountBites, &level, address);

        unsigned long long num_address = 0;
        for (int j = 0; *(address + j) != '\0'; j++)
        {
            num_address *= base;
            if (*(address + j) >= '0' && *(address + j) <= '9')
                num_address += (*(address + j) - '0');
            else
                num_address += (*(address + j) - 'A' + 10);
        }
        void *pointer = (void *)num_address;
        for (int j = 0; j < level - 1; j++)
        {
            pointer = *((void **)pointer);
        }
        unsigned long long final = 0;
        for (int k = 0; k < CountBites; k++)
        {
            final += ((unsigned long long)(*(((unsigned char *)pointer) + k))) << (8 * k);
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
