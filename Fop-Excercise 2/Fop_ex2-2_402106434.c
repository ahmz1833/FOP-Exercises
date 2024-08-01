///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//         Part 2 "XO Game!"             //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	int table = 0;	// define input table as int ( no overflow. 999999999 < Integer Max )
	
	scanf("%d", &table);		// Input Table form the user

	/*
		XO Table
	  i11  i12  i13              (Row 1)
	  i21  i22  i23              (Row 2)
	  i31  i32  i33              (Row 3)
	*/
	int row1 = (table / 1000000),
		row2 = (table / 1000) % 1000,
		row3 = (table % 1000);
	
	int i11 = (row1 / 100), i12 = (row1 / 10) % 10, i13 = row1 % 10,
		i21 = (row2 / 100), i22 = (row2 / 10) % 10, i23 = row2 % 10,
		i31 = (row3 / 100), i32 = (row3 / 10) % 10, i33 = row3 % 10;

  /////////////////// Check Winner ///////////////////////
	//______________Check Rows____________________	
	if(i11 == i12 && i12 == i13)		//	First Row
	{
		printf("%d", i11);
	}
	else if(i21 == i22 && i22 == i23)	//	Second Row
	{
		printf("%d", i21);
	}
	else if(i31 == i32 && i32 == i33)	//	Third Row
	{
		printf("%d", i31);
	}
	//______________Check Columns_________________	
	else if(i11 == i21 && i21 == i31)	//	First Column
	{
		printf("%d", i11);
	}
	else if(i12 == i22 && i22 == i32)	//	Second Column
	{
		printf("%d", i12);
	}
	else if(i13 == i23 && i23 == i33)	//	Third Column
	{
		printf("%d", i13);
	}
	//______________Check Diameters_________________
	else if(i11 == i22 && i22 == i33)	//	Main diamater 
	{
		printf("%d", i11);
	}
	else if(i13 == i22 && i22 == i31)	//	Secondary diameter
	{
		printf("%d", i13);
	}
	//______________No Winner_________________
	else
	{
		printf("0");
	}
	return 0;
}