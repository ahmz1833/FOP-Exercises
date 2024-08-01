#include <stdio.h>
#include <stdlib.h>

void reorder_int(char *p, int index)
{
    for (int i = 0; i < 2; i++)
    {
        int temp = (int)(*(p + i + index));
        (*(p + i + index)) = (*(p + 3 + index - i));
        (*(p + 3 + index - i)) = temp;
    }
}

void reorder_uint(char *p, int index)
{
    for (int i = 0; i < 2; i++)
    {
        unsigned int temp = (unsigned int)(*(p + i + index));
        (*(p + i + index)) = (*(p + 3 + index - i));
        (*(p + 3 + index - i)) = temp;
    }
}

void reorder_short(char *p, int index)
{
    for (int i = 0; i < 1; i++)
    {
        short int temp = (short int)(*(p + i + index));
        (*(p + i + index)) = (*(p + 1 + index - i));
        (*(p + 1 + index - i)) = temp;
    }
}

void reorder_ushort(char *p, int index)
{
    for (int i = 0; i < 1; i++)
    {
        unsigned short int temp = (unsigned short int)(*(p + i + index));
        (*(p + i + index)) = (*(p + 1 + index - i));
        (*(p + 1 + index - i)) = temp;
    }
}

void reorder_longlong(char *p, int index)
{
    for (int i = 0; i < 4; i++)
    {
        long long int temp = (long long int)(*(p + i + index));
        (*(p + i + index)) = (*(p + 7 + index - i));
        (*(p + 7 + index - i)) = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            b[i] = 4;

        if (a[i] == 1)
            b[i] = 4;

        if (a[i] == 2)
            b[i] = 2;

        if (a[i] == 3)
            b[i] = 2;

        if (a[i] == 4)
            b[i] = 1;

        if (a[i] == 5)
            b[i] = 8;
    }

    for (int i = 0; i < n; i++)
    {
        sum += b[i];
    }

    char *pointer = malloc(sum);
    int index = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] == 0)
        {
            scanf("%d", pointer + index);
            reorder_int(pointer, index);
            index += b[i];
        }

        if (a[i] == 1)
        {
            scanf("%u", pointer + index);
            reorder_uint(pointer, index);
            index += b[i];
        }

        if (a[i] == 2)
        {
            scanf("%hd", pointer + index);
            reorder_short(pointer, index);
            index += b[i];
        }

        if (a[i] == 3)
        {
            scanf("%hu", pointer + index);
            reorder_ushort(pointer, index);
            index += b[i];
        }

        if (a[i] == 4)
        {
            scanf("\n%c", pointer + index);
            index += b[i];
        }

        if (a[i] == 5)
        {
            scanf("%lld", pointer + index);
            reorder_longlong(pointer, index);
            index += b[i];
        }
    }

    // return 0;
    // now we get destination data types and put them in an array
    scanf("%d", &n);
    int c[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        // printf("scan shod");
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
            b[i] = 4;

        if (c[i] == 1)
            b[i] = 4;

        if (c[i] == 2)
            b[i] = 2;

        if (c[i] == 3)
            b[i] = 2;

        if (c[i] == 4)
            b[i] = 1;

        if (c[i] == 5)
            b[i] = 8;

        if (c[i] == 6)
            b[i] = 4;

        if (c[i] == 7)
            b[i] = 8;
    }
    // printf("salam");
    // printf(" %d  %d ", b[0], b[1]);
    index = 0;
    for (int i = 0; i < n; i++)
    {
        // printf(" i=%d \n", i);
        if (c[i] == 0)
        {
            printf("%d\n", *(pointer + index));
            index += b[i];
        }

        if (c[i] == 1)
        {
            printf("%u\n", *(pointer + index));
            index += b[i];
        }

        if (c[i] == 2)
        {
            printf("%hd\n", *(pointer + index));

            index += b[i];
        }

        if (c[i] == 3)
        {
            printf("%hu\n", *(pointer + index));
            index += b[i];
        }

        if (c[i] == 4)
        {
            printf("%c\n", *(pointer + index));
            index += b[i];
        }

        if (c[i] == 5)
        {
            printf("%lld\n", *(pointer + index));

            index += b[i];
        }

        if (c[i] == 6)
        {
            printf("%.2e\n", *(pointer + index));
            index += b[i];
        }

        if (c[i] == 7)
        {
            printf("%.4e\n", *(pointer + index));
            index += b[i];
        }
    }
}