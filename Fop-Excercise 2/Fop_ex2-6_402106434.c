///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//       Part 6 "Strange Patient!"       //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int x1=0,x2=0,x3=0,x4=0,
		y1=0,y2=0,y3=0,y4=0;
	int S_ABC=0, S_ABD=0, S_ACD=0, S_BCD=0;

	scanf("%d%d", &x1, &y1);  // Point 'A'
	scanf("%d%d", &x2, &y2);  // Point 'B'
	scanf("%d%d", &x3, &y3);  // Point 'C'
	scanf("%d%d", &x4, &y4);  // Point 'D'

	// For Debug
	// printf("A=[%d,%d]\tB=[%d,%d]\tC=[%d,%d]\tD=[%d,%d]\n", x1,y1, x2,y2, x3,y3, x4,y4);

	// Calculate Areas with cross product vectors!
	S_ABC = (x3-x1)*(y2-y1)-(y3-y1)*(x2-x1);  // |AC x AB| is 2*( Area of Triangle 'ABC' )
	S_ABD = (x4-x1)*(y2-y1)-(y4-y1)*(x2-x1);  // |AD x AB| is 2*( Area of Triangle 'ABD' )
	S_ACD = (x3-x1)*(y4-y1)-(y3-y1)*(x4-x1);  // |AC x AD| is 2*( Area of Triangle 'ACD' )
	S_BCD = (x3-x2)*(y4-y2)-(y3-y2)*(x4-x2);  // |BC x BD| is 2*( Area of Triangle 'BCD' )

	if(S_ABC < 0) S_ABC *= -1; // Absolute
	if(S_ABD < 0) S_ABD *= -1; // Absolute
	if(S_ACD < 0) S_ACD *= -1; // Absolute
	if(S_BCD < 0) S_BCD *= -1; // Absolute

  ////////////////// Check Point 'A' /////////////////////
	if(S_ABC+S_ABD+S_ACD == S_BCD) ///  Point 'A' is within the Triangle 'BCD' 
	{
		printf("0");      // Not Convex !
		return 0;
	}
  ////////////////// Check Point 'B' /////////////////////
	else if(S_ABC+S_ABD+S_BCD == S_ACD) ///  Point 'B' is within the Triangle 'ACD' 
	{
		printf("0");      // Not Convex !
		return 0;
	}
  ////////////////// Check Point 'C' /////////////////////
	else if(S_ABC+S_ACD+S_BCD == S_ABD) ///  Point 'C' is within the Triangle 'ABD' 
	{
		printf("0");      // Not Convex !
		return 0;
	}
  ////////////////// Check Point 'D' /////////////////////
	else if(S_ABD+S_ACD+S_BCD == S_ABC) ///  Point 'D' is within the Triangle 'ABC' 
	{
		printf("0");      // Not Convex !
		return 0;
	}
  ////////////////// Else : Is Convex! /////////////////////
	else
	{
		printf("1");
		return 0;
	}
}