#include "stdio.h"
// #include <conio.h>

// int Password[2] = {0};
// int Number[2] = {0};
// int Password = 0;
// int Number = 0;
char Number[3] = "";

PUBLIC void startGuessNumGame(int fd_stdin, int fd_stdout)
{
	int price=58;
	int readCount = 0;
	int number = 0;
	// ,i=0;
	printf("============================================\n");
	printf("        This is a Number Guess Game         \n");
	printf("============================================\n");
	// while( Password != 1234 )
	// {
	// 	if( i >= 3 )
	// 		return;
	// 	i++;
	// 	printf("Please input Password: \n");
	// 	read(fd_stdin, Password, 4);
	// 	// scanf("%d",&Password);
	// }

	// i=0;
	while( Number!=price )
	{
		do{
			printf("Please input a number between 1 and 100: \n");
			readCount = read(fd_stdin, Number, 4);
			// scanf("%d",&Number);
			// printf("%d\n", readCount);
			if (readCount == 1) {
				printf("Your input number is %c \n",Number[0]);
				number = Number[0] - '0';
			}
			else if (readCount == 2) {
				printf("Your input number is %c%c \n", Number[0], Number[1]);
				number = (Number[0] - '0') * 10 + Number[1] - '0';
			}
			else if (readCount == 3) {
				printf("Your input number is %c%c%c \n", Number[0], Number[1], Number[2]);
				number = 100;
			}
			// printf("Your input number is %d \n",Number);
		}while( !(number>=1 && number<=100) );
		if( number >= 90 )
		{
			printf("Too Bigger! Press any key to try again!\n");
		}
		else if( number >= 70 && number < 90 )
		{
			printf("Bigger!\n");
		}
		else if( number >= 1 && number <= 30 )
		{
			printf("Too Small! Press any key to try again!\n");
		}
		else if( number > 30 && number <= 50 )
		{
			printf("Small! Press any key to try again!\n");
		}
		else
		{
			if( number == price )
			{
				printf("OK! You are right! Bye Bye!\n");
				return;
			}
			else if( number < price )
			{
				printf("Sorry,Only a little smaller! Press any key to try again!\n");

			}
			else if( number > price )
				printf(" Sorry, Only a little bigger! Press any key to try again!\n");
		}
	}
}
