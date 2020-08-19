/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		1
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		September 05, 2013           
//
//  FILE:		Assignment_01.c        
//
//  DESCRIPTION:	This file contains the driver and the user-interface functions 
//			for Homework 1 – the temperature conversion program
//
//****************************************************************/
// To compile the program:
// $ cc -o Assignment_01.x   Assignment_01.c
// $ ./Assignment_01.x
//****************************************************************/




#include <stdio.h>

int	GetTemperature(void);
int	RoundNumber(int number);
float	convertFtoC(int Fahrenheit);
void	PrintTable(int Fahrenheit_temp);


int	main(void)
{
	int max_temperature;

	max_temperature = GetTemperature();

	PrintTable(max_temperature);

	printf("\n");
	return 0;
}

// The main body of program ends here ...



/*****************************************************************
//
//  Function name:		GetTemperature   
//
//  DESCRIPTION:		A userinterface function
// 				This function obtains the values of the maximum temperature
// 				in Fahrenheit from the user
//
//  Parameters:			no input parameter 
//
//  Return values:		(int) the maximum temperature value which is rounde up to 
// 				the next multiple of 5 number
//
//****************************************************************/

int	GetTemperature(void)
{
	int temperature = 0;
	int scan_error;
	int round_temperature = 0;
	char buffer[100];
	
	do
	{

	  printf("\nPlease enter a positive integer number \nas the maximum temperature in Fahrenheit (F > 0): ");

	  // here, user can enter any string, then we can check if we have valid integer number using sscanf
	  // sscanf converts the string to an integer number if it contains it 
	  
	  fgets(buffer, 99, stdin);
	  
	  // using the "sscanf" we make sure that the buffer is cleared out after the scanning
	  // process and we can ask the user to enter the valid number as many time as we need
	  // within the loop. 
	 
	  scan_error = sscanf(buffer, "%d", &temperature);
	  
	  // scan_error = 0 means that the inout parameter is not an integer number
	  
	  if (scan_error == 0 || temperature <= 0 ) 
	  {
	      printf("\n   *** Warning ****\n");
	  }

	} while(scan_error == 0 || temperature <= 0);
	
	round_temperature = RoundNumber(temperature);
	printf("\nThe next multiple of 5 to %d is: %d\n", temperature, round_temperature);
	return round_temperature;
}


/*****************************************************************
//
//  Function name:		RoundNumber   
//
//  DESCRIPTION:		rounding up the input number to the next 
// 				multiple of 5 number
//
//  Parameters:			number (int): an integer number which is to be rounded up 
//
//  Return values:		(int): the rounded numbr
//
//****************************************************************/

int	RoundNumber(int number)
{
	// Rounding up the input number to the next multiple of 5

	number -= 1;
	return number + (5 - number % 5);
}


/*****************************************************************
//
//  Function name:		convertFtoC   
//
//  DESCRIPTION:		A function to conver the temperature from Fahrenheit to Celsius
//
//  Parameters:			(int): the temperature in Fahrenheit 
//
//  Return values:		(float): the temperature in Celsius 
//
//****************************************************************/

float	convertFtoC(int Fahrenheit)
{
	float Celsius = (Fahrenheit - 32.) * 5. / 9.;
	return  Celsius;
}


/*****************************************************************
//
//  Function name:		PrintTable   
//
//  DESCRIPTION:		This function prints in two columns the temperatures 
// 				in Fahrenheit and Celsius. 
// 				The first column would be the temperatures in Fahrenheit
// 				with the incremtn of 5 starting from 0. The secound column 
// 				would be the corresponding Celsius temperatures.
//
//  Parameters:			(int) the input temperature in Fahrenheit 
//
//  Return values:		No output. It print out the results on the screen 
//
//****************************************************************/

void	PrintTable(int Fahrenheit_temp)
{
	int index = 0;
	printf("\n");
	printf("    ***********************************************\n");
	printf("     Temperature in F\t\tTemperature in C\n");
	printf("    ***********************************************\n");
	
	do
	{
	  printf("          %d\t\t\t%.2f\n", index, convertFtoC(index));
	  index += 5;
	} while (index <= Fahrenheit_temp);
	printf("    ***********************************************\n");
}

// The end of the code.
