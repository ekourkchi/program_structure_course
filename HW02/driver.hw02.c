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
//  FILE:		driver.hw02.c        
//
//  DESCRIPTION:	driver function to test functions strlen, strcmp strchr, strpbrk and strcpy functions, 
//			which are available in the library
//
//****************************************************************/

# include <stdio.h>
# include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m" 
#define DEFCOLOR "\033[0m"


void PrintStatus(int status);

int main(void) 
{
  
  char TestString1[100]= "This is the 1st test sentence which has 61 characters length.";
  char TestString2[100]= "This is the 2nd sentence which has 49 characters.";
  char TestApple[100]= "Apple";
  char TestOrange[100]= "Orange";
  char TestBanana[100]= "Banana";
  int  temp = 0;
  char TempString[100];
  char *CharPointer, test_char;
  int function_out = 0;
 
  printf("\n***********************************************\n");
  printf("************   testing strlen  ****************\n"); 
  printf("***********************************************\n");

  printf("The test string 1 is: \n\"%s\"\n", TestString1);
  function_out = strlen(TestString1);
  printf("The measured length of the string 1: %d\n", function_out);
  printf("\t\t\t\tstrlen:");
 
  if (function_out == 61)  
     PrintStatus(1); 
  else 
     PrintStatus(0); 
 
  printf("\t The test string 2 is: \n\"%s\"\n", TestString2);
  function_out = strlen(TestString2);
  printf("The measured length of the string 2: %d\n", function_out);
  printf("\t\t\t\tstrlen:");
  
  if (function_out == 49)  
    PrintStatus(1); 
  else 
   PrintStatus(0); 
 
  printf("\n***********************************************\n");
  printf("************   testing strcmp  ****************\n"); 
  printf("***********************************************\n"); 
 

  printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestApple, TestOrange);
  printf("%3d", temp = strcmp(TestApple,TestOrange));
  
  if (temp < 0) 
     PrintStatus(1); 
  else 
    PrintStatus(0); 

   
 
 printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestBanana, TestOrange);
 printf("%3d", temp = strcmp(TestBanana,TestOrange));
 
 if (temp < 0) 
    PrintStatus(1); 
 else 
    PrintStatus(0);
 
 printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestBanana, TestApple);
 printf("%3d", temp = strcmp(TestBanana,TestApple));
  if (temp > 0) 
     PrintStatus(1); 
  else 
    PrintStatus(0); 
 
 printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestApple, TestBanana);
 printf("%3d", temp = strcmp(TestApple,TestBanana));
  if (temp < 0) PrintStatus(1); 
 else PrintStatus(0); 
 
 printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestApple, TestApple);
 printf("%3d", temp = strcmp(TestApple,TestApple));
  if (temp == 0) PrintStatus(1); 
 else PrintStatus(0); 
 
 printf("strcmp \"%s\"\t vs. \"%s\"\t: ", TestOrange, TestOrange);
 printf("%3d", temp = strcmp(TestOrange,TestOrange));
 if (temp == 0) PrintStatus(1); 
 else PrintStatus(0); 
 
 printf("\n***********************************************\n");
 printf("************   testing strcpy  ****************\n"); 
 printf("***********************************************\n"); 
 
 
 printf("strcpy \"%s\"\t -> \"%s\"\t: ", TestApple, TestOrange);
 strcpy(TestOrange,TestApple);
 printf("\"%s\"\n", TestOrange);
 printf("\t\t\t\tstrcpy:");
 if (strcmp(TestOrange,TestApple) == 0)  PrintStatus(1); 
 else PrintStatus(0); 
 
 printf("\n");
 
 TestApple[0] = 'A';
 TestApple[1] = 'p';
 TestApple[2] = 'p';
 TestApple[3] = 'l';
 TestApple[4] = 'e';
 TestApple[5] = 0;
 
 TestOrange[0] = 'O';
 TestOrange[1] = 'r';
 TestOrange[2] = 'a';
 TestOrange[3] = 'n';
 TestOrange[4] = 'g';
 TestOrange[5] = 'e';
 TestOrange[6] = 0;
 
 TestBanana[0] = 'B';
 TestBanana[1] = 'a';
 TestBanana[2] = 'n';
 TestBanana[3] = 'a';
 TestBanana[4] = 'n';
 TestBanana[5] = 'a';

 printf("strcpy \"%s\"\t -> \"%s\"\t: ", TestBanana, TestApple);
 strcpy(TestApple,TestBanana);
 printf("\"%s\"\n", TestApple);
 printf("\t\t\t\tstrcpy:");
 if (strcmp(TestApple,TestBanana) == 0)  PrintStatus(1); 
 else PrintStatus(0); 
 
 
 
 TestApple[0] = 'A';
 TestApple[1] = 'p';
 TestApple[2] = 'p';
 TestApple[3] = 'l';
 TestApple[4] = 'e';
 TestApple[5] = 0;
 
 TestOrange[0] = 'O';
 TestOrange[1] = 'r';
 TestOrange[2] = 'a';
 TestOrange[3] = 'n';
 TestOrange[4] = 'g';
 TestOrange[5] = 'e';
 TestOrange[6] = 0;
 
 TestBanana[0] = 'B';
 TestBanana[1] = 'a';
 TestBanana[2] = 'n';
 TestBanana[3] = 'a';
 TestBanana[4] = 'n';
 TestBanana[5] = 'a';
 TestBanana[6] = 0;
 

 printf("\n***********************************************\n");
 printf("************   testing strchr  ****************\n"); 
 printf("***********************************************\n");
 
 test_char = 'O';
 CharPointer = strchr(TestOrange, test_char);
  if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t ",test_char, TestOrange, CharPointer);
  else 
   printf("Look for \'%c\' in \"%s\"\t: null ",test_char, TestOrange);
 if (*CharPointer == test_char) PrintStatus(1); 
 else PrintStatus(0); 
 
 test_char = 'r';
 CharPointer = strchr(TestOrange, test_char);
  if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t ",test_char, TestOrange, CharPointer);
  else 
   printf("Look for \'%c\' in \"%s\"\t: null ",test_char, TestOrange);
 if (*CharPointer == test_char) PrintStatus(1); 
 else PrintStatus(0); 
 
 test_char = 'a';
 CharPointer = strchr(TestOrange, test_char);
  if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t ",test_char, TestOrange, CharPointer);
  else 
   printf("Look for \'%c\' in \"%s\"\t: null ",test_char, TestOrange);
 if (*CharPointer == test_char) PrintStatus(1); 
 else PrintStatus(0); 
 
 test_char = 'g';
 CharPointer = strchr(TestOrange, test_char);
  if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t \t",test_char, TestOrange, CharPointer);
  else 
   printf("Look for \'%c\' in \"%s\"\t: null ",test_char, TestOrange);
 if (*CharPointer == test_char) PrintStatus(1); 
 else PrintStatus(0); 
 
 
 test_char = 'n';
 CharPointer = strchr(TestBanana, test_char);
 if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t ",test_char, TestBanana, CharPointer);
 else 
   printf("Look for \'%c\' in \"%s\"\t: null\t\t ",test_char, TestBanana);
 if (*CharPointer == test_char) PrintStatus(1); 
 else PrintStatus(0); 
 
 
  test_char = 'X';
 CharPointer = strchr(TestBanana, test_char);
 if (CharPointer != 0) 
 printf("Look for \'%c\' in \"%s\"\t: \'%s\'\t ",test_char, TestBanana, CharPointer);
 else 
   printf("Look for \'%c\' in \"%s\"\t: null\t \t",test_char, TestBanana);
 if (CharPointer == 0) PrintStatus(1); 
 else PrintStatus(0); 
 
 
 

 printf("\n***********************************************\n");
 printf("************   testing strpbrk  ****************\n"); 
 printf("***********************************************\n");
 
 
  CharPointer = strpbrk(TestBanana, TestApple); 
  
 if (CharPointer != 0) 
 printf("Look for \'%s\' in \"%s\"\t: \'%s\'\t ",TestApple, TestBanana, CharPointer);
 else 
   printf("Look for \'%s\' in \"%s\"\t: null \t\t",TestApple, TestBanana);
 if (CharPointer == 0) PrintStatus(1); 
 else PrintStatus(0); 
 
 
 CharPointer = strpbrk(TestBanana, TestOrange);
 
 if (CharPointer != 0) 
   printf("Look for \'%s\' in \"%s\"\t: \'%s\'\t ",TestOrange, TestBanana, CharPointer);
 else 
   printf("Look for \'%s\' in \"%s\"\t: null\t ",TestOrange, TestBanana);
  
 if (*CharPointer == 'a') 
   PrintStatus(1); 
 else 
   PrintStatus(0); 
 
 
 printf("\n************   Done.  ****************\n"); 

 
  printf(DEFCOLOR);
  return 0;
  
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


