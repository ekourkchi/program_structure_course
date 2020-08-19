# include  <stdio.h>
# include "record.h"

extern int debugmode;
    
//     int addRecord (struct record **,char [ ],char [ ],int, char [ ]);
//     int printRecord (struct record *, char [ ]);    
//     int modifyRecord (struct record *, char [ ], char [ ], int, char [ ]);       
//     void printAllRecords(struct record *);
//     int deleteRecord(struct record **, char [ ]);
    


/*****************************************************************
//
//  Function name:		addRecord  
//
//  DESCRIPTION:		a funstion that add new record to the existing database
//
//  Parameters:			struct record **start: a pointer to the database record
//				char name[ ]: name 
//				char address[ ]: address 
//				int yearofbirth: Year of Birth
//				char telephone[ ]: Telephone #
//
//  Return values:		int: = 0 if it is successful, = 1 if it is not successful
//
//****************************************************************/

    int addRecord (struct record **start,char name[ ],char address[ ],int yearofbirth, char telephone[ ]) 
    {
      
    if (debugmode ==1)
    {
      printf("\n\n *** DEBUG ***\n");
      printf(" Fuction: addRecord\n");
      printf(" Name: %-10s\n", name);
      printf(" Address: %-10s\n", address);
      printf(" Year of Birth: %-10d\n", yearofbirth);
      printf(" Telephone #: %-10s\n", telephone);
      printf(" ************\n");

    }
    
      
    return 1;
    }
    
   
/*****************************************************************
//
//  Function name:		printRecord  
//
//  DESCRIPTION:		a funstion that prints a record based on the 'key' 
//
//  Parameters:			struct record *start: a pointer to the database
//				char name[ ]: name ... which is the 'key' here
//
//  Return values:		int: = 0 if it is successful, = 1 if it is not successful
//
//****************************************************************/
   
   
    int printRecord (struct record *start, char name[ ])
    {
      
    if (debugmode ==1)
    {
      printf("\n\n *** DEBUG ***\n");
      printf(" Fuction: printRecord\n");
      printf(" Name: %-10s\n", name);
      printf(" ************\n");

    }   

    
    return 1;  
    }
    
/*****************************************************************
//
//  Function name:		modifyRecord  
//
//  DESCRIPTION:		a funstion that modify record based on the input 'key'
//
//  Parameters:			struct record **start: a pointer to the database record
//				char name[ ]: name  ... which is the 'key' here
//				..the filloin parameters would be modified
//				char address[ ]: address 
//				int yearofbirth: Year of Birth
//				char telephone[ ]: Telephone #
//
//  Return values:		int: = 0 if it is successful, = 1 if it is not successful
//
//****************************************************************/


  int modifyRecord (struct record *start, char name[ ],char address[ ],int yearofbirth, char telephone[ ])
  {
      
    if (debugmode ==1)
    {
      printf("\n\n *** DEBUG ***\n");
      printf(" Fuction: modifyRecord\n");
      printf(" Name: %-10s\n", name);
      printf(" Address: %-10s\n", address);
      printf(" Year of Birth: %-10d\n", yearofbirth);
      printf(" Telephone #: %-10s\n", telephone);
      printf(" ************\n");

    }
    
      
    return 1;
    } 

 /*****************************************************************
//
//  Function name:		printAllRecords  
//
//  DESCRIPTION:		a funstion that prints all records of the database 
//
//  Parameters:			struct record *start: a pointer to the database
//
//  Return values:		int: = 0 if it is successful, = 1 if it is not successful
//
//****************************************************************/

    void printAllRecords(struct record *start)
    {
    
	if (debugmode ==1)
      {
	printf("\n *** These are all contacts ***\n");
	printf(" Fuction: printAllRecords\n");
	printf("\n *** ********************** ***\n");


      }    
          
    }
    
/*****************************************************************
//
//  Function name:		deleteRecord  
//
//  DESCRIPTION:		a funstion that delete a record based on the 'key' 
//
//  Parameters:			struct record *start: a pointer to the database
//				char name[ ]: name ... which is the 'key' here
//
//  Return values:		int: = 0 if it is successful, = 1 if it is not successful
//
//****************************************************************/  
    
    int deleteRecord(struct record **start, char name[ ])
    {
    
	if (debugmode ==1)
	{
	    printf("\n\n *** DEBUG ***\n");
	    printf(" Fuction: deleteRecord\n");
	    printf(" Name: %-10s\n", name);
	    printf(" ************\n");

	}  
    
    return 1;
    }
    
//****************************************************************/  

