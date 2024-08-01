///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//         Part 7 "Game Chess!"          //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int Wk=0, Bk=0, Bq=0, Br=0;   //2 digits inputs
	int Wk_x=0, Wk_y=0;     // White king coordination
	int Bk_x=0, Bk_y=0, Bq_x=0, Bq_y=0, Br_x=0, Br_y=0;   // Black King/Queen/Rook coordinations

	scanf("%d%d", &Wk, &Bk);   //First Line : Get Kings Coordinations
	scanf("%d", &Bq);          //Second Line : Get Black Queen Coordination
	scanf("%d", &Br);          //Third Line : Get Black Rook Coordination

	// Put coordinations into their variables
	Wk_y = (Wk/10); Wk_x = Wk%10;
	Bk_y = (Bk/10); Bk_x = Bk%10;
	Bq_y = (Bq/10); Bq_x = Bq%10;
	Br_y = (Br/10); Br_x = Br%10;

	if(Wk_x > 8 || Wk_x < 1 || Bk_x > 8 || Bk_x < 1 || Bq_x > 8 || Bq_x < 1 || Br_x > 8 || Br_x < 1 ||
	   Wk_y > 8 || Wk_y < 1 || Bk_y > 8 || Bk_y < 1 || Bq_y > 8 || Bq_y < 1 || Br_y > 8 || Br_y < 1)   // Invlaid Input
	{
		printf("No One!");
		return 0;
	}

	if((Bq_y - Wk_y == Bq_x - Wk_x) ^ (Bq_y - Wk_y == Wk_x - Bq_x)) // Checkmate with Black Queen   /   Diagonal : (Δy=Δx) XOR (Δy=-Δx)
	{
		printf("Queen");
	}
	else if((Bq_y == Wk_y) ^ (Bq_x == Wk_x)) // Checkmate with Black Queen   /   Horiz or Vert : (is same Y)  XOR  (is same X)
	{
		printf("Queen");
	}
	else if((Br_y == Wk_y) ^ (Br_x == Wk_x))  // Checkmate with Black Rook  /  Horiz or Vert : (is same Y)  XOR  (is same X)
	{
		printf("Rook");
	}
	else  // Not Checkmate
	{
		printf("No One!");
	}
	return 0;
}