/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		2
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		September 12, 2013           
//
//  FILE:		program01.c        
//
//  DESCRIPTION:	This is a driver for "strappend" and "find_index_of_max" functions
//
//****************************************************************/


# include <stdio.h>
# include "program01.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m" 
#define DEFCOLOR "\033[0m"

void PrintStatus(int status);




void main(void) {
   
   char s1[100], s2[100]; 
   char buffer[100];
   int i = 0, index;
   float test_arr[] = {10.,20.,30.,40.,2,1.3,5.};
   
  
   printf("\n***********************************************\n");
   printf("************   testing find_index_of_max  ****************\n"); 
   printf("***********************************************\n");
  
   printf("The test array is:\n");
   
   for (i=0; i < 7; i++)
   {
   printf("%5d %10.2f\n", i, test_arr[i]);
   }
  
   printf("The index of maximum value in the array: %d\n",index = find_index_of_max(test_arr,7));
   printf("find_index_of_max .... ");
   
   if (index == 3) 
     PrintStatus(1); 
   else 
     PrintStatus(0); 
   printf("\n");
 
 
   printf("\n***********************************************\n");
   printf("************   testing strappend  ****************\n"); 
   printf("***********************************************\n");
  
   printf("Please enter the 1st string: ");
   fgets(s1, 99, stdin);
   i = 0; while (s1[i] != '\0') i++; s1[i-1] = '\0';

   printf("Please enter the 2nd string: ");
   fgets(s2, 99, stdin);
   i = 0; while (s2[i] != '\0') i++; s2[i-1] = '\0';

   printf("This is the 1st string: %s\n",s1);
   printf("This is the 2nd string: %s\n",s2); 
  
   strappend(s1,s2);
   printf("\nThe final attached strings: %s",s1);
   PrintStatus(1); 
   printf("\n************   Done.  ****************\n"); 
  
  
}


/*****************************************************************
//
//  Function name:		PrintStatus  
//
//  DESCRIPTION:		Print the status of the program
//
//  Parameters:			int : 
//				
//
//  Return values:		for any positive input integer, prints a green "[OK]"
//				for any negative or zero value, it prints a red "[error]"
//
//****************************************************************/


void PrintStatus(int status)
{
 if (status > 0)
 { 
   printf(GREEN); 
   printf("\t [OK]\n"); 
   printf(DEFCOLOR);
   
 } 
 else 
 {
   printf(RED);
   printf("\t[error]\n");
   printf(DEFCOLOR);
 }
  
}



