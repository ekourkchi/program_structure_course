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
//  FILE:               hw10.cpp        
//
//  DESCRIPTION:        This file contains the main function which creates instances of the animal, cow and bird class.
//                      It Uses the vector and Map classes to store multiple instances of the animals
//                      By calling the animaldisplaydata function the polymorphism on the displaydata 
//                      function of the bird and cow classes are checked
//
//****************************************************************/
// To compile the program:
// $ make all
// $ ./hw10
//****************************************************************/



#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>


#ifndef COW
#include "cow.h"
#endif 


#ifndef BIRD
#include "bird.h"
#endif 


#ifndef ANIMAL
  #include "animal.h"
#endif 

/****************************************************************/
// Function declarations
void animaldisplaydata(animal * a);
/****************************************************************/


/**
 * Main function (driver for animal, cow and bird classes)
 * 
 * @param no input argument is needed
 * 
 */

int main(int argc, char * argv[])
{

    int size, index; 
    
    // defining a Vector of animals
    vector <animal> zoo;  
    
    animal dog("bark", 4, false);
    animal mosquito("buzz", 2, true);
    animal horse("whinny", 4, false);
    animal defAnimal;
    
    cow defCow;
    cow myCow1("moo", 4);
    cow myCow2("moi", 3);
    
    bird defBird;
    bird crow("caaaw caaaw", true);
    bird eagle("gig", true);
    bird rooster("cock-a-doodle-doo", false);

    zoo.push_back(dog);  
    zoo.push_back(mosquito);
    zoo.push_back(horse);
    zoo.push_back(defAnimal);
    
    zoo.push_back(defCow);  
    zoo.push_back(myCow1);
    zoo.push_back(myCow2);
    
    zoo.push_back(defBird);    
    zoo.push_back(crow);       
    zoo.push_back(eagle);       
    zoo.push_back(rooster);      
    
    
    size =  zoo.size();
    
    cout << "\n***********************************" << endl;
    cout << "*** Testing animaldisplaydata()" << endl;
    cout << "*** using a defined vector holding " << endl;
    cout << "*** all animals " << endl << endl;
    cout << " Here the displaydata() method of animal" << endl;
    cout << " class would be called for all animals" << endl;
    cout << "***********************************" << endl;
    cout << "The size of zoo vector is " << size << endl << endl; 
    for (int index=0; index < size; index++)
    {
       cout << index+1 << endl;
       animaldisplaydata(&zoo.at(index));
       cout << endl;
    }


    // defining a map of cows
    map<string, cow> CowsMap;
    CowsMap["Default Cow"] = defCow;
    CowsMap["Cow1"] = myCow1;
    CowsMap["Cow2"] = myCow2;
    
    
    // defining a map of birds
    map<string, bird> BirdsMap;
    BirdsMap["Default Bird"] = defBird;
    BirdsMap["Crow"] = crow;
    BirdsMap["Eagle"] = eagle;
    BirdsMap["Rooster"] = rooster;    
    
    
    
    
    cout << "\n***********************************" << endl;
    cout << "*** Testing displaydata() for cow " << endl;
    cout << "*** using a defined Map " << endl;
    cout << "***********************************" << endl;
    cout << "The size of Cowsmap is " << CowsMap.size() << endl; 
    
    cout << "\nKey: " << "\"Default Cow\"" ;
    CowsMap.at("Default Cow").displaydata();
    cout << "\nKey: " << "\"Cow1\"" ;
    CowsMap.at("Cow1").displaydata();
    cout << "\nKey: " << "\"Cow2\"" ;
    CowsMap.at("Cow2").displaydata();
    cout << endl;

 
    cout << "\n***********************************" << endl;
    cout << "*** Testing displaydata() for bird " << endl;
    cout << "*** using a defined Map " << endl;
    cout << "***********************************" << endl;
    cout << "The size of Birdsmap is " << BirdsMap.size() << endl; 
    
    cout << "\nKey: " << "\"Default Bird\"";
    BirdsMap.at("Default Bird").displaydata();
    
    cout << "\nKey: " << "\"Crow\"";
    BirdsMap.at("Crow").displaydata();
    
    cout << "\nKey: " << "\"Eagle\"";
    BirdsMap.at("Eagle").displaydata();
    
    cout << "\nKey: " << "\"Rooster\"";
    BirdsMap.at("Rooster").displaydata();

    cout << endl;
    
    return 0;

}  // the end of main function

/*****************************************************************
//
//  Function name:		animaldisplaydata  
//
//  DESCRIPTION:		a function which calls displaydata() method from the animal class 
//				if any "bird" or "cow" object are passed to this function
//				then the animal method would be called
//				
//  Parameters:			input (animal *): a pointer of the animal type (e.g. cows and birds are animals as well)
//				
//  Return values:		void (no output)
//
//****************************************************************/

void animaldisplaydata(animal * a)
{

  a->displaydata();
  
}

//****************************************************************/

