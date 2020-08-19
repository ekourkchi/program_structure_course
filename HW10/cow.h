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
//****************************************************************/

#ifndef ANIMAL
#include "animal.h"
#endif 

#define COW



class cow : public animal
{

   public: 
       cow();
       cow(string, int);
       cow(int legsNo);
       cow(string sound);
       
       ~cow();
       void displaydata( );  // prints values of sound, numberoflegs and fly

};  // end of the calss

//****************************************************************/
