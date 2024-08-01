///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//        Part 3 "Untimely Call!"        //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    char S[1000000];  //  1≤|S|≤1000000
    
    // Input loop: we receive input, until we get CR or LF or NULL (End of Str)
    for(int i = 0 ;; i++)
    {
        scanf("%c", &S[i]);

        // If we got CR'\r' or LF'\n' or NULL'\0'
        if(S[i]=='\r' || S[i]=='\n' || S[i]=='\0')
        {
            S[i] = '\0'; //set to null (end of string)
            break; // break the input loop
        }
    }

    //Process & Print Loop: Process, until we arrive to '\0'
    for(int i = 0; S[i] != 0; i++)
    {
        switch(S[i])
        {
            int letter_index;

            case ' ': // Space
                printf("00 ");
                break;
            
            // All Numbers :
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                printf("%c ", S[i]); // Print itself
                break;

            // Else ( logically, it is a letter ! )
            default:
                letter_index = (S[i]-'a'); // zero-based index of alphabetical letter

                // We Process in mod 3 !! :)
                // what we print : (index/3 + 1)
                // how many times we print : (index%3 + 1)
                for(int j = 0; j <= (letter_index % 3) + 1; j++)
                   printf("%d", (letter_index / 3) + 1); //Print without space

                // Print the space after inner loop (nokia key sequence!)
                printf(" ");
        }
    }

    return 0;
}