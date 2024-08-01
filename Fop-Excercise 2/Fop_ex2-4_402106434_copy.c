///////////////////////////////////////////
//         In the Name of Allah          //
//     Fundamentals of Programming       //
//             Excercise 2               //
//   Part 4 "Forgiveness of Doctors!"    //
//     By AmirHossein MohammadZadeh      //
//       Student Code : 402106434        //
///////////////////////////////////////////

#include <stdio.h>

int main()
{
	char h1=0, h2=0, m1=0, m2=0;
	int total_minutes = 0, h=0,m=0;
	scanf("%d", &total_minutes);
	h = (total_minutes / 60) % 24;
	m = total_minutes % 60;

	/////////////////// Hour Dahgan //////////////////
	switch (h/10)
	{
		case 0:
			h1='z';
			break;
		case 1:
			h1='o';
			break;
		case 2:
			h1='t';
			break;
	}
	/////////////////// Hour Yekan //////////////////
	switch (h%10)
	{
		case 0:
			h2='z';
			break;
		case 1:
			h2='o';
			break;
		case 2:
			h2='t';
			break;
		case 3:
			h2='t';
			break;
		case 4:
			h2='f';
			break;
		case 5:
			h2='f';
			break;
		case 6:
			h2='s';
			break;
		case 7:
			h2='s';
			break;
		case 8:
			h2='e';
			break;
		case 9:
			h2='n';
			break;
	}
	/////////////////// Minute Dahgan //////////////////
	switch (m/10)
	{
		case 0:
			m1='z';
			break;
		case 1:
			m1='o';
			break;
		case 2:
			m1='t';
			break;
		case 3:
			m1='t';
			break;
		case 4:
			m1='f';
			break;
		case 5:
			m1='f';
			break;
	}
	/////////////////// Minute Yekan //////////////////
	switch (m%10)
	{
		case 0:
			m2='z';
			break;
		case 1:
			m2='o';
			break;
		case 2:
			m2='t';
			break;
		case 3:
			m2='t';
			break;
		case 4:
			m2='f';
			break;
		case 5:
			m2='f';
			break;
		case 6:
			m2='s';
			break;
		case 7:
			m2='s';
			break;
		case 8:
			m2='e';
			break;
		case 9:
			m2='n';
			break;
	}
	/////////////////// Print //////////////////
	printf("  .-----------------------===------------------------.\n\
  :o  ______________________________________________  o:\n\
  ;   :                                            :   ;\n\
  `.  `.                                          .'  .'\n\
   :   :                                          :   :\n\
   `.  `.                 TIME???                .'  .'\n\
    :   :                  %c%c:%c%c                  :   :\n\
    `.  `.                                      .'  .'\n\
     :   :                                      :   :\n\
     `.  `.                                    .'  .'\n\
      :   :                                    :   :\n\
      `.  `.                                  .'  .'\n\
       :   :__________________________________:   :\n\
       `.                                        .'\n\
        '-------------|  |-----|  |--------------'\n\
       .\"\"\"\"\"\"\"\"\"\"\"\"\"\"|  |\"\"\"\"\"|  |\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n\
       |  ()          '-----------'      o   ()  |\n\
       |   ___________________________________   |\n\
       |  :__|__|__|__|__|__|__|__|__|__|__|__:  |\n\
       |  |___|__|__|__|__|__|__|__|__|__|__|_|  |\n\
       |  |__|_|__|__|__|__|__|__|__|__|__|___|  |\n\
       |  |___|__|__|__|__|__|__|__|__|__|____|  |\n\
       |  |____|__|__|__|__|__|__|___|__|__|__|  |\n\
       |  :___|__|___________________|__|__|__:  |\n\
       |                                         |\n\
       |             .-------------.             |\n\
       |             |             |             |\n\
       |             |             |             |\n\
       |             |_____________|             |\n\
       |             |             |             |\n\
       |             |             |             |\n\
       |             '.___________.'             |\n\
       |                   ___                   |\n\
       '-----------------------------------------'\n", h1, h2, m1, m2);

	return 0;
}