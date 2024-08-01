///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//   Part 1 "Brotherly relationship!"    //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int a = 0, b = 0;	// define a,b
	
	scanf("%d %d", &a, &b);		// Input a & b from the user
	
	unsigned char c = a ^ b;	// In (a XOR b),  the different bits are 1, and the same bits are zero

	// It's enough to count the "1 bits" in variable c
	int n = ( (c & 0b10000000) >> 7 ) +
			( (c & 0b01000000) >> 6 ) +
			( (c & 0b00100000) >> 5 ) +
			( (c & 0b00010000) >> 4 ) +
			( (c & 0b00001000) >> 3 ) +
			( (c & 0b00000100) >> 2 ) +
			( (c & 0b00000010) >> 1 ) +
			( (c & 0b00000001) >> 0 );
	
	printf("%d", n);	// Outputs the n (number of diffrent bits a vs. b)

	return 0;
}