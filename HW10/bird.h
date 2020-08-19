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

#define BIRD



class bird : public animal
{

   public: 
       bird();
       bird(string, bool);
       ~bird();
       void displaydata( );  // prints values of sound, numberoflegs and fly

};  // end of the calss

//****************************************************************/
