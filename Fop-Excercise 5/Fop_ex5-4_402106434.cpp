///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 5               //
//          Part 4 "Decoding!"           //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
//#include "grader.h"

// A Useful Macro for Debug :)
#define _DEBUG_(fmt,val1,val2,val3)  printf("\n\tDEBUG (Line %d): ", __LINE__); printf(fmt,val1, val2,val3)

// Abreviations
#define uint unsigned int
#define ullong unsigned long long
#define uchar unsigned char

// Useful code snippet macro for getInput from char* , ordered and countered
#define getInput(input,counter,fmt,dest,end) \
    sscanf(input+counter, fmt, dest); \
    while(*(input+(++counter)) != end) if(*(input+counter) == '\0') break;

// Used for convert a one-letter-character to a number digit
#define detNumber(numChar)  ((numChar >= '0' && numChar <= '9') ? (numChar - '0') : \
                            ((numChar >= 'A' && numChar <= 'Z') ? (numChar - 'A' + 10) : \
                            ((numChar >= 'a' && numChar <= 'z') ? (numChar - 'a' + 10) : 0)))

// A function for converting a string number in base n -> to a real literal number
ullong convertBase(char* number, uint base)
{
    ullong finalNumber = 0;
    // Iterate String , to reach '\0'
    for(int i = 0; *(number+i) != '\0'; i++)
    {
        finalNumber *= base;
        finalNumber += detNumber(*(number+i));
    }
    return finalNumber;
}

/**** Function decryption : Important and main of program ****/
void decryption(char *input)
{
    unsigned int N = 0, inputIndex = 0;
    getInput(input, inputIndex, "%u", &N, '\n'); // Scan N from input string

    // Iterate n times -> get N lines from string, and process each line after scanning it
    for(uint i = 0; i < N; i++)
    {
        uint base = 0, byteCount = 0, level = 0;
        void* address = 0; // Declare address as void*
        char str_address[64]; // Declare an array to scan ADDRESS in String format
        ullong finalResult = 0; // Final Result -> will be maked

        // Scan the inputs in line -> put to their variables
        getInput(input, inputIndex, "\n%u", &base, '.');
        getInput(input, inputIndex, ".%u", &byteCount, '.');
        getInput(input, inputIndex, ".%u", &level, '.');

        // Scan the Address in String format (because we have to change its base)
        getInput(input, inputIndex, ".%s", str_address, '\n');

        // Covert the base of Address_string -> and cast it to void*
        address = (void *) convertBase(str_address, base);

        // Decrypt !!!   Reduce level pointer to 1 !!!
        for(uint j = 0; j < level-1; j++)
            address = *((void **) address);
        
        // Construct the finalResult (itrate over the bytes and put them in result)
        for(uint j = 0; j < byteCount; j++)
            finalResult |= (ullong) *((uchar *) address+j) << (j*8);
        
        // Prints the finalResult in current line
        printf("%llu\n", finalResult);
    }
}

/***** Main Function For Testing the program :)  ******/
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
