/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		4
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		September 29, 2013           
//
//  FILE:		hw04.c        
//
//  DESCRIPTION:	This file contains the Driver and User Interface 
//			to test the reading and writing functions for [Homework 4] 
//
//****************************************************************/
#define RED "\033[1;31m"
#define GREEN "\033[1;32m" 
#define BLUE "\033[1;34m"
#define DEFCOLOR "\033[0m\033[K"


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "account.h"
# include "databaseio.h"


int main(int argc, char *argv[])
{
   
  struct account bankone[5];
  int numcustomers = 5, index, bool;
  char filename[30], nextcustomer[10];
    
   
   if (argc == 2 && (!strcmp(stringlower(argv[1]), "read") || !strcmp(stringlower(argv[1]), "-r")))
   {
	      printf("\n Enter the filename to be imported (string): ");
	      scanf("%s", filename);
	    
	      printf("\n ");
	      printf("\n Reading the file: \"%s\" \n", filename);
	      printf("\n ................................... \n");
	    
		  if (readfile(bankone, &numcustomers, filename))
		  {
		    printf(RED); 
		    printf("\n *************************************");
		    printf("\n The file \"%s\" can not be read.\n", filename);
		    printf(" There is either no such file\n or it has a wrong format.");
		    printf("\n *************************************\n");
		    printf(DEFCOLOR);
		    return 1;
		  }
	  
	      printf(" The imported records \n");
	      printf(" Record.no:  Field.name:  \"Field.value\" \n");
	      printf(" ................................... \n");
	      
		  for (index=0;index<numcustomers;index++)
		  {
		    printf("\n %d: Name: \"%s\"\n", index+1, bankone[index].name);
		    printf(" %d: AccountNo: \"%d\"\n",index+1,  bankone[index].accountno);
		    printf(" %d: Balance: \"%f\"\n\n", index+1, bankone[index].balance);
		  }
	    
	      printf(GREEN);
	      printf("\n *************************************");
	      printf("\n The file \"%s\" was imported successfully.\n", filename);
	      printf(" Number of records: %d", numcustomers);
	      
		  if (numcustomers == 0) 
		  {
		    printf(RED);
		    printf("\n No record in this file or wrong format.", numcustomers);
		    printf(DEFCOLOR);
		  }
	      
	      printf("\n *************************************\n\n");
	      printf(DEFCOLOR);
  
    return 0;
    }
 
 
    if (argc == 2 && ( !strcmp(stringlower(argv[1]), "write") || !strcmp(stringlower(argv[1]), "-w")))
    {
	      printf("\n\n Testint the Writing function.\n Filling the database ... \n\n");
	      numcustomers = 0;
	      
	      do 
	      {
		bool = 0;
		printf(" ................................... \n");
		printf("\n Getting the record #%d\n", numcustomers+1);
		
		printf(" Enter Name (string): ");
		scanf("%s", bankone[numcustomers].name);
		
		printf(" Enter account number (integer): ");
		scanf("%d", &bankone[numcustomers].accountno);
		
		printf(" Enter account balance (float): ");
		scanf("%f", &bankone[numcustomers].balance);
	      
		numcustomers ++;
	
		if (numcustomers < 5 ) 
		{
		  printf("\n\n Another customer? (Y/N): ");
		  scanf("%s", nextcustomer);
		
		  if (numcustomers < 5 && (!strcmp(stringlower(nextcustomer), "y") || 
                    !strcmp(stringlower(nextcustomer), "yes")))
		      bool = 1;
		  } 
		  else 
		    printf("\n You reached the maximum number of records.\n");
		
		
	      } while(bool);
	      

	      printf("\n Enter the name of output file: ");
	      scanf("%s", filename);
	      printf("\n ...................................");
	    
	      printf("\n Writing the file: \"%s\" \n", filename);
	      printf(" ................................... \n");
	    

	      if (writefile(bankone, numcustomers, filename))
	      {
		  printf(RED); 
		  printf("\n *************************************");
		  printf("\n Error in writing \"%s\" \n", filename);
		  printf(" *************************************\n\n");
		  printf(DEFCOLOR);
	      return 1;  
	      }
	  
	      printf(GREEN);
	      printf("\n *************************************");
	      printf("\n The file \"%s\" was created successfully.\n", filename);
	      printf(" Number of records: %d", numcustomers);
	      printf("\n *************************************\n\n");
	      printf(DEFCOLOR);
       
    return 0;
    }

    
    
  // In the case of wrong arguments
  printf("\n\n Usage: hw04 [OPTION] ");
  printf("\n\n *** Mandatory Options *** ");
  printf("\n\n -w, write");
  printf("\n   In this mode, the writing function would be tested and");
  printf("\n   the user would be prompted to enter the records manually.");
  printf("\n\n -r, read");
  printf("\n   In this mode, use would be asked to enter the file name and ");
  printf("\n   this program will try to import the file into the database.");
  printf("\n   At the end the imported data would be displayed.");
  printf("\n\n");

  return 1;
 
}

/*****************************************************************
//
//  Function name:		StringColorPrint  
//
//  DESCRIPTION:		a colorful version of the printf
//				This function uses "printf" 
//				** This is not still completed, under development
//
//  Parameters:			char *string: The pointer to the string that would be displayed
//				char color[]: the color code of the displayed string
//
//  Return values:		No output.
//
//****************************************************************/

void StringColorPrint(char *string, char color[])
{ 
  
 if(color == "red") 
 {
   printf(RED);
   printf("%s", string); 
   printf(DEFCOLOR);
 }
  
  
 if(color == "green") 
 {
   printf(GREEN);
   printf("%s", string); 
   printf(DEFCOLOR);
 }
   
   
  if(color == "blue") 
 {
   printf(BLUE);
   printf("%s", string); 
   printf(DEFCOLOR);
 }
 
}

//****************************************************************/








