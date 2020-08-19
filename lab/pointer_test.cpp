#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>



int main(void)
{
  

  int *pr, a[10];
  char address[10];
  
  cout << "Hello World" << endl ;
  cout << "This is my first vi program" << endl; 
  a[1] = 4;
  
  pr = a;
  
  *pr = a[1];
  
  
  cout << *pr << endl;

  
  std::cin.getline(address, 10, '$');
  
  cout << address << endl;




return 0;
}
