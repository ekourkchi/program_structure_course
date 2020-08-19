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

#define ANIMAL



class animal 
{

   protected:     
      
      string         sound;                // contains "moo", "quack"
      unsigned char  data;                 // 0 – cannot fly, 1 – can fly
                                           // number of legs – 3 bits
   public: 
     
     animal();
     animal(string, int, bool);
     ~animal();
     virtual void displaydata( ); // prints the value of sound and fly


     
}; // end of the animal class

//****************************************************************/

