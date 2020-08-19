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
//  FILE:               cow.cpp        
//
//  DESCRIPTION:        This file contains the method definitions of 
//			the "cow" for HomeWork 10
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

#ifndef COW
#include "cow.h"
#endif 


/*****************************************************************
//
//  Function name:		cow::cow()  
//
//  DESCRIPTION:		Default Constructor 
//
//  Parameters:			Constructor: no input
//				By default, each cow has four legs, does not fly and has "moo" sound
//
//  Return values:		no output
//
//****************************************************************/ 
     /**    */
     cow::cow() 
     : animal("moo", 4, false)
     {
 
                
     }
     
/*****************************************************************
//
//  Function name:		cow::cow(string sound, int legsNo) 
//
//  DESCRIPTION:		Constructor 
//
//  Parameters:			string sound: An string representing animal sound
//				int legsNo: An integer number representing the number of legs (0..7)
//
//  Return values:		no output
//
//****************************************************************/     
     /**    */
     cow::cow(string sound, int legsNo) 
     : animal(sound, legsNo, false)
     {


       
     }
     
     
/*****************************************************************
//
//  Function name:		cow::cow(string sound) 
//
//  DESCRIPTION:		Constructor 
//
//  Parameters:			string sound: An string representing animal sound
//
//  Return values:		no output
//
//****************************************************************/     
     /**    */
     cow::cow(string sound) 
     : animal(sound, 4, false)
     {


       
     }
     
/*****************************************************************
//
//  Function name:		cow::cow(string sound, int legsNo) 
//
//  DESCRIPTION:		Constructor 
//
//  Parameters:			int legsNo: An integer number representing the number of legs (0..7
//
//  Return values:		no output
//
//****************************************************************/     
     /**    */
     cow::cow(int legsNo) 
     : animal("moo", legsNo, false)
     {


       
     }     
     
     
/*****************************************************************
//
//  Function name:		cow::~cow()
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
     cow::~cow()
     {

     }
     
/*****************************************************************
//
//  Function name:		void cow::displaydata()
//
//  DESCRIPTION:		prints values of sound, numberoflegs and fly
//
//  Parameters:			no input
//
//  Return values:		Prints the results on the screen
//
//****************************************************************/      
     /**    */
     void cow::displaydata()
     {
       
        cout << "\nThis is a cow ...." << endl;
        cout << "Sound: " << sound << endl;
	
	if(data & 0x01)
           cout << "Can Fly: Yes"   << endl;
	else 
	   cout << "Can Fly: No"   << endl;
	
	
        cout << "Legs: " << (int)(data>>1) << endl;
       
     }
     
//****************************************************************/      
/** END */

