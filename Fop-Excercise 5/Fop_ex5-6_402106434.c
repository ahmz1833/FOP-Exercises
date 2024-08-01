///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//     Part 6 "Mr. Waternoose Hack!"     //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

// Abreviations
#define uint unsigned int
#define ushort unsigned short
#define llong long long
#define uchar unsigned char

/* Define types codes*/

#define TYPE_INT    0
#define TYPE_UINT   1
#define TYPE_SHORT  2
#define TYPE_USHORT 3
#define TYPE_CHAR   4
#define TYPE_LONG   5
#define TYPE_FLOAT  6
#define TYPE_DOUBLE 7

/* Number of bytes for each code of datatype */
const uint  NUMBER_OF_BYTES[8] = {4,4,2,2,1,8,4,8};

/* Convert Big Endian bytes to Little Endian */
void revertBytes(void * bytes, int n);

/* Get input in type format of 'type' , and assume it is big endian */
void getInputBigEndian(void* dest, uint type);

/* Print the data in type format of 'type' */
void printLittleEndian(void* src, uint type);

/* Our main function */
int main()
{
    uint n = 0;
    uint *types;

    // Scan the number of primary(read) types
    scanf("%u", &n);
    types = (uint*) malloc(n * sizeof(uint));

    uint totalByteCount = 0;
    for(int i = 0; i < n; i++)
    {
        // Get the type code
        scanf("%u", types+i);
        totalByteCount += NUMBER_OF_BYTES[*(types+i)];
    }

    // Allocate memory to simulate the memory of mr. waternoose Laptop!!
    void* memoryContent = malloc(totalByteCount);
    uint memIdx = 0;

    // Get n data  (in specified format) and build the memory content structure
    for(int i = 0; i < n; i++)
    {
        // get the input in BigEndian and put it in memIdx index
        getInputBigEndian(memoryContent+memIdx, *(types+i));
        // Increament memory index by number of bytes of this datatype
        memIdx += NUMBER_OF_BYTES[*(types+i)];
    }

    // Scan the number of final (actual) datatypes
    scanf("%u", &n);
    types = (uint *) malloc(n * sizeof(uint));

    // Scan the final datatype codes, and at the same time
    // print Final Datatypes in littleEndian Format (Without Change)
    memIdx = 0;
    for(int i = 0; i < n; i++)
    {
        // Scan the type code
        scanf("%u", types+i);
        // print data without change (normal)
        printLittleEndian(memoryContent+memIdx, *(types+i));
        // increament the memory index by number of bytes in this datatype
        memIdx += NUMBER_OF_BYTES[*(types+i)];
    }
    
    return 0;
}

/* Print the data in type format of 'type' */
void printLittleEndian(void* src, uint type)
{
    switch (type)
    {
        case TYPE_INT:
            printf("%d", *((int *) src));
            break;
        case TYPE_UINT:
            printf("%u", *((uint *) src));
            break;
        case TYPE_SHORT:
            printf("%hi", *((short *) src));
            break;
        case TYPE_USHORT:
            printf("%hu", *((ushort *) src));
            break;
        case TYPE_CHAR:
            printf("%c", *((char *) src));
            break;
        case TYPE_LONG:
            printf("%lld", *((llong *) src));
            break;
        case TYPE_FLOAT:
            printf("%.2e", *((float *) src));
            break;
        case TYPE_DOUBLE:
            printf("%.4e", *((double *) src));
            break;
    }
    printf("\n");
}

/* Get input in type format of 'type' , and assume it is big endian */
void getInputBigEndian(void* dest, uint type)
{
    switch (type)
    {
        case TYPE_INT:
            scanf("%d", (int *) dest);
            break;
        case TYPE_UINT:
            scanf("%u", (uint *) dest);
            break;
        case TYPE_SHORT:
            scanf("%hi", (short *) dest);
            break;
        case TYPE_USHORT:
            scanf("%hu", (ushort *) dest);
            break;
        case TYPE_CHAR:
            scanf("\n%c", (char *) dest);
            break;
        case TYPE_LONG:
            scanf("%lld", (llong *) dest);
            break;
    }
    // Convert Big endian to Little endian
    revertBytes(dest, NUMBER_OF_BYTES[type]);
}

/* Convert Big Endian bytes to Little Endian */
void revertBytes(void * bytes, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        // Swap between Start and End
        *((uchar *) bytes+i) = *((uchar *) bytes+i) ^ *((uchar *) bytes+n-1-i);
        *((uchar *) bytes+n-1-i) = *((uchar *) bytes+i) ^ *((uchar *) bytes+n-1-i);
        *((uchar *) bytes+i) = *((uchar *) bytes+i) ^ *((uchar *) bytes+n-1-i);
    }
}