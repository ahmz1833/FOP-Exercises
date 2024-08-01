///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//  Part 5 "Dismissal of Mrs.Shirzad!"   //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int d = 0, m = 0, wd = 0, _D = 0, _M = 0;
	int difference = 0, _WD = 0;

	scanf("%d%d -> %d", &d, &m, &wd);			/// Scan first line (Today)
	scanf("%d%d", &_D, &_M);	/// Scan second line (Target)

	// If any invalid input
	if( (d>30 || d<=0) || (_D>30 || _D<=0) ||
		(m>12 || m<=0) || (_M>12 || _M<=0) ||
		(wd>=7 || wd<0))   
	{
		printf("Invalid Date!");
		return 0;
	}

	difference = (_M-m)*30 + (_D-d);  // The day difference between today and target (can be positive or negative)
	_WD = (difference + wd) % 7;      // Target Weekday ! (solve with mod 7 :)
	if(_WD<0) _WD += 7;               // If the Target Weekday is negative, Add 7 to it , to become positive!

	switch (_WD)
	{
		case 0:
			printf("Saturday");
			break;
		case 1:
			printf("Sunday");
			break;
		case 2:
			printf("Monday");
			break;
		case 3:
			printf("Tuesday");
			break;
		case 4:
			printf("Wednesday");
			break;
		case 5:
			printf("Thursday");
			break;
		case 6:
			printf("Friday");
			break;
	}
	return 0;
}