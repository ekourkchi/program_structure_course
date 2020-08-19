/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		8
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		November 2, 2013           
//
//  FILE:		program2.c        
//
//  DESCRIPTION:	This file contains the interface for HW08.cpp functions - the temperature conversion program
//
//****************************************************************/
/** 
// 1) In your consule run the following command before running the java program
//    $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
// 2) To run the program type:
//    $ java HW08
// 
*/

import java.util.InputMismatchException;
import java.util.Scanner;



public class HW08 
{
    
    
    
    static
    {
       System.loadLibrary("MyCppLibrary");
    }
   
    public native static int RoundNumber(int number);
    public native static float  convertftoC(int Fahrenheit);
    

    
/*****************************************************************
//
//  Function name:		main 
//
//  DESCRIPTION:		Main function, it gets the temperature form user in Fahrenheit
//				and print the converted temperatures in Celsius
//
//  Parameters:			no input
//
//  Return values:		no output
//
//****************************************************************/

    public static void main(String [] args)
    {
       
       int maxTemperature = 0;
       Scanner scan = new Scanner(System.in);
       boolean exception;
          
          do 
          {
             exception = false;
             System.out.printf("\nPlease enter a positive integer number \nas the maximum temperature in Fahrenheit (F > 0): ");
             

             
              try 
              {			// get the start position
              
		maxTemperature = scan.nextInt();
		
	      } 
	      catch(InputMismatchException ex) 
	      {	// Checking the exception for anything other than an integer number
		System.out.println("\n\nError: You did not enter an integer number.");
		exception = true;
	      }
              
              
              
              if (maxTemperature <= 0) 
              {
                 System.out.println("\nPlease enter a positive number.");  
                 exception = true;             
              }
          
           
              scan.nextLine(); // empty the input buffer
              
          } while(exception);
    
    
          int round_temperature = HW08.RoundNumber(maxTemperature);
          
          System.out.println("\nThe next multiple of 5 to 20 is: " +  Integer.toString(round_temperature));
          
          printTable(round_temperature);
    
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

    private static void printTable(int Fahrenheit_temp)
    {
      
        int index = 0;
	System.out.printf("\n");
	System.out.printf("    ***********************************************\n");
	System.out.printf("     Temperature in F\t\tTemperature in C\n");
	System.out.printf("    ***********************************************\n");
	
	do
	{
	
	  System.out.printf(" %15d  %25.2f\n", index, convertftoC(index));
	  index += 5;
	  
	} while (index <= Fahrenheit_temp);
	
	System.out.printf("    ***********************************************\n");
    
    
    }



/****************************************************************/

} /** The end of main class*/

