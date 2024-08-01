///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 3               //
//     Part 8(2) "Stupid Jack Jack!"     //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main(void)
{
    unsigned int n = 0, m = 0;
    scanf("%u %u", &n, &m); // Input n (string length)  and m (number of shifts)

    char string[n+1]; // Declare our string array (string is its name :) not its type)

    int index = 0;
    for(index = 0; index < n; index++) // We must input "n" times, getting alphabetical small letter
    {
        char letter = 0;
        scanf("%c", &letter); // Scan one character
        
        // If we got "not a small alphabet letter"
        if(letter > 'z' || letter < 'a')
        {
            index--; // This is not a acceptable Character for our string! 
            continue;  // We have to scan agian , to get another character instead of it.
        }

        string[index] = letter; // Put the letter in our string :)
    }
    string[index] = 0;

    // First, We Shift All the letters m times. (Rotative)
    // In this stage, Rotative Shift in letters m times not different from m%26 times
    int m_new = m % 26; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m_new; j++)
            string[i] = (string[i] == 'z') ? 'a' : (string[i] + 1);

    // (In each shift, we had not to change one letter (ind) , Now we change back)
    // Because of we shifted m times before,  now we must change back m times :)
    // In this stage, we begin from index=0 and try to change it to 'a' (via back shift)
    for(int i = 0, index = 0; i < m; i++)
    {
        // If we aren't in last index, and the letter is 'a' , goto next letter
        if((string[index] == 'a') && (index < n-1)) { index++; i--; continue; }

        string[index] = (string[index] == 'a') ? 'z' : string[index]-1; // Back Shifting the letter
    }

    // Prints the output
    for(int i = 0; i < n; i++) printf("%c", string[i]);
}