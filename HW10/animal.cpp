/*****************************************************************                                                      
//                                                                                                                      
//  NAME:               Ehsan Kourkchi                                                                                  
//                                                                                                                      
//  HOMEWORK:           10                                                                                      
//                                                                                                                      
//  CLASS:              ICS 212                                                                                         
//                                                                                                                      
//  INSTRUCTOR:         Ravi Narayan                                                                                    
//                                                                                                                      
//  DATE:               December 12, 2013                                                                               
//
//  FILE:               animal.cpp        
//
//  DESCRIPTION:        This file contains the method definitions of 
//			the "animal" for HomeWork 10
//
//****************************************************************/

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>


#ifndef ANIMAL
#include "animal.h"
#endif 


// Class Parameters
//string         sound;                // contains "moo", "quack"
//unsigned char  data;                 // 0 – cannot fly, 1 – can fly
                                      // number of legs – 3 bits


/*****************************************************************
//
//  Function name:		animal::animal()  
//
//  DESCRIPTION:		Default Constructor 
//
//  Parameters:			Constructor: no input
//
//  Return values:		no output
//
//****************************************************************/ 
     /**    */
     animal::animal()
     {

       this -> sound = "";
       this -> data  = 0;
       
     }
     
/*****************************************************************
//
//  Function name:		animal::animal(string sound, int legsNo, bool canFly)
//
//  DESCRIPTION:		Constructor 
//
//  Parameters:			string sound: An string representing animal sound
//				int legsNo: An integer number representing the number of legs (0..7)
//				bool canFly: It is true if the animal can fly and it is false otherwise
//
//  Return values:		no output
//
//****************************************************************/      
     /**    */
     animal::animal(string sound, int legsNo, bool canFly)
     {
       
       this -> sound = sound;
       
       data = (unsigned char) legsNo;
       
       data = data & 0x07;
       
       data = data << 1;
       
       if(canFly)
	 data = data | 0x01;
       
     }
     
/*****************************************************************
//
//  Function name:		animal::~animal()
//
//  DESCRIPTION:		Destructor: Since no pointer is still used for poiting at any data on the Heap
 //				this destructor is still empty
//
//  Parameters:			no input
//
//  Return values:		no output
//
//****************************************************************/       
     /**    */
     animal::~animal()
     {
       

     }
     
     
/*****************************************************************
//
//  Function name:		void animal::displaydata()
//
//  DESCRIPTION:		prints the value of sound and fly
//
//  Parameters:			no input
//
//  Return values:		Prints the results on the screen
//
//****************************************************************/      
     /**    */
     void animal::displaydata()
     {
       
        cout << "\nThis is an animal ...." << endl;
        cout << "Sound: " << sound << endl;
	
	if(data & 0x01)
           cout << "Can Fly: Yes"   << endl;
	else 
	   cout << "Can Fly: No"   << endl;

       
     }


//****************************************************************/      
/** END */

