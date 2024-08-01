///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//     Part 3 "Schedule patients!"       //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int masoud=0, saeed=0;
	scanf("%d %d", &masoud, &saeed); // Input masoud and saeed schedule date

	if(masoud > 31 || masoud <=0 || saeed > 31 || saeed <= 0)   // if any date are invalid
	{
		printf("invalid date");
		return 0;
	}

	masoud = masoud ^ saeed;          // a = (a XOR b)    -> means that a=(different bits a vs. b)
	saeed = masoud ^ saeed;           // b = (a XOR b) = ( (a_orig XOR b_orig) XOR b_orig ) = a_orig
	masoud = masoud ^ saeed;          // a = (a XOR b) = ( (a_orig XOR b_orig) XOR b) = ((a_orig XOR b_orig) XOR a_orig) = b_orig
	/* Successfully Swaped 2 variable with XOR! AHMZ:) */

	printf("%d\n%d", masoud, saeed);
	return 0;
}