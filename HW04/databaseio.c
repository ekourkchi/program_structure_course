# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "account.h"
# include "databaseio.h"


/*****************************************************************
//
//  Function name:		writefile  
//
//  DESCRIPTION:		a function to write a database with 3 fields into a file 
//				If the file is previously available, it would be overwritten
//
//  Parameters:			struct account accarray[]: the database in a form of array of structure. The array name would be pass here
//				int numcust: The number of bank customers which must be equal or less than the number of array elements
//				char filename[]: The name of the file which will be created.
//
//  Return values:		int: = 0 if the file is successfully created. = 1 in the case of error.
//
//****************************************************************/

int writefile(struct account accarray[ ], int numcust, char filename[ ])
{
  
  FILE *outputfile;
  int index;

  outputfile = fopen(filename, "w");
  if (outputfile == NULL)
  {
     return 1;
  }
    
  fprintf(outputfile, "# The list of the bank customers. \n\n");

  for (index=0; index<numcust; index++)
  {
    
      fprintf(outputfile, " Name: %s\n", accarray[index].name);
      fprintf(outputfile, " AccountNo: %d\n", accarray[index].accountno);
      fprintf(outputfile, " Balance: %f\n\n", accarray[index].balance);
  }
  
  
  fclose(outputfile);
  return 0;
}

/*****************************************************************
//
//  Function name:		readfile  
//
//  DESCRIPTION:		a function to read from a file of data and import it into a database with 3 fields
//				
//  Parameters:			struct account accarray[]: the database in a form of array of structure. The array name would be pass here
//				int *numcust: The pointer to the variable whic holds the 
//				number of bank customers which must be equal or less than the number of array elements
//				If the number of records in the input file is less than *numcust, then the number of imported records would be pass
//				char filename[]: The name of the file which will be imported.
//				
//				The input file format:
//				Each record have a keyword which ends with a ":" or without it.
//				The keywords are ad following: (they are NOT even case-sensitive)
//
//				Name:
//				AccountNo:
//				Balance:
//
//				Any other line of the file which does not follow this keyword formatting would be ignored.
//				The field value after any keyword can be attached to it or sperated by spaces (no matter how many space)
//				
//				This function can pretty much handle any wrong input format to import as much as possible into the databse.
//				So, it is well prepared for most of the strange circumstances. Please note that in this version each line of the input text cannot 
//				be bigger than 2000 charachter size, otherwise the program crashes.
//
//  Return values:		int: = 0 if the file is successfully created. = 1 in the case of error.
//
//
//****************************************************************/

int readfile(struct account accarray[ ], int * numcust, char filename[ ])
{
  
  FILE *inputfile;
  char readstring1[1000], readstring2[1000], test_char, address_st[100];
  int i, j, k, check, numrecords, boolean, counter;

  inputfile = fopen(filename, "r");
  if (inputfile == NULL)
  {
     return 1;
  }
 
  numrecords = 0;
  
  // i, j, k are cecking variables. If a new record is created, they are all set to zero. 
  // If any of them become 2, then a new record would be generated.
  i = 0;  
  j = 0;  
  k = 0;
  
  while(!readfield2string(inputfile,  readstring1,  readstring2, 25) && numrecords < *numcust) 
  {
    
    if (!strcmp(stringlower(readstring1), "address") || !strcmp(stringlower(readstring1), "address:")) 
    {
      
      strcpy(address_st, readstring2);
      while(!readfield2string(inputfile,  readstring1,  readstring2, 25))
      {
	
	 if (!strcmp(stringlower(readstring1), "\n") || !strcmp(stringlower(readstring1), "") || !strcmp(stringlower(readstring1), "name") || 
	        !strcmp(stringlower(readstring1), "name:") || !strcmp(stringlower(readstring1), "accountNo") || 
	           !strcmp(stringlower(readstring1), "accountno:") || !strcmp(stringlower(readstring1), "balance") || 
	               !strcmp(stringlower(readstring1), "balance:")) 
	                   break;
	      
	 strappend(address_st,"\n");
	 strappend(address_st, readstring1);
	 
	 if (strcmp(readstring2, "")) strappend(address_st," ");
	 	 strappend(address_st, readstring2);

    }     
  }
  
  if (!strcmp(stringlower(readstring1), "name") || !strcmp(stringlower(readstring1), "name:")) 
  {
    i++;
    if (i == 2) 
    {
      
      if (j == 0 ) 
	accarray[numrecords].accountno = 0;
      
      if (k == 0 ) 
	accarray[numrecords].balance = 0.0;
      
      numrecords++; 
      i = 1;  
      j = 0;  
      k = 0;
    }
        
    if (numrecords < *numcust)  strcpy( accarray[numrecords].name , readstring2);
  }
  
  else if (!strcmp(stringlower(readstring1), "accountno") || !strcmp(stringlower(readstring1), "accountno:")) 
  {
     j++;
     if (j == 2) 
     {
     
       if (i == 0 ) 
	 strcpy( accarray[numrecords].name , " ");
       
       if (k == 0 ) 
	 accarray[numrecords].balance = 0.0;
      
      numrecords++;
      
      i = 0;  
      j = 1;  
      k = 0; 
     
    } 
  
     if (numrecords < *numcust) accarray[numrecords].accountno = atoi(readstring2);
  }
  
  else if (!strcmp(stringlower(readstring1), "balance") || !strcmp(stringlower(readstring1), "balance:")) 
  {

    k++;
    
    if (k == 2) 
    {
      
      if (i == 0 ) 
	strcpy( accarray[numrecords].name , " ");
      
      if (j == 0 )  
	accarray[numrecords].accountno = 0;
      
      numrecords++; 
      i = 0;  
      j = 0;  
      k = 1;  
     
    } 
    if (numrecords < *numcust) accarray[numrecords].balance = atof(readstring2);
  } 
  else ;
    
    
  } // the end of while statement
  
 
  if (numrecords < *numcust) 
  {
        if (i == 0 ) 
	  strcpy( accarray[numrecords].name , " ");
      
	if (j == 0 )  
	accarray[numrecords].accountno = 0;
        
	if (k == 0 ) 
	  accarray[numrecords].balance = 0.0;
  }
  
  
   if (i == 0 && j == 0 && k == 0 && numrecords == 0) 
     numrecords--;
   
   if (*numcust == numrecords) 
     numrecords--;
  
  *numcust = numrecords+1;

  fclose(inputfile);
  return 0;
  
}


/*****************************************************************
//
//  Function name:		readfield2string  
//
//  DESCRIPTION:		A function which reads a line from the input file. And it returns two strings. 
//				In the line is empty both string would be empty as well. 
//				The fitst and second strings can be either seprated by ":" or one space or even muliple spaces.
//				There might be several spaces in the second string. The first string plays the role of keyword in any text formating applications.
//				The secound string will be the corresponding value.
//
//  Parameters:			FILE *inputfile: The pointer pointing at the file to read from
//				char readstring1[]: The first returned string (keyword)
//				char readstring2[]: The secound returned string (corresponding value)
//				int max_length2): The maximum number of allowd characters for the secound string. 
//
//  Return values:		int: = 1 if no line can be red from the file after reaching to EOF. = 0 if one line of the file is read and returned.
//****************************************************************/
// return 1 > EOF ... nothing happens
// return 0 > some string is read ... successful

int readfield2string(FILE *inputfile, char readstring1[], char readstring2[], int max_length2)
{
  int i=0;
  char test_char;
  readstring1[0]='\0';
  readstring2[0]='\0';
  
  if (!feof(inputfile))
  {
   
    do 
    { 
      test_char = fgetc(inputfile);
    }   while ((test_char == ' ' || test_char == '\t' ) && test_char != '\n' && !feof(inputfile));
    
    i = 0;
    while (test_char != '\n' && test_char != ' ' && test_char != '\t' && !feof(inputfile) )
    {
      readstring1[i] = test_char;
      i++; 
      test_char = fgetc(inputfile);
      if (test_char == ':') break;
    } 
    readstring1[i]  = '\0';
    
    if (test_char == ':') 
      test_char = fgetc(inputfile);
    
    while (test_char != '\n' && (test_char == '\t' || test_char == ' ') && !feof(inputfile))
    {
      test_char = fgetc(inputfile);
    }
         
    i=0;
    
    while (test_char != '\n' && !feof(inputfile))
    {
      readstring2[i] = test_char;
      
      if ((test_char != '\t' && test_char != ' ') || readstring2[i-1]!=' ')
      {
        i++;
      }
        
      test_char = fgetc(inputfile);
    } 
    
    readstring2[i]  = '\0';
    
    if (i>max_length2) 
      readstring2[max_length2]  = '\0';

    while (test_char != '\n' && !feof(inputfile))
      test_char = fgetc(inputfile); 
    
    //printf("\'%s\'.\'%s\'\n", readstring1, readstring2);
    return 0;
  }
 
 
return 1;
}


/*****************************************************************
//
//  Function name:		strappend  
//
//  DESCRIPTION:		a function to appends the second string argument 
				to the first string
//
//  Parameters:			char[] string1: The first string that the secound is to be attached to
//				char[] string2: The secound string which is to be attached to the forst one
//
//  Return values:		No output.
//
//****************************************************************/

void strappend(char string1[ ], char string2[ ]) 
{
  int index1 = 0, index2 = 0;
  
  while (string1[index1] != '\0') 
  {
    index1++;
  }

  while (string2[index2] != '\0') 
  {
    string1[index1] = string2[index2];
    index1++;
    index2++;
  }
  
  string1[index1] = '\0';

}


/*****************************************************************
//
//  Function name:		stringlower  
//
//  DESCRIPTION:		This function returns the input string in lowercase format.
//
//  Parameters:			char *string: the pointer assigned to the input string
//
//  Return values:		char: The lowercase format of the output string
//
//****************************************************************/

char *stringlower(char *string) 

{
  int index = 0;
  char newstr[100];

  
  while (string[index] != '\0') 
  {

   newstr[index] = tolower(string[index]);
    
    index++;
  
  }
  newstr[index] = '\0';
  return newstr;
}

//****************************************************************/

