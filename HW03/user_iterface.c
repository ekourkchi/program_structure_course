#define RED "\033[1;31m"
#define GREEN "\033[1;32m" 
#define BLUE "\033[1;34m" 
// background: blue foeground: cyan
#define CYAN "\033[44;1;36m"
// "\033[K" clears the end of Line
#define DEFCOLOR "\033[0m\033[K"
#define YELLOW "\033[44;1;33m"

# include <stdio.h>
# include "record.h"

 // Database handling
 int addRecord (struct record **,char [ ],char [ ],int, char [ ]);
 int printRecord (struct record *, char [ ]);    
 int modifyRecord (struct record *, char [ ], char [ ], int, char [ ]);       
 void printAllRecords(struct record *);
 int deleteRecord(struct record **, char [ ]);
 
 // Display header
 // Main Menu
 // Program Arguments Handling
 void header(void);
 int main_menu(void);
 int arguments(int argc, char * argv[]);
 
 // UserInterface to ask user to input the data
 int getfield(char * input_string, char string_name[], int mode);
 int get_address(char * address, char string[]);
 int get_name(char * name, char string[]);
 int get_int(int * number, int lower, int upper);
 void get_int_txt(int * year, int lower, int upper, char text []);
 
 // User Interface to handle the database
 int getdata(struct record * start);
 int printdata(struct record * start);
 int modifydata(struct record * start);
 int removedata(struct record * start);
 
 // Some additonal functions
 int string_equality(char a [], char b []);
 void StringColorPrint(char * string, char color[]);


/*****************************************************************/
// GLOBAL VARIABLES */

 int debugmode = 0;

/****************************************************************/




int main(int argc, char *argv[])
{
 
  char address[80];
  char name[25];
  char telephone[15];
  int  yearofbirth;
  int check, menu;
  int goto_main_menu=1, exit_program=0;
  struct record *start = NULL;


  
if (arguments(argc, argv) == 1) return 1;


do {
  
menu = main_menu();
switch (menu)
{
  case 1: 
    check = getdata(start);
    if (check == 0) exit_program=1;
    else  goto_main_menu=1;
    break;
  case 2:
    check = printdata(start);
    if (check == 0) exit_program=1;
    else  goto_main_menu=1;
    break;
  case 3: 
    check = modifydata(start);
    if (check == 0) exit_program=1;
    else  goto_main_menu=1;
    break;
  case 4: 
    printAllRecords(start);
    goto_main_menu=1;
    break;
  case 5: 
    check = removedata(start);
    if (check == 0) exit_program=1;
    else  goto_main_menu=1;  
    break;
  case 6: 
    exit_program=1;
    break;
}
 

} while(exit_program == 0 && goto_main_menu==1) ;
 
 

printf("\n\n  Discarding contents of the address book ...\n  Goodbye ....\n\n");
  
fflush(stdout);
return 0; 


} // The end of main program




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

int get_address(char *address, char string[])
{
  int boolean = 0;
  int counter = 0;
  char test_char0 = ' ', test_char1 = ' ' ;
  
  
  printf("Enter the %s:  ", string);
  printf("\nPress the <Enter> key two times when you are done\n");

  do 
  {
    boolean = 0;
    counter = 0;
  

    test_char0 = ' ';
    test_char1 = '\0' ;
    StringColorPrint("# ", "def");
 
	while(boolean == 0) 
	{
	      
	  test_char0 = fgetc(stdin);
	  *(address+counter) = test_char0;
	  
	  if (test_char0 == '\n' && test_char1 == '\0')       
	    boolean = 1;
	  
	  if (test_char0 == '\n' && test_char1 == '\n')    
	  {   
	    boolean = 1; 
	    counter--; 
	  }
	  
	  if (test_char0 == '\n' && boolean == 0) 
	    StringColorPrint("# ", "def");
	  
	test_char1 = test_char0;   
	counter++;
	}
	
  
  *(address+counter-1) = '\0';
  

	if ( *address == '\0') 
	{
	  printf(RED);
	  printf("Enter a valid %s again:\n", string);
	  printf(DEFCOLOR);
	}
      
  } while(*address == '\0');
  

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

int get_name(char *name, char string[])
{
  int boolean = 0;
  int counter = 0;
  char test_char0 = ' ', test_char1 = ' ' ;
    printf("Enter the %s: ", string);

do {
  
  boolean = 0;
  counter = 0;
  test_char0 = ' ';
  test_char1 = ' ' ;

  while(boolean == 0) 
  {
    test_char0 = fgetc(stdin);
    *(name+counter) = test_char0;
    counter++;

    if (test_char0 == '\n') boolean = 1;    
    test_char1 = test_char0;   
  }

  *(name+counter-1) = '\0';
  
  if ( *name == '\n' || *name == '\0') 
  {
   printf(RED);
   printf("Enter a valid %s again: ", string); 
   printf(DEFCOLOR);
  }
  
} while(*name == '\n' || *name == '\0');
  

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


int get_int(int *number, int lower, int upper)
{
  
char input_string[100], input_char;
int length_string = 0, i, delta, boolean = 1, sum = 0, get_char = 1;
char zero='0';

  while(get_char) 
  {
    
    input_char = fgetc(stdin);
    input_string[length_string] = input_char;
    length_string++;
    if (input_char == '\n') get_char = 0;
  } 
  
  
  length_string -= 1;
  *(input_string+length_string) = '\0';

  sum = 0;
  for(i=length_string-1; i >= 0; i--)
  {
    
	delta = (int) input_string[length_string-i-1] - (int) zero;

	if (delta <= 9 && delta >= 0) 
	  sum = 10 * sum + delta;
	else 
	{ 
	    boolean = 0;
	    break;
	}

  }
  
  if(boolean == 1 && sum >= lower && sum <= upper) 
    *number = sum;
  else boolean = 0;
  
  
return boolean;
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

void get_int_txt(int *year, int lower, int upper, char text [])
{

  int boolean = 0;

  printf("%s", text);  
  boolean = get_int( year, lower, upper);
  
  while(!boolean) 
  {
   StringColorPrint(text, "red");
   boolean = get_int( year, lower, upper);
  }
    
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

void header(void)
{
  
   if (!debugmode) printf("\033[2J"); // clear screen
   if (!debugmode) printf("\033[100A"); // 100 lines up
   if (debugmode)  printf("\n");
   StringColorPrint("Ehsan Kourkchi (Sep. 2013) ", "yellow");
   StringColorPrint("*** Welcome to [Address Book] (ICS212 - HW03)", "yellow"); 
   printf("\033[K");
   printf("\n\n");
   if (debugmode) StringColorPrint(" *** DEBUG MODE ***\n\n", "green");
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

int main_menu(void)
{
 
 int check = 1;
 int menu;
 do {
  
   header();
 
   printf(" *** Menu Options ***\n");
   printf("\n 1) Add a contact\n");
   printf(" 2) Print a contact\n");
   printf(" 3) Modify a contact\n");
   printf(" 4) Print all contacts\n");
   printf(" 5) Remove a contact\n");
   printf(" 6) Quits\n\n");
   printf(" ********************\n");

   
    if (check ==0 ) 
      StringColorPrint(" Enter your choice (1..6): ", "red");
    else
      printf(" Enter your choice (1..6): ");

   check = get_int(&menu,1,6);
  
   } while(!check);
   
return menu;  
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

int  arguments(int argc, char *argv[])
{
  int exit_program = 0;
   if (argc == 1) 
 {
   debugmode = 0;
 }
 else if (argc == 2) 
 {
	if (string_equality(argv[1] , "--help") || string_equality(argv[1] , "-h")) 
	{
	  printf("\n\n Usage: database [OPTION] ");
	  printf("\n If no option is used,\n the program will be run in the normal mode.");
	  printf("\n\n *** OPTIONS *** ");

	  printf("\n\n -d, debug");
	  printf("\n   In this mode, the name of all functions");
	  printf("\n   and the passed parameters will be displayed.");
	  
	  printf("\n\n -v, --version");
	  printf("\n   output version information and exit");
	  

	  printf("\n\n -h, --help");
	  printf("\n   display this help and exit\n");


	  printf("\n");

	  
	  exit_program = 1;
	} 
	else if (string_equality(argv[1] , "debug") || string_equality(argv[1] , "-d")) 
	{
	  debugmode = 1;
	}
	else if (string_equality(argv[1] , "-v") || string_equality(argv[1] , "--version"))
	{
	 printf("\n   database");
 	 printf("\n   version: (ICS212) HW03");
	 printf("\n   Copyright (C) 2013");	  
	 printf("\n   Written by Ehsan Kourkchi\n\n");  
	 exit_program = 1;
	}
	else
	{
	  printf("\n Bad opperands\n Try '--help' flag for more information.\n\n");
	  exit_program = 1;
	}
  
 }
 else {
   printf("\n Bad operands.\n Try '--help' flag for more information.\n\n");
   exit_program = 1;
 }

 return exit_program;
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

int getfield(char *input_string, char string_name[], int mode)
{
  
  // Get one line string
  switch (mode)
  {
    case 0: 
      get_name(input_string, string_name);
      break;
  // Get a string which potentialy can be more than one lines
    case 1:
      get_address(input_string, string_name);
      break;
    default: return 1;
  }

return 0;
  
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

int getdata(struct record *start)
{
  
  char address[80];
  char name[25];
  char telephone[15];
  int  yearofbirth;
  
  
  int menu=2,check=1;
  do 
  {

  header();
  getfield(name,"name", 0);
  getfield(address, "address", 1); 
  get_int_txt(&yearofbirth, 1900, 2050, "Please enter the year of birth (1900-2050):");
  getfield(telephone,"telephone number", 0);
  

	    do {
	    header();
	    
	    printf("New Contact:");

	    StringColorPrint("\nName: ", "blue");
	    StringColorPrint(name, "green");

	    StringColorPrint("\nAddress: ", "blue");
	    StringColorPrint(address, "green");

	      
	    StringColorPrint("\nYear of Birth: ", "blue");
	    printf(GREEN);
	    printf("%d\n", yearofbirth);
	    printf(DEFCOLOR);
	  
	    StringColorPrint("Telephone #: ", "blue");
	    StringColorPrint(telephone, "green"); 
	    printf("\n\n");
      
	    printf("\n ***** Options *****\n");
	    printf("\n 1) Yes (save it)\n");
	    printf(" 2) No (try again)\n");
	    printf(" 3) Main Menu (ignore it)\n");
	    printf(" 4) Exit the program\n\n");
	    printf(" *******************\n");

   
	    if (check == 0 ) 
	      StringColorPrint(" Enter your choice (1..4): ", "red");
	    else
	      printf(" The input data is correct?\n");
	    
	    printf(" Enter your choice (1..4): ");

	    check = get_int(&menu,1,4);
  
	    } while(!check);

    
  } while(menu==2);


  
  switch (menu)
  {
    case 1:
      addRecord (&start, name, address, yearofbirth, telephone);
    case 3: 
      return 1;
    case 4: 
      return 0;
  }

  
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

int printdata(struct record * start)
{
  
  char address[80];
  char name[25];
  char telephone[15];
  int  yearofbirth;
  int menu=2,check=1;
  
  do {

  header();
  getfield(name,"contact name", 0);
  
  
  
	    do {
  
	    header();
	         
	    StringColorPrint("\nName: ", "blue");
	    StringColorPrint(name, "green");
	    
            if (printRecord (start, name) == 0) 
               StringColorPrint("\n The entered ontact name does not exist in database.\n", "red");    
	    
	    printf("\n\n");
      
	    printf("\n ***** Options *****\n");
	    printf("\n 1) Search again\n");
	    printf(" 2) Main Menu\n");
	    printf(" 3) Exit the program\n\n");
	    printf(" *******************\n");

   
	    if (check == 0 ) 
	      StringColorPrint(" Enter your choice (1..3): ", "red");
	    else
	      printf(" Enter your choice (1..3): ");
	    check = get_int(&menu,1,3);
  
	    } while(!check);


} while(menu==1);
  

      switch (menu)
      {
	case 2: 
	  return 1;
	case 3: 
	  return 0;
      }
  
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

int modifydata(struct record *start)
{
  
  char address[80];
  char name[25];
  char telephone[15];
  int  yearofbirth;
  int menu=2,check=1;


  do {

  header();

  StringColorPrint("\nThe contact to be modified \n", "blue");
  getfield(name,"name", 0);

  StringColorPrint("\nEnter the new address \n", "blue");
  getfield(address, "address", 1); 

  StringColorPrint("\nNew year of birth \n", "blue");
  get_int_txt(&yearofbirth, 1900, 2050, "Please enter the year of birth (1900-2050):");

  StringColorPrint("\nNew telephone number \n", "blue"); 
  getfield(telephone,"telephone number", 0);
  

	    do {
	      
	    header();
	    
	    if (menu !=1) 
	    {
	    
	      printf("[Modify a Contact]\n");

	      StringColorPrint("\nName: ", "blue");
	      StringColorPrint(name, "green");
 
	      StringColorPrint("\nAddress: ", "blue");
	      StringColorPrint(address, "green");
  
	      StringColorPrint("\nYear of Birth: ", "blue");
	      printf(GREEN);
	      printf("%d\n", yearofbirth);
	      printf(DEFCOLOR);
	  
	      StringColorPrint("Telephone #: ", "blue");
	      StringColorPrint(telephone, "green"); 
	      printf("\n\n");

	      
	      printf("\n ***** Options *****\n");
	      printf("\n 1) Yes (modify it)\n");
	      printf(" 2) No (try again)\n");
	      printf(" 3) Main Menu (ignore it)\n");
	      printf(" 4) Exit the program\n\n");
	      printf(" *******************\n");

   
	      if (check == 0 ) 
	        StringColorPrint(" Enter your choice (1..4): ", "red");
	       else
	         {
	           printf(" The input data is correct?\n");
	           printf(" Enter your choice (1..4): ");
	         }

	    check = get_int(&menu,1,4);
	    }

	    
	    
	    if (menu == 1 && modifyRecord (start, name, address, yearofbirth, telephone) == 0)
	      {
                  StringColorPrint("\n The entered contact name does not exist in database.\n", "red");
		  printf("\n ***** Options *****\n");
		  printf(" 2) Try again\n");
		  printf(" 3) Main Menu (ignore it)\n");
		  printf(" 4) Exit the program\n\n");
		  printf(" *******************\n");
		  
	            if (check == 0 ) 
	              StringColorPrint(" Enter your choice (2..4): ", "red");
	            else
	              printf(" Enter your choice (2..4): ");
  
                  check = get_int(&menu,2,4);
	    
		  if (check == 0) 
	             menu = 1;
	      }
	      

	     } while(!check);


  } while(menu==2);


    switch (menu)
    {
      
      case 3: 
	return 1;
      case 4: 
	return 0;
    }

 
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

int removedata(struct record * start)
{
  
  char address[80];
  char name[25];
  char telephone[15];
  int  yearofbirth;
  int menu=2,check=1;
  
  do {

     header();
     printf("[Remove a Contact]");
     StringColorPrint("\n\nThe contact to be removed \n", "blue");
     getfield(name,"contact name", 0);
 
	    do {
   
	    header();
	    StringColorPrint("\nName: ", "blue");
	    StringColorPrint(name, "green");
	    
            if (deleteRecord (&start, name) == 0) 
              StringColorPrint("\n The entered contact name does not exist in database.", "red");    
	    printf("\n");
	      
	    printf("\n ***** Options *****\n");
	    printf("\n 1) Try again\n");
	    printf(" 2) Main Menu\n");
	    printf(" 3) Exit the program\n\n");
	    printf(" *******************\n");

   
	    if (check == 0 ) 
	      StringColorPrint(" Enter your choice (1..3): ", "red");
	    else
	      printf(" Enter your choice (1..3): ");

	    check = get_int(&menu,1,3);
  
	    } while(!check);


    
    
    
     } while(menu==1);
  

switch (menu)
{
  case 2: 
    return 1;
  case 3: 
    return 0;
}
  
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


int string_equality(char a [], char b [])
{

int i=0, j=0, bool =1;
 
 
while ( *(a+i) != '\0'  )  
  i++;
while ( *(b+j) != '\0'  )  
  j++;


 if (i != j) bool = 0;
 else 
 {
   i = 0;

      while(*(a+i) == *(b+i) )  
	i++;
      
      if (i-1 == j) 
	bool = 1; 
      else 
	bool = 0; 
 }

 
return bool;
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

 
  if(color == "cyan") 
 {
   printf(CYAN);
   printf("%s", string); 
   printf(DEFCOLOR);
   printf("\033[K");
 } 
 
   if(color == "yellow") 
 {
   printf(YELLOW);
   printf("%s", string); 
   printf(DEFCOLOR);
 } 
  
  if(color == "def") 
 {
   printf("%s", string); 
 } 
 
 
}

  