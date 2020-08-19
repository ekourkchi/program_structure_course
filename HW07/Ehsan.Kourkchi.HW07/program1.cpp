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
//  DATE:		November 24, 2013           
//
//  FILE:		program1.c        
//
//  DESCRIPTION:	This file contains the driver and the user-interface functions 
//			for Homework 1 – the temperature conversion program
//
//****************************************************************/

#include <iostream>
using namespace std;
#include <iomanip>      // std::setprecision
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int	GetTemperature(void);
int	RoundNumber(int number);
void    convertftoC(int, float &);
void	PrintTable(int Fahrenheit_temp);


int	main(void)
{
  

	int max_temperature;

	max_temperature = GetTemperature();

	PrintTable(max_temperature);
        
  return 0;
}
/*
// The main body of program ends here ...


/*




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

	  cout << "\nPlease enter a positive integer number \nas the maximum temperature in Fahrenheit (F > 0): ";

	  // here, user can enter any string, then we can check if we have a valid integer number 
	  
	  cin.getline (buffer, 100);
	  
	  temperature = atoi(buffer);
	  scan_error = temperature;
	  
	  // scan_error = 0 means that the inout parameter is not an integer number
	  
	  if (scan_error == 0 || temperature <= 0 ) 
	  {
	      cout << "\n   *** Warning ****\n";
	  }

	} while(scan_error == 0 || temperature <= 0);
	
	round_temperature = RoundNumber(temperature);
	cout << "\nThe next multiple of 5 to " <<  temperature << " is: " << round_temperature << "\n" ;
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
//  Function name:		convertftoC   
//
//  DESCRIPTION:		A function to conver the temperature from Fahrenheit to Celsius
//
//  Parameters:			(int Fahrenheit): the temperature in Fahrenheit 
// 				(float &Celsius): the converted temperature
//
//  Return values:		no output
//
//****************************************************************/

void  convertftoC(int Fahrenheit, float &Celsius)
{
	Celsius = (Fahrenheit - 32.) * 5. / 9.;
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
	float celsius;
	cout << "\n";
	cout << "    ***********************************************\n";
	cout << "     Temperature in F\t\tTemperature in C\n";
	cout << "    ***********************************************\n";
	
	do
	{ 
	  convertftoC(index, celsius);
	  cout << setw(15) << index << "\t\t\t" << setw(10) << setprecision(2) << fixed << celsius << "\n" ;
	  index += 5;
	} while (index <= Fahrenheit_temp);
	cout << "    ***********************************************\n";
}

// The end of the code.*/*/
