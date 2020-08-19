/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		7
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		November 24, 2013           
//
//  FILE:		program2.c        
//
//  DESCRIPTION:	This file contains the driver for "costofpainting" function
//			It prints out the road length for which the painting price dramatically changes
//
//****************************************************************/

#include <iostream>
using namespace std;
#include <iomanip>      // std::setprecision
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int  costofpainting(double length);


int main(void)
{
  
  double distance;
  int newcost, oldcost = 0;
  int i = 1, j = 0;
  
	cout << "\n\n";
	cout << "     Testing Driver for \"costofpainting\" function\n";
	
	cout << "\n";
	cout << "    ***********************************************\n";
	cout << "     Road Length (Mile)\t\tCost of Painting ($)\n";
	cout << "    ***********************************************\n";
	
	distance = 0.0;
	newcost = costofpainting(distance);
	cout << setw(15) << setprecision(2) << fixed << distance << setw(25)  << newcost << "\n" ;
	
	do
	{  
	   distance = j * 0.01;
	   newcost = costofpainting(distance);
	   
	   if (oldcost < newcost)
	   {
	       cout << setw(15) << setprecision(2) << fixed << distance << setw(25)  << newcost << "\n" ;
	       oldcost = newcost;
	       i++;
	   }
	  j++;
	} while(i <= 10);
	
	cout << "    ***********************************************\n\n";

  
  
}





  
