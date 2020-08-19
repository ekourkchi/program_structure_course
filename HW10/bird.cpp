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
//  FILE:               bird.cpp        
//
//  DESCRIPTION:        This file contains the method definitions of 
//			the "bird" for HomeWork 10
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

#ifndef BIRD
#include "bird.h"
#endif 




/*****************************************************************
//
//  Function name:		bird::bird() 
//
//  DESCRIPTION:		Default Constructor 
//
//  Parameters:			Constructor: no input
//				By default, each bird has two legs, flys and has "quack" sound
//
//  Return values:		no output
//
//****************************************************************/
     /**    */
     bird::bird() 
     : animal("quack", 2, true)
     {
 
                
     }
     
/*****************************************************************
//
//  Function name:		bird::bird(string sound, bool canFly) 
//
//  DESCRIPTION:		Constructor 
//
//  Parameters:			string sound: An string representing animal sound
//				bool canFly: It is true if the animal can fly and it is false otherwise
//
//  Return values:		no output
//
//****************************************************************/      
     /**    */
     bird::bird(string sound, bool canFly) 
     : animal(sound, 2, canFly)
     {

     }
     
     
/*****************************************************************
//
//  Function name:		bird::~bird()
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
     bird::~bird()
     {

     }
     
     
/*****************************************************************
//
//  Function name:		bird::displaydata()
//
//  DESCRIPTION:		prints the value of sound and fly
//
//  Parameters:			no input
//
//  Return values:		Prints the results on the screen
//
//****************************************************************/      
     /**    */
     void bird::displaydata()
     {
        
        cout << "\nThis is a bird ...." << endl;
        cout << "Sound: " << sound << endl;
	
	if(data & 0x01)
           cout << "Can Fly: Yes"   << endl;
	else 
	   cout << "Can Fly: No"   << endl;

       
     }
